#include "GenOptions.hpp"

GenOptions::GenOptions()
    : debug_mode(false), 
    input_from_file(false),
    out_to_file(false),
    use_source(false),
    source(),
    output_file(),
    input_file(){
}

GenOptions::~GenOptions(){
}

const void GenOptions::set_debug_mode(const bool flag){
    this->debug_mode = flag;
}
const void GenOptions::set_input_file(const string& input_file){
    if(!input_file.empty()){
        this->input_from_file = true;
    }
    this->input_file = &input_file;
}
const void GenOptions::set_output_file(const string& output_file){
    if(!output_file.empty()){
        this->out_to_file = true;
    }
    this->output_file = &output_file;
}

const void GenOptions::set_source(const string& source){
    if(!source.empty()){
        this->use_source = true;
    }
    this->source = &source;
}

const bool GenOptions::is_debug_mode(){
    return this->debug_mode;
}

const bool GenOptions::has_input_file(){
    return this->input_from_file;
}

const string* const GenOptions::get_input_file(){
    return this->input_from_file ? this->input_file : new string();
}

const bool GenOptions::is_out_to_file(){
    return this->out_to_file;
}

const string* const GenOptions::get_output_file(){
    return this->out_to_file ? this->output_file : new string();
}

const bool GenOptions::has_source(){
    return this->use_source;
}

const string* const GenOptions::get_source(){
    return this->use_source ? this->source : new string();
}