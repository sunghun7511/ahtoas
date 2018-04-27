#ifndef __IRCODE__
#define __IRCODE__

#include "includes.hpp"
#include "GenOptions.hpp"

enum CodeType{
    // basic instructions set
    NOP             = 0x000001,
    UNDEFINED       = 0x000001,
    EXIT            = 0x000002,

    // operator instructions set
    OP_ADD          = 0x000010,
    OP_SUB          = 0x000020,
    OP_MUL          = 0x000030,
    OP_DIV          = 0x000040,
    OP_MOD          = 0x000050,

    // memory manipulation instructions set
    MEM_PUSH        = 0x000100,
    MEM_POP         = 0x000200,
    MEM_RE_PUSH     = 0x000300,
    MEM_ALTERN      = 0x000400,

    // control instructions set
    CNT_SELECT      = 0x001000,
    CNT_MOVE        = 0x002000,
    CNT_COMPARE     = 0x003000,
    CNT_JNZ         = 0x004000,
    
    // cursor manipulation instructions set
    CUR_UP          = 0x010000,
    CUR_DOWN        = 0x020000,
    CUR_RIGHT       = 0x030000,
    CUR_LEFT        = 0x040000,
    CUR_UP_2        = 0x050000,
    CUR_DOWN_2      = 0x060000,
    CUR_RIGHT_2     = 0x070000,
    CUR_LEFT_2      = 0x080000,
    CUR_HOR_REV     = 0x090000,
    CUR_VER_REV     = 0x0a0000,
    CUR_REV         = 0x0b0000,
};

class IRCode {
private:
    ptr<queue<CodeType>> irs;
public:
    IRCode();
    ~IRCode();

    const void push_code(const CodeType type);
    const bool has_code();
    const CodeType pop_first_code();
    const CodeType get_first_code();
};

const void print_ir(const ptr<IRCode> ir);

#endif