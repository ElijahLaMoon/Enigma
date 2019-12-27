#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <string>

class Reflector
{
public:
    void reflectorSubstitute(char &);
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

private:
    std::string _reflector = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
};

#endif
