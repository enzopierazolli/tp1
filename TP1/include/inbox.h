#ifndef INBOX_H
#define INBOX_H

#include "message.h"
#include <iostream>

struct Node{
    Message mensagem;
    Node* next;
};

class Inbox_user{
private:
    Node *head = nullptr;
    Node *aux = nullptr;
    int id;

public:
    Inbox_user();
    ~Inbox_user();
    void add_msg(std::string msg, int priority);
    void consulta_msg();
    void set_id(int id);
    int get_id();


};







#endif
