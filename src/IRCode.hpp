#ifndef __IRCODE__
#define __IRCODE__

#include "includes.hpp"
#include "GenOptions.hpp"

class IRCode {
private:
    
public:

};

void parse(const std::shared_ptr<GenOptions> opt, const std::shared_ptr<IRCode> ir);
void print_ir(const std::shared_ptr<IRCode> ir);

#endif