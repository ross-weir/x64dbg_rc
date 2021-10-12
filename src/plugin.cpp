#include "plugin.h"
#include <sstream>
#include "x64dbg_rc/x64dbg_rc.h"

void on_winevent(CBTYPE cbType, PLUG_CB_WINEVENT* info)
{
    if (info->message->message != WM_COPYDATA) {
        return;
    }

    const auto copydata = reinterpret_cast<COPYDATASTRUCT*>(info->message->lParam);

    if (!copydata || copydata->dwData != RC_COPYDATA) {
        return;
    }

    const auto msg = (RCMSG*)copydata->lpData;
    std::ostringstream cmd;

    switch(msg->type) {
        case RC_ATTACH_CMD: {
            const auto data = reinterpret_cast<RC_ATTACH_DATA*>(msg);
            cmd << "attach ." << std::dec << data->pid;

            break;
        }
        case RC_EVAL_CMD: {
            const auto data = reinterpret_cast<RC_EVAL_DATA*>(msg);
            cmd << data->command;

            break;
        }
    }

    const auto cmd_str = cmd.str();

    if (!cmd_str.empty()) {
        dprintf("executing: %s\n", cmd_str.c_str());
        DbgCmdExecDirect(cmd_str.c_str());
    }
}

bool pluginInit(PLUG_INITSTRUCT* initStruct)
{
    _plugin_registercallback(initStruct->pluginHandle, CB_WINEVENT, reinterpret_cast<CBPLUGIN>(on_winevent));

    return true;
}

void pluginStop()
{
}

void pluginSetup()
{
}
