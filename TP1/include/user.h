#ifndef USER_H
#define USER_H

#include "inbox.h"
#include <iostream>

struct Nodes{
    Inbox_user inbox;
    Nodes* next;
};

class Users{
private:
    
    Nodes* head = nullptr;
    Nodes* auxiliar = nullptr;
    Nodes* auxiliar2 = nullptr;

public:
    Users();
    ~Users();
    void consulta(int id);
    void entrega(int id, std::string msg, int priority);
    void cadastro_user(int id);
    void remove_user(int id);
    int existe_id(int id);
};





#endif  
