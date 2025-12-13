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

struct personalData{
    std::string name;
    std::string lastname;
    std::string gender;
    int age;
};

personalData askInformations(){
    personalData data {};
    std::cout << "NOM ?" << std::endl;
    secureInput(data.name);

    std::cout << "PRENOM ?" << std::endl;
    secureInput(data.lastname);

    std::cout << "SEXE ?" << std::endl;
    secureInput(data.gender);
    std::cout << "AGE ?" << std::endl;
    secureInput(data.age, [](int a){return a >=0;});
    return data;
}

std::string registerInformations( personalData const & data){
    std::string fileName { data.name +"."+data.lastname+".csv"};
    std::ofstream file {fileName};
    file << data.name <<", "<< data.lastname << ", " << data.gender << ", " << data.age;
    return fileName;
}

int main(){

    auto yourData = askInformations();
    auto fileName = registerInformations(yourData);

    std::cout << "Those info will be saved in the file " << fileName << std::endl;

    return 0;

}