# x64dbg Remote Control

A plugin that enables [`x64dbg`](https://github.com/x64dbg/x64dbg) to be controlled remotely.

Currently, `attach` and `eval` commands are supported.

`eval` allows the execution of arbitrary `x64dbg` commands, so technically all commands that can
be triggered by `DbgCmdExecDirect` are supported. The idea behind having concrete commands like `attach` is so external tools can be debugger agnostic.

See `example/main.cpp` for example usage.

## Credits

The authors of `x64dbg` <3