#pragma once
#include <string>
#include <iostream>

class Validator
{
public:
    Validator();
    ~Validator() = default;

    bool validateDogStringAttribute(std::string stringToValidate);
    bool validateDogStringPhotograph(std::string stringToValidate);
    bool validateInteger(std::string integerToValidate);
};