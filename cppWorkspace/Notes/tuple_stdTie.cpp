#include <iostream>
#include <tuple>
#include <vector>

/*
    Tuple Datatype
*/

bool compareMultipleValues();

int main() {
    /*
        Can accept any type of variable with any count
    */
    std::tuple<int, float, std::string, std::vector<int>> tuVariable (
        1,
        2.4f,
        "Ahmed",
        {1, 2, 3, 4, 5, 6}
    );

    /* Access tuple by Index ... Error if accessing no available element */
    std::cout << "Index 0: " << std::get<0>(tuVariable) << std::endl;
    std::cout << "Index 1: " << std::get<1>(tuVariable) << std::endl;
    std::cout << "Index 2: " << std::get<2>(tuVariable) << std::endl;
    std::cout << "Index 2 - Element 0: " << std::get<2>(tuVariable)[0] << std::endl;
    for (auto i: std::get<3>(tuVariable)) {
        std::cout << "  - Element: " << i << std::endl;
    }
    std::cout << "Index 3 - Element 0: " << std::get<3>(tuVariable)[0] << std::endl;

    /* Get Tuple Size */
    std::cout<< "Tuple Size: " << std::tuple_size_v<decltype(tuVariable)> << std::endl;
    std::cout<< "Tuple Size: " << std::tuple_size<decltype(tuVariable)>::value << std::endl;

    /* Get Datatype of an Element */
    std::cout<< "Element 0 type: " << typeid(std::tuple_element_t<0, decltype(tuVariable)>).name() << std::endl;
    std::cout<< "Element 1 type: " << typeid(std::tuple_element<1, decltype(tuVariable)>::type).name() << std::endl;

    /* I Can create new Element using this fetched Datatype */
    std::tuple_element<2, decltype(tuVariable)>::type stringVariable = "Mohamed";
    std::cout<< "New Created String: " << stringVariable << std::endl;


    /*
    std::tie() - Compare Multiple Variables together
    */
    std::cout<< "Comapare Result: " << std::boolalpha << compareMultipleValues() << std::endl;

    return 0;
}


/*
    std::tie() - Compare Multiple Variables together
*/
bool compareMultipleValues() {
    std::string strVariable_1("Ahmed");
    std::string strVariable_2("Ahmed");
    int numVariable_1 {10};
    int numVariable_2 {10};

    return std::tie(strVariable_1, numVariable_1) == std::tie(strVariable_2, numVariable_2);
}
