#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

template<typename T>
void secureInput(T & variable){
    while (!(std::cin >> variable)){
        std::cout << "Entrée invalide. Recommence." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
template<typename T, typename Predicate>
void secureInput(T & variable, Predicate predicate){
    while (!(std::cin >> variable) || !predicate(variable) ){
        std::cout << "Entrée invalide. Recommence." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void askInformations(std::string& name, std::string& lastname, std::string& gender, int& age){
    std::cout << "NOM ?" << std::endl;
    secureInput(name);

    std::cout << "PRENOM ?" << std::endl;
    secureInput(lastname);

    std::cout << "SEXE ?" << std::endl;
    secureInput(gender);
    std::cout << "AGE ?" << std::endl;
    secureInput(age, [](int a){return a >=0;});
}

std::string registerInformations(std::string const name, std::string const lastname, std::string const gender, int const age){
    std::string fileName { name +"."+lastname+".csv"};
    std::ofstream file {fileName};
    file << name <<", "<< lastname << ", " << gender << ", " << age;
    return fileName;
}

int main(){

    std::string name {""};
    std::string lastname {""};
    std::string gender {""};
    int age { 0 };

    askInformations(name, lastname, gender, age);
    auto fileName = registerInformations(name, lastname, gender, age);

    std::cout << "Those info will be saved in the file " << fileName << std::endl;

    return 0;

}