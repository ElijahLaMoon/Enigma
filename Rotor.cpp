#include <algorithm>
#include <iostream>
#include <string>
#include "Rotor.hpp"

void Rotor::setRotor(char choice)
{
    if(choice > 0 && choice < 6)
    {
        --choice; //people count from 1, unlike machines
        rotor = m_rotors[choice];
    } else 
    {
        std::cout << "Bad input. Try again" << std::endl;
    }
}

void Rotor::substitute(std::string& message)
{
	std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    std::string alphabet =
    {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    };
    
    for (auto messageIterator = message.begin(); messageIterator != message.end(); ++messageIterator)
    {
        for (auto alphabetIterator = alphabet.begin(), rotorIterator = rotor.begin(); alphabetIterator != alphabet.end(), rotorIterator != rotor.end(); ++alphabetIterator, ++rotorIterator)
        {
            if (*messageIterator == *alphabetIterator)
            {
                *messageIterator = *rotorIterator;
            }
        } 
    }
}
