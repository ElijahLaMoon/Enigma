#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <array>
#include <string>
#include "Rotor.hpp"

class Enigma
{
public:
    std::string ringSettings[3];
    bool defaultSettings();
    bool correctInput(int);
    bool duplicateCheck(std::array<int, 3>);
    bool setRingSettings(std::string &);
    void wholeCycle(std::array<Rotor, 3> &, char &);
    int start();
};

#endif
