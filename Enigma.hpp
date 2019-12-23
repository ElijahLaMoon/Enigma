#ifndef ENIGMA_HPP
#define ENIGMA_HPP

class Enigma
{
public:
    std::string ringSettings[3];
    bool defaultSettings();
    bool duplicateCheck(int, int, int);
    bool setRingSettings(std::string&);
    int start();
};

#endif
