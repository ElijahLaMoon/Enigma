#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include "Plugboard.hpp"


bool Plugboard::plugboardDuplicateCheck(std::string &plugboardCopy)
{
    for (int firstCharacter = 0; firstCharacter < plugboardCopy.size() - 1; ++firstCharacter)
    {
        for (int secondCharacter = firstCharacter + 1; secondCharacter < plugboardCopy.size(); ++secondCharacter)
        {
            if (plugboardCopy[firstCharacter] == plugboardCopy[secondCharacter])
            {
                std::cout << "Bad input. Try again";
                return true && EXIT_FAILURE;
            }
            else
            {
                return false;
            }
        }
    }
}

bool Plugboard::lengthCheck(std::string &plugboardCopy)
{
    if (plugboardCopy.length() / 2 > 13)
    {
        std::cout << "Bad input. Try again";
        return true;
    }
    else
    {
        return false;
    }
}

bool Plugboard::setPlugboard()
{
    std::getline(std::cin, plugboardCopy);
    plugboardCopy.erase(std::remove(plugboardCopy.begin(), plugboardCopy.end(), ' '), plugboardCopy.end());
    if (plugboardDuplicateCheck(plugboardCopy) || lengthCheck(plugboardCopy))
    {
        return true;
    }
    else 
    {
        return false;
    }
    
    for (int firstCharacter = 0, secondCharacter = firstCharacter + 1; firstCharacter < plugboardCopy.length() - 1, secondCharacter < plugboardCopy.length(); ++firstCharacter, ++secondCharacter)
    {
        auto pair = std::make_pair(plugboardCopy[firstCharacter], plugboardCopy[secondCharacter]);
        plugboard.emplace(pair);
    }

}
