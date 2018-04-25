#ifndef __IRCODE__
#define __IRCODE__

#include "includes.hpp"
#include "GenOptions.hpp"

enum CodeType{
    
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