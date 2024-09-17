#include <iostream>

template<typename T>
T multiplyFunction(T variable1, T variable2) {
    return variable1*variable2;
}

template<typename T, typename U>
auto multiplyFunction(T variable1, U variable2) -> decltype(variable1*variable2) {
    return variable1*variable2;
}

template<typename T>
T addFunction(T variable1, T variable2) {
    return variable1+variable2;
}

int main() {

    std::cout<< multiplyFunction(2, 2) << std::endl;
    std::cout<< multiplyFunction(2.5, 2.5) << std::endl;
    std::cout<< multiplyFunction(2.5, 2) << std::endl;

    std::string v1 = "Ahmed";
    std::string v2 = "Montasser";
    std::cout<< addFunction(v1, v2) << std::endl;

    return 0;
}