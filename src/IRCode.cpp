#include "IRCode.hpp"

IRCode::IRCode()
    : queue(new std::queue<CodeType>()){
    
}

IRCode::~IRCode(){
}


const bool IRCode::has_code(){
    return !this->queue->empty();
}

const CodeType IRCode::pop_first_code(){
    CodeType type = this->queue->front();
    this->queue->pop();
    return type;
}

const CodeType IRCode::get_first_code(){
    return this->queue->front();
}

const void IRCode::push_code(const CodeType type){
    this->queue->push(type);
}

const void print_ir(const std::tr1::shared_ptr<IRCode> ir){
    
}