#pragma once
#include <string>

class Exception
{
private:
    std::string message;

public:
    Exception();
    Exception(std::string message);
    std::string getMessage();
    ~Exception() = default;
};