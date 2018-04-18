#include "Parser.hpp"


Parser::Parser(const std::tr1::shared_ptr<GenOptions> opt)
    : opt(opt), ir(new IRCode()){
}

Parser::~Parser(){
}

const void Parser::change_gen_options(const std::tr1::shared_ptr<GenOptions> opt){
    
}

const void Parser::start_parse(){

}

const std::tr1::shared_ptr<IRCode> Parser::get_ir_code(){
    return this->ir;
}