#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>

class Message{
private:
    std::string msg;
    int priority;
public:
    Message();
    ~Message();
    std::string get_msg();
    void set_msg(std::string _msg);
    void set_pri(int prior);
    int get_pri();

};






#endif
