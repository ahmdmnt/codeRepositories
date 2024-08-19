/*
* CLASS HEADER FILE: myString
*/

class myString {
public:
    std::string message;

    // Class Methods
    void display ();
    myString& operator+=(const std::string& msg);
    bool operator<(const myString& dInstance);
};

std::string operator+(const myString& dInstance, const std::string& msg);
