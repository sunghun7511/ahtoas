#ifndef __PARSER__
#define __PARSER__

#include "includes.hpp"
#include "IRCode.hpp"

class Parser {
private:
    GenOptions* opt;
    ptr<IRCode> ir;
public:
    Parser(GenOptions* const opt);
    ~Parser();

    const void change_gen_options(GenOptions* const opt);

    const void start_parse();
    const ptr<IRCode> get_ir_code();
private:
    // private methods.
};

#endif