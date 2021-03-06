#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <array>
#include <string>
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

class Enigma
{
public:
    std::string ringSettings[3];
    bool defaultSettings();
    bool duplicateCheck(std::array<int, 3>);
    int atoi(char);
    bool correctInput(int);
    bool setRingSettings(std::string &);
    void encipher(std::array<Rotor, 3> &, Reflector &, Plugboard &, char &, int &);
    int start();
};

#endif
