#ifndef __CODE_GENERATION__
#define __CODE_GENERATION__

#include "includes.hpp"
#include "IRCode.hpp"

class CodeGenerator {
private:
    const std::tr1::shared_ptr<IRCode> ir;
public:
    CodeGenerator(const std::tr1::shared_ptr<IRCode> ir);
    ~CodeGenerator();

    const void generate_code(const std::ostream& output);
private:
    // private methods
};

#endif