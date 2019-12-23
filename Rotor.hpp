#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

class Rotor
{
public:
    std::string rotor;
    char ring;
    void setRotor(char);
    void substitute(std::string&, char);
    void offset(std::string&);
    void ringApply(char, std::string&);

private:
    // TODO turn m_rotors to either std::array<...> or constexpr static?
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
