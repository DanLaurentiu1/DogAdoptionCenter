#pragma once
#include "../Exceptions/Exception.h"
#include <string>

class DogDuplicateException : public Exception
{
private:
    std::string message;

public:
    DogDuplicateException();
    DogDuplicateException(std::string message);
    std::string getMessage();
    ~DogDuplicateException() = default;
};