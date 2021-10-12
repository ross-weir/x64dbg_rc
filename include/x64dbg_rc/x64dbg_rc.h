#ifndef X64DBG_RC_X64DBG_RC_H
#define X64DBG_RC_X64DBG_RC_H

#include <stdint.h>

#define RC_COPYDATA 0x1338
#define RC_X64DBG_WIN_NAME "x64dbg"
#define RC_X64DBG_WIN_CLASS "Qt5QWindowIcon"

typedef enum
{
    RC_ATTACH_CMD,
    RC_EVAL_CMD
} RCCMDTYPE;

// COPYDATA structures can't contain pointers. The first field should contain the type which we can then use to cast
// the data to the correct struct.

typedef struct
{
    RCCMDTYPE type;
} RCMSG;

typedef struct
{
    RCCMDTYPE type;
    uint32_t pid;
} RC_ATTACH_DATA;

typedef struct
{
    RCCMDTYPE type;
    char command[512];
} RC_EVAL_DATA;

#endif //X64DBG_RC_X64DBG_RC_H
