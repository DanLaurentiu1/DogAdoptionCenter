#include "../Exceptions/IndexOutOfBoundsException.h"
#include <string>

IndexOutOfBoundsException::IndexOutOfBoundsException()
{
    this->message = "IndexOutOfBoundsException";
}
IndexOutOfBoundsException::IndexOutOfBoundsException(std::string message)
{
    this->message = message;
}
std::string IndexOutOfBoundsException::getMessage()
{
    return this->message;
}
