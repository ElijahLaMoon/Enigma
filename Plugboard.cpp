#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "Plugboard.hpp"


bool Plugboard::plugboardDuplicateCheck(std::string &plugboardCopy)
{
    for (int firstCharacter = 0, secondCharacter = firstCharacter + 1;
            secondCharacter < plugboardCopy.length();
            ++firstCharacter, ++secondCharacter)
    {
        if (plugboardCopy[firstCharacter] == plugboardCopy[secondCharacter])
        {
            std::cout << "Bad input. Try again";
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Plugboard::lengthCheck(std::string &plugboardCopy)
{
    if (plugboardCopy.length() / 2 > 13)
    {
        std::cout << "Bad input. Try again";
        return true && EXIT_FAILURE;
    }
    else
    {
        return false;
    }
}

bool Plugboard::setPlugboard(std::string &plugboardCopy)
{
    std::cin.ignore();
    std::getline(std::cin, plugboardCopy);
    std::transform(plugboardCopy.begin(), plugboardCopy.end(), plugboardCopy.begin(), ::toupper);
    plugboardCopy.erase(std::remove(plugboardCopy.begin(), plugboardCopy.end(), ' '), plugboardCopy.end());
    if (plugboardDuplicateCheck(plugboardCopy) || lengthCheck(plugboardCopy))
    {
        return true;
    }
    
    for (int firstCharacter = 0, secondCharacter = firstCharacter + 1;
            secondCharacter < plugboardCopy.length();
            ++firstCharacter, ++secondCharacter)
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
        if (mapIterator.first == eachCharacter) eachCharacter = mapIterator.second;
        if (mapIterator.second == eachCharacter) eachCharacter = mapIterator.first;
    }
}
