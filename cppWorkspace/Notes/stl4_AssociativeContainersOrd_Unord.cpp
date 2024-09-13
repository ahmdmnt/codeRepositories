#include <iostream>
#include <map>
#include <set>

/*
    MAP

*/

void print(std::map<std::string, std::string>& l_map);

int main() {

    /*
        MAP
    */
    std::map<std::string, std::string> dB = {
        {"Name", "Ahmed"},
        {"Job", "SW Engineer"}
    };                                              // By Definition

    dB.insert(std::make_pair("Age", "31"));         // insert make pair
    dB.emplace("Salary", "1000");                   // Emplace
    dB.insert({"Martial Status", "Married"});       // Temp Pair ... to be inserted
    dB["Address"] = "Cairo";                        // Assigning new Key

    std::cout<< "Name: " << dB["Name"] << std::endl;
    std::cout<< "Job: " << dB["Job"] << std::endl;
    std::cout<< "Age: " << dB["Age"] << std::endl;
    print(dB);

    std::cout << dB.size() << std::endl;
    std::cout << dB.empty() << std::endl;
    
    auto it = dB.find("Name");
    if( it != dB.end() ) {
        std::cout<< "Found --   Value: " << it->second << std::endl;
    }

    dB.erase("Address");
    print(dB);

    return 0;
}

void print(std::map<std::string, std::string>& l_map) {
    
    for(auto it: l_map) {
        std::cout << it.first << ": " << it.second << std::endl;
    }
    // for(std::map<std::string, std::string>::iterator it = l_map.begin(); it!=l_map.end(); ++it) {
    //     std::cout << it->first << ": " << it->second << std::endl;
    // }
    // std::cout << std::endl;
}