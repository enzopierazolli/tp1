#include <iostream>
#include <iomanip>
#include <fstream>


int main() {
    std::string entrada;
    std::ifstream inFile;
    
    inFile.open("test.txt");
    if (!inFile) {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> entrada) {
        if(a == "5")
            std::cout << " -TESTE- \n" ;
        else
        std::cout << a << std::endl;
    }
    
    inFile.close();
    return 0;
}