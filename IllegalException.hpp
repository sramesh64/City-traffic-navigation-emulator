#include <exception>
#include <iostream>
class illegal_exception : public std::exception{
    public:
    std::string what(){
        return "illegal argument\n";
    }

};