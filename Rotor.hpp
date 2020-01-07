#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

class Rotor
{
public:
    std::string alphabet =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string iAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ring;
    void setRotor(int);
    void substitute(char &, char);
    void offset();
    void ringApply(char);

private:
    std::string rotor;
    std::string inverseRotor;
    // TODO turn rotors to either std::array<...> or constexpr static?
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
    //  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "UWYGADFPVZBECKMTHXSLRINQOJ",
        "AJPCZWRLFBDKOTYUQGENHXMIVS",
        "TAGBPCSDQEUFVNZHYIXJWLRKOM",
        "HZWVARTNLGUPXQCEJMBSKDYOIF",
        "QCYLXWENFTZOSMVJUDKGIARPHB"
    };

    // TODO plugboard should be totaly separated and try to make it in pairs(?)
    std::string plugboard[10]
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
