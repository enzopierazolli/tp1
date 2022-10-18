#include "message.h"

Message::Message(){
}

Message::~Message(){

}

std::string Message::get_msg(){
    return msg;
}

int Message::get_pri(){
    return priority;
}

void Message::set_msg(std::string _msg){
    msg = _msg;
}

void Message::set_pri(int _prior){
    priority = _prior;
}

