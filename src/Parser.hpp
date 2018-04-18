#ifndef __PARSER__
#define __PARSER__

#include "includes.hpp"
#include "IRCode.hpp"

class Parser {
private:
    std::tr1::shared_ptr<GenOptions> opt;
    std::tr1::shared_ptr<IRCode> ir;
public:
    Parser(const std::tr1::shared_ptr<GenOptions> opt);
    ~Parser();

    const void change_gen_options(const std::tr1::shared_ptr<GenOptions> opt);

    const void start_parse();
    const std::tr1::shared_ptr<IRCode> get_ir_code();
private:
    // private methods.
};

#endif