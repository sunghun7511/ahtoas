#include "IRCode.hpp"

IRCode::IRCode()
    : irs(new queue<CodeType>()){
    
}

IRCode::~IRCode(){
}


const bool IRCode::has_code(){
    return !this->irs->empty();
}

const CodeType IRCode::pop_first_code(){
    CodeType type = this->irs->front();
    this->irs->pop();
    return type;
}

const CodeType IRCode::get_first_code(){
    return this->irs->front();
}

const void IRCode::push_code(const CodeType type){
    this->irs->push(type);
}

const void print_ir(const ptr<IRCode> ir){
    
}