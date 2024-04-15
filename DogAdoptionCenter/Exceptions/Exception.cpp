#include "../Exceptions/Exception.h"
#include <string>

Exception::Exception()
{
    this->message = "Exception";
}
Exception::Exception(std::string message)
{
    this->message = message;
}
std::string Exception::getMessage()
{
    return this->message;
}