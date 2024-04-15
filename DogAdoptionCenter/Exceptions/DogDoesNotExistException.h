#pragma once
#include "../Exceptions/Exception.h"
#include <string>

class DogDoesNotExistException : public Exception
{
private:
    std::string message;

public:
    DogDoesNotExistException();
    DogDoesNotExistException(std::string message);
    std::string getMessage();
    ~DogDoesNotExistException() = default;
};