/*
    Algorithm and RAII: Resource Aquistion Initialization

    Libraries:
        1. Algorithm
        2. Numeric

    Basic template for functions/methods in Algorithm
        (beginPtr, endPtr, value/ptr/iterator/function)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> vectorVariable {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
    std::vector<int> vectorVariable_2 {10, 21, 30, 1, 4, 8, 11, 500, 2, 34, 48, 10, 10};

    std::cout<< std::boolalpha;

    /*
        all_of:
        All of elements must be (Function/LambdaExperssion implemented)
    */
    std::cout<< "All Elements > 10: " << std::all_of(vectorVariable.begin(), vectorVariable.end(), [](int i) {
        return i>10;
    }) << std::endl;

    /*
        any_of:
        Any of elements must be (Function/LambdaExperssion implemented)
    */
    std::cout<< "Any of Elements > 10: " << std::any_of(vectorVariable.begin(), vectorVariable.end(), [](int i) {
        return i>10;
    }) << std::endl;

    /*
        none_of:
        Any of elements must be (Function/LambdaExperssion implemented)
    */
    std::cout<< "None of Elements > 10: " << std::none_of(vectorVariable.begin(), vectorVariable.end(), [](int i) {
        return i>10;
    }) << std::endl;

    /*
        for_each:
        For each elements Perform (Function/LambdaExperssion implemented)
    */
    #define begin_end(vect)   std::begin(vect), std::end(vect)
    std::for_each(begin_end(vectorVariable), [](int i) {
        std::cout<< i*10 << " ";
    });
    std::cout<< std::endl;

    /*
        for_each_n:
        For each elements -till certain size- Perform (Function/LambdaExperssion implemented)
    */
    std::for_each_n(std::begin(vectorVariable), 3, [](int i) {
        std::cout<< i << " ";
    });
    std::cout<< std::endl;

    /*
        count:
        Count existence of an element
    */
    std::cout<< "Count 10 = " << std::count(vectorVariable.begin(), vectorVariable.end(), 10) << std::endl;

    /*
        count_if:
        Count if elements is according (Function/LambdaExperssion implemented)
    */
    std::cout<< "Count Elements > 10: " << std::count_if(vectorVariable.begin(), vectorVariable.end(), [](int i) {
        return i>10;
    }) << std::endl;


    /*
        mismatch:
        get the Mismatch between two containers
        auto pVar = ..
            - vectorVariable   {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
            - vectorVariable_2 {10, 21, 30, 1, 4, 8, 11, 500, 2, 34, 48, 10, 10};
    */
    std::pair pVar_1 = std::mismatch(vectorVariable.begin(), vectorVariable.end(), vectorVariable_2.begin(), vectorVariable_2.end());
    std::cout<< "Element Values that are (or Beginning) mismatch in 1st/2nd Conatiner: " << *pVar_1.first << "-" << *pVar_1.second << std::endl;

    std::pair pVar_2 = std::mismatch(vectorVariable.begin(), vectorVariable.end(), vectorVariable_2.begin(), vectorVariable_2.end(), [](int i, int j) {
        // return i == j;    Default Expression in mismatch it can be changed to any implementation
        return i != j;      // mismatch occur if IS NOT equals --> (i) not-equal (j)
    });
    std::cout<< "Element Values that are (or Beginning) mismatch in 1st/2nd Conatiner: " << *pVar_2.first << "-" << *pVar_2.second << std::endl;


    /*
        find:
        get the iterator of a certain element.

        if the Algorithm function available specific as a method in your class ...
        better to use built-in method for your class... like find() for example.
    */
    auto iter = std::find(vectorVariable.begin(), vectorVariable.end(), 20);
    if(iter != vectorVariable.end()) {
        std::cout<< "Value (" << *iter <<") is found at index: " << iter-vectorVariable.begin() << std::endl;
        std::cout<< "Found at index: " << std::distance(vectorVariable.begin(), iter) << std::endl;
        std::cout<< "Value Address: " << iter.base() << std::endl;
    }

    /*
        find_if:
        get the iterator of a certain element.

        if the Algorithm function available specific as a method in your class ...
        better to use built-in method for your class... like find() for example.
    */
    iter = std::find_if(vectorVariable.begin(), vectorVariable.end(), [](int value) {
        return value >= 100;
    });
    if(iter != vectorVariable.end()) {
        std::cout<< "Value (>= 100) is found at index: " << iter-vectorVariable.begin() << std::endl;
    }

    /*
        find_first_of:
            - vectorVariable   {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
            - vectorVariable_2 {10, 21, 30, 1, 4, 8, 11, 500, 2, 34, 48, 10, 10};
    */
    iter = std::find_first_of(vectorVariable.begin(), vectorVariable.end(), vectorVariable_2.begin(), vectorVariable_2.end());
    if(iter != vectorVariable.end()) {
        std::cout<< "First Matching Value is found at index: " << iter-vectorVariable.begin() << std::endl;
    }

    /*
        adjacent_find:
            find first duplicate elements
            - vectorVariable   {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
    */
    iter = std::adjacent_find(vectorVariable.begin(), vectorVariable.end());
    if(iter != vectorVariable.end()) {
        std::cout<< "First Duplicate Values is found at index: " << iter-vectorVariable.begin() << std::endl;
    }

    
    /*
        search:
            find certain sequence of elmenets
            - vectorVariable       {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
            - sub_vectorVariable   {500, 2, 34, 48};
    */
    std::vector<int> sub_vectorVariable   {500, 2, 34, 48};
    std::cout<< "First Element at Sequence : " << *(std::search(begin_end(vectorVariable), begin_end(sub_vectorVariable))) << std::endl;
    std::cout<< "First Element at Sequence : " << (std::search(begin_end(vectorVariable), begin_end(sub_vectorVariable)))-vectorVariable.begin() << std::endl;
    
    /*
        lower_bound:
            Searches for the first element in the partitioned range
        copy:
        copy_if:
        copy_n:
        move:
        fill:
        fill_n:
        transform:
        generate:
        remove:
        remove_if:
    */
    std::transform(begin_end(vectorVariable), vectorVariable.begin(), [](int i) {
        return ++i;
    });
    std::for_each(begin_end(vectorVariable), [](int i) {std::cout<< i << " ";});std::cout<<std::endl;

    // If the Vector to be filled not same SIZE.
    // std::back_inserter(_) push_back ... save already available elements if not empty
    std::vector<int> vectorVariable_3 {1,2,3};
    std::transform(begin_end(vectorVariable), std::back_inserter(vectorVariable_3), [](int i) {
        return ++i;
    });
    std::for_each(begin_end(vectorVariable_3), [](int i) {std::cout<< i << " ";});std::cout<<std::endl;

    // Two Vectors Manuplates and fill another vector
    vectorVariable_3.clear();
    std::transform(begin_end(vectorVariable), vectorVariable_2.begin(), std::back_inserter(vectorVariable_3), // [](int a, int b) { return a+b; });
    std::plus<int>());          // using std <functional>

    std::for_each(begin_end(vectorVariable_3), [](int i) {std::cout<< i << " ";});std::cout<<std::endl;

    /* Create set from a vr ...*/
    std::set<int> setVariable1 {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
    std::for_each(setVariable1.begin(), setVariable1.end(), [](int i) {std::cout<< i << " ";});std::cout<<std::endl;
    std::set<int, std::greater<>> setVariable2 {10, 21, 30, 1, 4, 8, 20, 500, 2, 34, 48, 10, 10};
    std::for_each(setVariable2.begin(), setVariable2.end(), [](int i) {std::cout<< i << " ";});std::cout<<std::endl;


    // generate
    int val = 0;
    std::vector<int> vectorVariable_4(10);
    std::generate(begin_end(vectorVariable_4), [&val]() {
        return val++;
    });
    std::for_each(begin_end(vectorVariable_4), [](int i) {std::cout<< i << " ";});std::cout<<std::endl;


    return 0;
}
 