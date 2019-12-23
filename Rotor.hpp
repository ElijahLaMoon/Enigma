#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

class Rotor
{
public:
    std::string rotor;
    char ring;
    void setRotor(char);
    void substitute(std::string&);
    void offset(std::string&);

private:
    const std::string m_rotors[5] =
    {
    //  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ", //rotor I
        "AJDKSIRUXBLHWTMCQGZNPYFVOE", //rotor II
        "BDFHJLCPRTXVZNYEIWGAKMUSQO", //rotor III
        "ESOVPZJAYQUIRHXLNFTGKDCMWB", //rotor IV
        "VZBRGITYUPSDNHLXAWMJQOFECK"  //rotor V
    };

    std::string m_plugboard[6]
    {
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
    };

};

#endif
