#include "user.h"

Users::Users(){

};

Users::~Users(){

};

void Users::cadastro_user(int _id){
    Nodes *new_user = new Nodes();
    auxiliar = nullptr;

    new_user->inbox.set_id(_id);
    new_user->next = nullptr;

    if(existe_id(_id) != 0){
        std::cout << "ERRO: CONTA " << _id <<" JA EXISTENTE" << std::endl;
    }
    else{
        if(head == nullptr)
            head = new_user;
        else{
            new_user->next = head;
            head = new_user;
        }
        std::cout << "OK: CONTA " << _id <<" CADASTRADA" << std::endl;
    }
}

void Users::remove_user(int id_remove){
    bool existe_id = false;
    
    auxiliar = nullptr;
    auxiliar2 = nullptr;

    if(head->inbox.get_id() == id_remove){
        auxiliar = head->next;
        delete head;
        head = auxiliar;
        existe_id = true;
    }
    else{
            auxiliar = head;
            while(auxiliar->next != nullptr){
                if(auxiliar->next->inbox.get_id() == id_remove){
                    auxiliar2 = auxiliar->next;
                    auxiliar->next = auxiliar->next->next;
                    delete auxiliar2;
                    existe_id = true;
                    std::cout << "OK: CONTA " << id_remove <<" REMOVIDA" << std::endl;
                    break;
                }
                auxiliar = auxiliar->next;
        }
    }
    if(existe_id == false){
        std::cout << "ERRO: CONTA " << id_remove <<" NAO EXISTE" << std::endl;
    }
    
}

void Users::consulta(int consulta_id){
    int existe = 0;
    existe = existe_id(consulta_id);
    if(existe != 0){
        if(head->inbox.get_id() == consulta_id){
            head->inbox.consulta_msg();
        }
        else{
            auxiliar = head;
                while(auxiliar->next != nullptr){
                        if(auxiliar->next->inbox.get_id() == consulta_id){
                            auxiliar->next->inbox.consulta_msg();
                            break;
                        }
                        auxiliar = auxiliar->next;
                    }
        }
    }
    else{
        std::cout << "ERRO: CONTA " << consulta_id <<" NAO EXISTE" << std::endl;
    }

}

void Users::entrega(int entrega_id, std::string msg, int priority){
    int existe = 0;
    existe = existe_id(entrega_id);
    if(existe != 0){
        if(head->inbox.get_id() == entrega_id){
            head->inbox.add_msg(msg, priority);
        }
        else{
            auxiliar = head;
                while(auxiliar->next != nullptr){
                        if(auxiliar->next->inbox.get_id() == entrega_id){
                            auxiliar->next->inbox.add_msg(msg, priority);
                            break;
                        }
                        auxiliar = auxiliar->next;
                    }
        }
    }
    else{
        std::cout << "ERRO: CONTA " << entrega_id <<" NAO EXISTE" << std::endl;
    }
}

int Users::existe_id(int id){
    int contador = 0;
    if(head == nullptr){
        return 0;
    }
    else{
        if(head->inbox.get_id() == id){
            return 1;
        }
        contador++;
        auxiliar2 = head;
        while(auxiliar2->next != nullptr){
            contador++;
            if(auxiliar2->next->inbox.get_id() == id)
                return contador;
            if(auxiliar2->next == nullptr)
                return 0;
            auxiliar2 = auxiliar2->next;
        }
        return 0;
    }
}