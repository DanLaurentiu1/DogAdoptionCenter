#include "Controller.h"
#include "../Tests/Tests.h"
#include <iostream>
#include <string>
#include <regex>

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
void Controller::updateDog(int index, std::string name, std::string breed, int age, std::string photograph)
{
    this->repository.updateDog(index, name, breed, age, photograph);
}
bool Controller::validateInputString(std::string stringValue)
{
    return std::regex_match(stringValue, std::regex("^[A-Za-z]+$"));
}
