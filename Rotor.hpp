#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <string>

class Rotor
{
private:
    std::string rotor;
    std::string inverseRotor;

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

public:
    std::string alphabet =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string iAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ring;
    void setRotor(int);
    void substitute(char &, char);
    void offset();
    void ringApply(char);
};

#endif
