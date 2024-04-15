#include "../Exceptions/DogDuplicateException.h"

DogDuplicateException::DogDuplicateException()
{
    this->message = "DogDuplicate Exception";
}
DogDuplicateException::DogDuplicateException(std::string message)
{
    this->message = message;
}
std::string DogDuplicateException::getMessage()
{
    return this->message;
}
