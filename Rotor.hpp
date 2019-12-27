#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

class Rotor
{
public:
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ring;
    void setRotor(int);
    void substitute(char &, char, int &, char);
    void offset();
    void ringApply(char);

private:
    std::string rotor;
    std::string inverseRotor;
    // TODO turn m_rotors to either std::array<...> or constexpr static?
    const std::string rotors[5] =
    {
    //  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "EKMFLGDQVZNTOWYHXUSPAIBRCJ", //rotor I
        "AJDKSIRUXBLHWTMCQGZNPYFVOE", //rotor II
        "BDFHJLCPRTXVZNYEIWGAKMUSQO", //rotor III
        "ESOVPZJAYQUIRHXLNFTGKDCMWB", //rotor IV
        "VZBRGITYUPSDNHLXAWMJQOFECK"  //rotor V
    };

    const std::string inverseRotors[5] =
    {
        "UWYGADFPVZBECKMTHXSLRINQOJ",
        "AJPCZWRLFBDKOTYUQGENHXMIVS",
        "TAGBPCSDQEUFVNZHYIXJWLRKOM",
        "HZWVARTNLGUPXQCEJMBSKDYOIF",
        "QCYLXWENFTZOSMVJUDKGIARPHB"
    };

    std::string m_plugboard[10]
    {
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0",
        "\0\0"
    };

};

#endif
