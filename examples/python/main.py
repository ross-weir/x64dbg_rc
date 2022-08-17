from ctypes import (
    c_uint32,
    pointer,
    wintypes,
    cast,
    c_void_p,
    Structure,
    c_int32,
    c_char,
    sizeof,
    windll,
)
from enum import IntEnum


RC_COPYDATA = int("0x1338", 16)
WM_COPYDATA = int("0x004A", 16)


class CopyDataStruct(Structure):
    _fields_ = [
        ("dwData", wintypes.LPARAM),
        ("cbData", wintypes.DWORD),
        ("lpData", c_void_p),
    ]


class RcEvalData(Structure):
    _fields_ = [
        ("type", c_int32),
        ("command", c_char * 512),
    ]


class RcAttachData(Structure):
    _fields_ = [
        ("type", c_int32),
        ("pid", c_uint32),
    ]


class RcCmdType(IntEnum):
    Attach = 0
    Eval = 1


def main():
    window = windll.user32.FindWindowW("Qt5QWindowIcon", "x64dbg")

    if not window:
        print("Make sure x64dbg is running")
        return

    eval_cmd = RcEvalData(type=RcCmdType.Eval, command=b"log hello!")
    lp_data = cast(pointer(eval_cmd), c_void_p)
    msg = CopyDataStruct(
        dwData=RC_COPYDATA,
        cbData=sizeof(eval_cmd),
        lpData=lp_data,
    )

    windll.user32.SendMessageW(window, WM_COPYDATA, None, msg)
    print("Check log window in x64dbg")
    print("Done")


if __name__ == "__main__":
    main()
