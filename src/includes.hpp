#ifndef __INCLUDES__
#define __INCLUDES__

#include <cstdlib>
#include <cstring>

#include <iomanip>
#include <iostream>

#include <queue>

#include <tr1/memory>
#include <fstream>

void inline error_exit(const char *str){
    std::cerr << "\n" << str << "\n\n";
    std::exit(EXIT_FAILURE);
}

#endif