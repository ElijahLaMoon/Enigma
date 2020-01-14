#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <string>

class Reflector
{
private:
    std::string reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

public:
    std::string alphabet =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    void reflectorSubstitute(char &);
};

#endif
