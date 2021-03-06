#ifndef __INCLUDES__
#define __INCLUDES__

#include <cstdlib>
#include <cstring>

#include <iomanip>
#include <iostream>

#include <string>

#include <queue>

#include <tr1/memory>
#include <fstream>

template <class T>
using ptr = std::shared_ptr<T>;

using std::string;

using std::vector;
using std::queue;

using std::cout;

using std::fstream;
using std::ifstream;
using std::ofstream;

void inline error_exit(const char *str){
    std::cerr << "\n[Error] " << str << "\n\n";
    std::exit(EXIT_FAILURE);
}

void inline error_exit(const string str){
    std::cerr << "\n[Error] " << str << "\n\n";
    std::exit(EXIT_FAILURE);
}

#endif