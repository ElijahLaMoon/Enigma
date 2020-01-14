#include <string>
#include "Reflector.hpp"

void Reflector::reflectorSubstitute(char &eachCharacter)
{
    for (auto alphabetIterator = alphabet.begin(), reflectorIterator = reflector.begin(); 
        alphabetIterator != alphabet.end(); 
        ++alphabetIterator, ++reflectorIterator) 
    {
        if (eachCharacter == *alphabetIterator)
        {
            eachCharacter = *reflectorIterator;
            break;
        }
    }
}
