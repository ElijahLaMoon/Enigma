#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <map>
#include <string>

class Plugboard
{
private:    
    std::map<char, char> plugboard;
    std::string plugboardCopy;

public:
    bool plugboardDuplicateCheck();
    bool lengthCheck();
    bool correctInputCheck();
    bool setPlugboard();
    void substitute(char &);
};

#endif
