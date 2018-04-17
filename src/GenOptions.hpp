#ifndef __GEN_OPTIONS__
#define __GEN_OPTIONS__

#include <string>

class GenOptions {
private:
    bool debug_mode;

    bool input_from_file;
    std::string input_file;
    
    bool out_to_file;
    std::string output_file;

    std::string source;
public:
    GenOptions();
    ~GenOptions();

    void set_debug_mode(const bool flag);

    void set_input_file(const std::string input_file);
    void set_output_file(const std::string output_file);

    void set_source(const std::string source);

    const bool is_debug_mode();
    
    const bool has_input_file();
    const std::string get_input_file();

    const bool is_out_to_file();
    const std::string get_output_file();

    const std::string get_source();
};

#endif