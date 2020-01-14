#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "Plugboard.hpp"


bool Plugboard::plugboardDuplicateCheck()
{
    for (size_t firstCharacter = 0; firstCharacter < plugboardCopy.length() - 1; ++firstCharacter)
    {
        for (size_t secondCharacter = firstCharacter + 1; secondCharacter < plugboardCopy.length(); ++secondCharacter)
        {
            if (plugboardCopy[firstCharacter] == plugboardCopy[secondCharacter])
            {
                std::cout << "Error: duplicates found" << std::endl;
                return true;
            }
        }
    }
    return false;
}

bool Plugboard::lengthCheck()
{
    if (plugboardCopy.length() / 2 > 13)
    {
        std::cout << "Error: too much pairs. There should no more than 13 pairs" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Plugboard::correctInputCheck()
{
    for (auto &iterator : plugboardCopy)
    {
        if (!(iterator > 64 && iterator < 91))
        {
            std::cout << "Error: plugboard should contain only alphabetical characters (A-Z)" << std::endl;
            return true;
		}
	}
    return false;
}

bool Plugboard::setPlugboard()
{
    std::cout << "Type characters in pairs (i.e. \"KL ON ...\"). No more than 13 pairs" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, plugboardCopy);
    std::transform(plugboardCopy.begin(), plugboardCopy.end(), plugboardCopy.begin(), ::toupper);
    plugboardCopy.erase(std::remove(plugboardCopy.begin(), plugboardCopy.end(), ' '), plugboardCopy.end());

    if (plugboardDuplicateCheck() || lengthCheck() || correctInputCheck())
    {
        return true;
    }
    
    for (size_t firstCharacter = 0, secondCharacter = firstCharacter + 1;
            secondCharacter < plugboardCopy.length();
            firstCharacter += 2, secondCharacter += 2)
    {
        auto pair = std::make_pair(plugboardCopy[firstCharacter], plugboardCopy[secondCharacter]);
        plugboard.emplace(pair);
    }

    return false;
}

void Plugboard::substitute(char &eachCharacter)
{
    for (auto const &mapIterator : plugboard)
    {
        if (mapIterator.first == eachCharacter)
        {
            eachCharacter = mapIterator.second;
            break;
        }
        if (mapIterator.second == eachCharacter)
        {
            eachCharacter = mapIterator.first;
            break;
        }   
    }
}
