#include "../Exceptions/Exception.h"
#include "../Exceptions/WrongInputException.h"
#include <string>

WrongInputException::WrongInputException()
{
    this->message = "WrongInputException";
}
WrongInputException::WrongInputException(std::string message)
{
    this->message = message;
}
std::string WrongInputException::getMessage()
{
    return this->message;
}