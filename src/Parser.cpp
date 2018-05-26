#include "Parser.hpp"

Parser::Parser(GenOptions* const opt)
    : opt(opt), ir(new IRCode()){
}

Parser::~Parser(){
}

const void Parser::change_gen_options(GenOptions* const opt){
    this->opt = opt;
}

const void Parser::start_parse(){
    string source, tmp;
    
    if(opt->has_input_file()){
        ifstream ifs(*opt->get_input_file());
        
        if(ifs.is_open()){
            getline(ifs, source);
            while(getline(ifs, tmp)){
                source += "\n" + tmp;
            }
            ifs.close();
        }else{
            error_exit("Cannot found file.. (" + *opt->get_input_file() + ")");
        }
    }else{
        source = *opt->get_source();
    }

    if(opt->is_debug_mode()){
        cout << "Source read complete.\n";
    }
    
}

const ptr<IRCode> Parser::get_ir_code(){
    return this->ir;
}