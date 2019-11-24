#ifndef ROTOR_HPP
#define ROTOR_HPP

class Rotor
{
private:
    /* data */
public:
    
    char rotorIndex;
    char rotorPosition[26];
    Rotor() {
        for (int i = 0; i < sizeof(rotorPosition); i++) {
            short temp = 65;
            rotorPosition[i] = temp;
            temp++;
        }
    };

    ~Rotor();
};

#endif