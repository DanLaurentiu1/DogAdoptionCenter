#include "Controller.h"
#include "../Tests/Tests.h"
#include <iostream>
#include <string>

Controller::Controller()
{
}

Controller::~Controller() = default;

Controller::Controller(Repository repository)
{
    this->repository = repository;
}

Repository Controller::getRepository()
{
    return this->repository;
}
void Controller::displayDogs()
{
    this->repository.displayAllDogs();
}
void Controller::addDog(Dog dog)
{
    this->repository.addDog(dog);
}

void Controller::removeDog(int index)
{
    this->repository.removeDog(index);
}
void Controller::updateDog(Dog dog, std::string name, std::string breed, int age, std::string photograph)
{
    this->repository.updateDog(dog, name, breed, age, photograph);
}
bool Controller::validateInputString(std::string stringValue)
{
    if (stringValue == "")
        return false;
    return true;
}

bool Controller::validateInputInt(int intValue)
{
    if (intValue == 10)
        return false;
    return true;
}
