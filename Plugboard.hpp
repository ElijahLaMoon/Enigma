#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <array>
#include <map>
#include <string>
#include <tuple>

class Plugboard
{
private:    
    std::map<char, char> plugboard;
    std::string plugboardCopy;

public:
    bool plugboardDuplicateCheck(std::string &);
    bool lengthCheck(std::string &);
    bool setPlugboard();
};

#endif
