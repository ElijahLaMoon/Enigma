#include <algorithm>
#include <iostream>
#include "Rotor.hpp"

void Rotor::setRotor(int choice)
{
    if (choice > 0 && choice < 6)
    {
        --choice; //people count from 1, unlike machines
        rotor = rotors[choice];
        inverseRotor = inverseRotors[choice];
    }
    else
    {
        std::cout << "Bad input. Try again" << std::endl;
    }
}

void Rotor::substitute(char &eachCharacter, char ring, char mode)
{
    ringApply(ring);
    switch (mode)
    {
    case 's':
        for (auto alphabetIterator = alphabet.begin(), rotorIterator = rotor.begin(); alphabetIterator != alphabet.end(), rotorIterator != rotor.end(); ++alphabetIterator, ++rotorIterator)
        {
            if (eachCharacter == *alphabetIterator)
            {
                eachCharacter = *rotorIterator;
                break;
            }
        }
        break;
    
    case 'r':
        for (auto alphabetIterator = alphabet.begin(), inverseRotorIterator = inverseRotor.begin(); alphabetIterator != alphabet.end(), inverseRotorIterator != inverseRotor.end(); ++alphabetIterator, ++inverseRotorIterator)
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
    std::rotate(alphabet.rbegin(), alphabet.rbegin() + 1, alphabet.rend());
}

void Rotor::ringApply(char ring)
{
    ring = toupper(ring);
    auto numberOfIterations = ring - 65;
    for (int i = 0; i < numberOfIterations; i++)
    {
        offset();
    }
}
