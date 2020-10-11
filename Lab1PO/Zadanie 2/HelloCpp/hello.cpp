#include <iostream>
#include <string>

int main() {
    std::string fellow = "world";
    while (fellow != "exit") {
        std::cout << "Hello " << fellow << std::endl;
        std::cout << "Introduce yourself: ";
        std::cout.flush();
        std::getline(std::cin, fellow);
    }
}

/* 
10. Debugowanie kodu pozwala na przechodzenie przez program linia po linii oraz sprawdzanie aktualnego stanu zmiennych co jest niezmiernie pomocne gdy skomplikowany 
program zawierający wiele funkcji oraz pętli nie zachowuje się jak powinien. Umożliwia ono także sprawdzanie bez manualnego szukania deklaracji klas i funkcji używanych 
w aktualnym momencie. W tak prostym programie jednak nie jesteśmy w stanie zobaczyć wszystkich tych możliwości w pełnej efektywności (nie ratuje życia lecz co najwyżej 
potencjalnie je ułatwia).
*/