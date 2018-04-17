#include "GenOptions.hpp"

// bool debug_mode;

// bool input_from_file;
// std::string input_file;

// bool do_output_to_file;
// std::string output_file;

// std::string source;

GenOptions::GenOptions()
    : debug_mode(false), 
    input_from_file(false),
    input_file(nullptr),
    out_to_file(false),
    output_file(nullptr),
    source(nullptr){
}
GenOptions::~GenOptions(){
}

void GenOptions::set_debug_mode(const bool flag){
    this->debug_mode = flag;
}
void GenOptions::set_input_file(const std::string input_file){
    this->input_from_file = true;
    this->input_file = input_file;
}
void GenOptions::set_output_file(const std::string output_file){
    this->out_to_file = true;
    this->output_file = output_file;
}

void GenOptions::set_source(const std::string source){
    this->source = source;
}

const bool GenOptions::is_debug_mode(){
    return this->debug_mode;
}

const bool GenOptions::has_input_file(){
    return this->input_from_file;
}

const std::string GenOptions::get_input_file(){
    return this->input_file;
}

const bool GenOptions::is_out_to_file(){
    return this->out_to_file;
}

const std::string GenOptions::get_output_file(){
    return this->output_file;
}

const std::string GenOptions::get_source(){
    return this->get_source;
}