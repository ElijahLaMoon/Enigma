#include <algorithm>
#include <iostream>
#include "Rotor.hpp"

void Rotor::setRotor(char choice)
{
    if (choice > 0 && choice < 6)
    {
        --choice; //people count from 1, unlike machines
        rotor = m_rotors[choice];
    }
    else
    {
        std::cout << "Bad input. Try again" << std::endl;
    }
}

void Rotor::substitute(std::string &message, char ring)
{
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ringApply(ring, alphabet);

    for (auto messageIterator = message.begin(); messageIterator != message.end(); ++messageIterator)
    {
        for (auto alphabetIterator = alphabet.begin(), rotorIterator = rotor.begin(); alphabetIterator != alphabet.end(), rotorIterator != rotor.end(); ++alphabetIterator, ++rotorIterator)
        {
            if (*messageIterator == *alphabetIterator)
            {
                *messageIterator = *rotorIterator;
                offset(alphabet);
                break;
            }
        }
    }
}

void Rotor::offset(std::string &alphabet)
{
    for (auto &alphabetIterator : alphabet)
    {
        if (alphabetIterator == 'Z')
        {
            alphabetIterator = 'A';
        }
        else
            ++alphabetIterator;
    }
}

void Rotor::ringApply(char ring, std::string &alphabet)
{
    auto numberOfIterations = ring - 65;
    for (int i = 0; i < numberOfIterations; i++)
    {
        offset(alphabet);
    }
}
