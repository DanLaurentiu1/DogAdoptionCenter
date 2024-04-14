#include "Controller.h"
#include "../Tests/Tests.h"
#include <iostream>
#include <string>
#include <regex>

Controller::Controller()
{
}

Controller::~Controller() = default;

Controller::Controller(DogRepository dogRepository, AdoptionListRepository adoptionListRepository)
{
    this->dogRepository = dogRepository;
    this->adoptionListRepository = adoptionListRepository;
}
Controller::Controller(DogRepository dogRepository, int noAdoptionListRepository)
{
    this->dogRepository = dogRepository;
}

DogRepository Controller::getDogRepository()
{
    return this->dogRepository;
}
std::vector<Dog> Controller::getDogRepositoryVector()
{
    return this->dogRepository.getVector();
}
void Controller::DogRepository_displayDogs()
{
    this->dogRepository.displayAllDogs();
}
void Controller::DogRepository_addDog(Dog dog)
{
    this->dogRepository.addDog(dog);
}

void Controller::DogRepository_removeDog(int index)
{
    this->dogRepository.removeDog(index);
}
void Controller::DogRepository_updateDog(int index, std::string breed, std::string name, int age, std::string photograph)
{
    this->dogRepository.updateDog(index, breed, name, age, photograph);
}
AdoptionListRepository Controller::getAdoptionListRepository()
{
    return this->adoptionListRepository;
}

void Controller::AdoptionListRepository_displayDogs()
{
    return this->adoptionListRepository.displayAllDogs();
}

void Controller::AdoptionListRepository_addDog(Dog dog)
{
    return this->AdoptionListRepository_addDog(dog);
}

bool Controller::validateInputString(std::string stringValue)
{
    return std::regex_match(stringValue, std::regex("^[A-Za-z]+$"));
}
std::vector<int> Controller::filterDogs(int age, std::string breed)
{
    std::vector<int> v;

    for (int i = 0; i < this->getDogRepository().getVector().size(); i++)
    {
        if (this->getDogRepository().getVector()[i].getAge() < age && this->getDogRepository().getVector()[i].getBreed() == breed)
        {
            v.push_back(i);
        }
    }

    return v;
}