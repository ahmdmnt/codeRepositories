/*
* CLASS HEADER FILE: myString
*/


class custString {
   std::string strVariable;

public:
   custString(std::string l_str);
   void print(void);
   void append(void);
   void erase(void);
   void replace(void);
   custString& operator+=(const std::string& l_str);
   custString& operator+=(const custString& l_str);
   friend std::string operator+(const custString& strInstance, const std::string& l_str);
   friend std::ostream& operator<<(std::ostream& l_cout, const custString& strInstance);
};