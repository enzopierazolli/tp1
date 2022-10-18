#include "inbox.h"

Inbox_user::Inbox_user(){

}

Inbox_user::~Inbox_user(){

}

void Inbox_user::add_msg(std::string msg, int priority){
    Node *new_msg = new Node();
    aux = nullptr;

    new_msg->mensagem.set_msg(msg);
    new_msg->mensagem.set_pri(priority);
    new_msg->next = nullptr;

    if(head == nullptr){
        head = new_msg;
    }

    else{
        aux = head;
        if(head->mensagem.get_pri() < priority){
            new_msg->next = head;
            head = new_msg;
        }
        else if(aux->next != nullptr){
            while(aux->next->mensagem.get_pri() >= priority){
                aux = aux->next;
                if(aux->next == nullptr)
                    break;
            }
            new_msg->next = aux->next;
            aux->next = new_msg;
        }
        else{
            head->next = new_msg;
        }

        std::cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << std::endl;
    }
}

void Inbox_user::consulta_msg(){
    if(head == nullptr){
        std::cout << "CONSULTA " << this->id << ": CAIXA DE ENTRADA VAZIA" << std::endl;
    }
    else{
        std::cout << "CONSULTA " << this->id << ":" << this->head->mensagem.get_msg() << std::endl;
        aux = head->next;
        delete head;
        head = aux;
        aux = nullptr;
    }

}

void Inbox_user::set_id(int _id){
    this->id = _id;
}

int Inbox_user::get_id(){
    return this->id;
}