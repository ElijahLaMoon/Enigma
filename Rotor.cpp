#include <algorithm>
#include <iostream>
#include "Rotor.hpp"

void Rotor::setRotor(int choice)
{
    --choice; //people count from 1, unlike machines
    rotor = rotors[choice];
    inverseRotor = inverseRotors[choice];
}

void Rotor::substitute(char &eachCharacter, char mode)
{
    switch (mode)
    {
    case 's':
        for (auto alphabetIterator = alphabet.begin(), rotorIterator = rotor.begin();
                alphabetIterator != alphabet.end();
                ++alphabetIterator, ++rotorIterator)
        {
            if (eachCharacter == *alphabetIterator)
            {
                eachCharacter = *rotorIterator;
                break;
            }
        }
        break;
    
    case 'r':
        for (auto alphabetIterator = iAlphabet.begin(), inverseRotorIterator = inverseRotor.begin();
                alphabetIterator != iAlphabet.end();
                ++alphabetIterator, ++inverseRotorIterator)
        {
            if (eachCharacter == *alphabetIterator)
            {
                eachCharacter = *inverseRotorIterator;
                break;
            }
        }
        break;
    }
}

void Rotor::offset()
{
    for (auto &rotorIterator : rotor)
    {
        if (rotorIterator == 'Z')
        {
            rotorIterator = 'A';
        }
        else
        {
            ++rotorIterator;
        }
    }
    std::rotate(inverseRotor.rbegin(), inverseRotor.rbegin() + 1, inverseRotor.rend());
}

void Rotor::ringApply(char ring)
{
    ring = toupper(ring);
    auto numberOfIterations = ring - 65;
    for (int i = 0; i < numberOfIterations; i++)
    {
        std::rotate(alphabet.rbegin(), alphabet.rbegin() + 1, alphabet.rend());
        for (auto &inverseRotorIterator : inverseRotor)
        {
            if (inverseRotorIterator == 'A')
            {
                inverseRotorIterator = 'Z';
            }
            else
            {
                --inverseRotorIterator;
            }
        }
    }
}
