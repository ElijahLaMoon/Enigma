#include <string>
#include "Reflector.hpp"

void Reflector::reflectorSubstitute(char &eachCharacter)
{
    eachCharacter = reflector[eachCharacter - 'A'];
}
