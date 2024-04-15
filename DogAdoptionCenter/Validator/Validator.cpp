#include "../Validator/Validator.h"
#include <string>
#include <regex>

Validator::Validator()
{
}
bool Validator::validateDogStringAttribute(std::string stringToValidate)
{
    if (std::regex_match(stringToValidate, std::regex("^[A-Za-z]+$")) == false || stringToValidate.length() <= 3 || !std::isupper(stringToValidate[0]))
    {
        return false;
    }
    return true;
}
bool Validator::validateDogStringPhotograph(std::string stringToValidate)
{
    if (std::regex_match(stringToValidate, std::regex("^[A-Za-z.:/0-9]+$")) == false)
    {
        return false;
    }
    return true;
}
bool Validator::validateInteger(std::string integerToValidate)
{
    if (std::regex_match(integerToValidate, std::regex("^[0-9]+$")) == false)
    {
        return false;
    }
    return true;
}
