#include <Windows.h>
#include <iostream>
#include "x64dbg_rc/x64dbg_rc.h"

int main()
{
    HWND x64dbg_win = FindWindowA(RC_X64DBG_WIN_CLASS, RC_X64DBG_WIN_NAME);

    if (x64dbg_win == NULL) {
        std::cout << "Make sure x64dbg is running\n";

        return 0;
    }

    const RC_EVAL_DATA msg = { RC_EVAL_CMD, "log hello!" };
    const COPYDATASTRUCT cds = { RC_COPYDATA, sizeof(RC_EVAL_DATA), (void*)&msg };

    SendMessage(x64dbg_win, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);

    std::cout << "Check log window in x64dbg\n";
    std::cout << "Done\n";
}