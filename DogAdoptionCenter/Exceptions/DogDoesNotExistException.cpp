#include "../Exceptions/DogDoesNotExistException.h"

DogDoesNotExistException::DogDoesNotExistException()
{
    this->message = "DogDoesNotExist Exception";
}
DogDoesNotExistException::DogDoesNotExistException(std::string message)
{
    this->message = message;
}
std::string DogDoesNotExistException::getMessage()
{
    return this->message;
}
