#include <string>
#include "Reflector.hpp"
#include "Rotor.hpp"

void Reflector::reflectorSubstitute(char &eachCharacter)
{
    for (auto alphabetIterator = alphabet.begin(), reflectorIterator = _reflector.begin(); alphabetIterator != alphabet.end(), reflectorIterator != _reflector.end(); ++alphabetIterator, ++reflectorIterator)
    {
        if (eachCharacter == *alphabetIterator)
        {
            eachCharacter = *reflectorIterator;
            break;
        }
    }

    /*
    for (auto messageIterator = message.begin(); messageIterator != message.end(); ++messageIterator)
    {
        for (auto alphabetIterator = alphabet.begin(), reflectorIterator = _reflector.begin(); alphabetIterator != alphabet.end(), reflectorIterator != _reflector.end(); ++alphabetIterator, ++reflectorIterator)
        {
            if (*messageIterator == *alphabetIterator)
            {
                *messageIterator = *reflectorIterator;
                break;
            }
        }
    }
    */
}