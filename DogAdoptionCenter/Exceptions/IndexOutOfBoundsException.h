#pragma once
#include "../Exceptions/Exception.h"
#include <string>
class IndexOutOfBoundsException : public Exception
{
private:
    std::string message;

public:
    IndexOutOfBoundsException();
    IndexOutOfBoundsException(std::string message);
    std::string getMessage();
    ~IndexOutOfBoundsException() = default;
};