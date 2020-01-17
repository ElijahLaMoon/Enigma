#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <array>
#include <string>
#include <string_view>

constexpr std::array<std::string_view, 5> rotors =
{
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ", //rotor I
    "AJDKSIRUXBLHWTMCQGZNPYFVOE", //rotor II
    "BDFHJLCPRTXVZNYEIWGAKMUSQO", //rotor III
    "ESOVPZJAYQUIRHXLNFTGKDCMWB", //rotor IV
    "VZBRGITYUPSDNHLXAWMJQOFECK"  //rotor V
};

constexpr std::array<std::string_view, 5> inverseRotors =
{
//  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "UWYGADFPVZBECKMTHXSLRINQOJ",
    "AJPCZWRLFBDKOTYUQGENHXMIVS",
    "TAGBPCSDQEUFVNZHYIXJWLRKOM",
    "HZWVARTNLGUPXQCEJMBSKDYOIF",
    "QCYLXWENFTZOSMVJUDKGIARPHB"
};

class Rotor
{
private:
    std::string rotor;
    std::string inverseRotor;

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
