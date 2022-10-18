#include <iostream>
#include <iomanip>
#include <fstream>
#include "inbox.h"
#include "user.h"

int main(int argc, char* argv[]) {
    Users usuarios;
    int id, priority;
    std::string entrada, msg;
    std::ifstream infile;
    
    infile.open("test.txt");
    if (!infile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while(infile >> entrada){

        if(entrada == "CONSULTA"){
            infile >> id;
            usuarios.consulta(id);
        }
        if(entrada == "CADASTRA"){
            infile >> id;
            usuarios.cadastro_user(id);
        }
        if(entrada == "ENTREGA"){
            infile >> id >> priority >> entrada;

            while(entrada != "FIM"){
                msg += entrada + " ";
                infile >> entrada;
            }
            usuarios.entrega(id, msg, priority);
            msg = "";
        }
    }

    infile.close();

    
    return 0;
}