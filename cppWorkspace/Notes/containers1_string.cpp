#include <iostream>
#include <vector>

/*
    Containers: String
*/

class eString : public std::string {        // Have basic features + add new implemented by me
public:
    using std::string::string;      // Forward Constructors

    /*
        Add Extra Functionalities ....
    */
    bool eString_startsWith(std::string prefix) {
        bool retResult = false;
        if( this->find(prefix) == 0) {
            retResult = true;
        }
        return retResult;
    }
};

int main() {
    
    /* 
        Mutliple Constructor definition available 
    */
    std::string str1= "Ahmed Montasser";                  // const pointer to char
    std::string str2("Montasser");              // Copy Constructor
    std::cout<< str1 << str2 << std::endl;

    std::string str3(std::move(str1));          // Move Constructor
    std::string str4(10, 'X');                  // Fill Constructor
    std::cout<< str3 << str4 << std::endl;

    std::string str5(str1.begin(), str1.end()); // Range Constructor
    std::string str6(str2, 4, 5);               // Substring Constructor
    std::cout<< str5 << str6 << std::endl;

    std::vector<char> vectChar {'A', 'B', 'C', 'D'};
    std::string str7(vectChar.begin(), vectChar.end());     // Range Constructor
    std::string str8 = {'X', 'Y', 'Z', '/'};                // Initailizer List Constructor
    std::cout<< str7 << str8 << std::endl;

    /* 
        String Functions
    */
    std::cout<< str2.size() << std::endl;
    std::cout<< str2.length() << std::endl;
    std::cout<< str2.capacity() << std::endl;
    std::cout<< str2.max_size() << std::endl;

    str3 = "";
    str3.clear();

    if (str1.empty() == true) {         // Check if empty
        std::cout<< "Filling the String: "<< std::endl;
        str1 = "Ahmed Montasser";
    }
    std::cout<< str1 << std::endl;

    auto it = str1.find("Ahmed");
    if (it == std::string::npos) {
        std::cout<< "Not Found" << std::endl;
    }
    else {
        std::cout<< it << std::endl;
    }

    str1.replace(6, 9, "C++");
    std::cout<< str1 << std::endl;

    str1.erase(0, 5);
    std::cout<< str1 << std::endl;

    str1.insert(0, "Hello");
    std::cout<< str1 << std::endl;

    str1.append(" World");
    str1+="!";
    std::cout<< str1 << std::endl;

    str1[0]= 'h';
    std::cout<< str1 << std::endl;

    str1.at(0)= 'H';
    std::cout<< str1 << std::endl;

    const char* ptrString = str1.c_str();   // Return the Point Address of String

    for(int i=0; i<str1.length(); i++) 
        std::cout<< *(ptrString+i);
    std::cout<< std::endl;

    str1.resize(9, 'C');
    std::cout<< str1 << std::endl;

    str1.assign("This new assigned string");
    std::cout<< str1 << std::endl;

    /*
        Raw String
        Inject another code in string Format
    */

    std::string htmlRawString = R"...(
        <!DOCTYPE html>
        <html>
        <body>

        <h1>My First Heading</h1>

        <p>My first paragraph.</p>

        </body>
        </html>
    )...";
    std::cout<< htmlRawString << std::endl;


    /*
        Adding String Extra Feature ...  Inherit Std::string
    */
    eString eStrVar = "AhmedMontasser";
    std::cout<< eStrVar << std::endl;

    std::cout << std::boolalpha << eStrVar.eString_startsWith("Ahm") << std::endl;
    
    return 0;
}
