#include "Rotor.hpp"

void rotorInitializer(Rotor rot) {
    for (int i = 0; i < sizeof(rot.rotorPosition); i++) {
        rot.rotorPosition[i] = (i + 1);
    }
};