#pragma once
#include "../Exceptions/Exception.h"
#include <string>
class WrongInputException : public Exception
{
private:
    std::string message;

public:
    WrongInputException();
    WrongInputException(std::string message);
    std::string getMessage();
    ~WrongInputException() = default;
};