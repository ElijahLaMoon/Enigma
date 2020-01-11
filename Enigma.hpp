#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include <array>
#include <string>
#include "Reflector.hpp"
#include "Rotor.hpp"

class Enigma
{
public:
    std::string ringSettings[3];
    bool defaultSettings();
    bool duplicateCheck(std::array<int, 3> &);
    bool correctInput(int);
    bool setRingSettings(std::string &);
    void wholeCycle(std::array<Rotor, 3> &, Reflector &, char &, int &);
    int start();
};

#endif
