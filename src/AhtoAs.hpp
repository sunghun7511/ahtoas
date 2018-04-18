#ifndef __AHTOAS__
#define __AHTOAS__

#include "includes.hpp"
#include "IRCode.hpp"
#include "Parser.hpp"
#include "GenOptions.hpp"
#include "CodeGeneration.hpp"

const void usage(const char * const cmdline);
const void help(const char * const cmdline);

const void parse_options(const int argc, const char * const argv[], const std::tr1::shared_ptr<GenOptions> options);

#endif