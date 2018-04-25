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
    
}

const ptr<IRCode> Parser::get_ir_code(){
    return this->ir;
}