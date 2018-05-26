#ifndef __GEN_OPTIONS__
#define __GEN_OPTIONS__

#include "includes.hpp"

class GenOptions {
private:
    bool debug_mode;

    bool input_from_file;
    const string* input_file;
    
    bool out_to_file;
    const string* output_file;

    bool use_source;
    const string* source;
public:
    GenOptions();
    ~GenOptions();

    const void set_debug_mode(const bool flag);

    const void set_input_file(const string& input_file);
    const void set_output_file(const string& output_file);

    const void set_source(const string& source);

    const bool is_debug_mode();
    
    const bool has_input_file();
    const string* const get_input_file();

    const bool is_out_to_file();
    const string* const get_output_file();

    const bool has_source();
    const string* const get_source();
};

#endif