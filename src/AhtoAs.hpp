#ifndef __AHTOAS__
#define __AHTOAS__

#include <iostream>
#include <iomanip>

#include "includes.hpp"
#include "IRCode.hpp"
#include "Parser.hpp"
#include "GenOptions.hpp"

void usage(const char * const cmdline);
void help(const char * const cmdline);

void parse_options(const int argc, const char * const argv[], const std::shared_ptr<GenOptions> options);

#endif