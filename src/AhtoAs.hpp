#ifndef __AHTOAS__
#define __AHTOAS__

#include "includes.hpp"
#include "IRCode.hpp"
#include "Parser.hpp"
#include "GenOptions.hpp"
#include "CodeGeneration.hpp"

const void usage(const string& cmdline);
const void help(const string& cmdline);

const void parse_options(const vector<string>& args, GenOptions& options);

#endif