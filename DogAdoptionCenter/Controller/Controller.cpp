#include "Controller.h"
#include <iostream>
#include <string>
#include <regex>

Controller::Controller()
{
}

Controller::~Controller() = default;

Controller::Controller(DogRepository dogRepository, AdoptionListRepository adoptionListRepository, Validator validator)
{
    this->dogRepository = dogRepository;
    this->adoptionListRepository = adoptionListRepository;
    this->validator = validator;
}
Controller::Controller(DogRepository dogRepository, int noAdoptionListRepository, Validator validator)
{
    this->dogRepository = dogRepository;
    this->validator = validator;
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

void Controller::validateInputDogAttributes(std::string breed, std::string name, std::string age, std::string photograph)
{
    if (breed != "" && this->validator.validateDogStringAttribute(breed) == false)
    {
        throw WrongInputException("Wrong input -> breed");
    }
    if (name != "" && this->validator.validateDogStringAttribute(name) == false)
    {
        throw WrongInputException("Wrong input -> name");
    }
    if (age != "" && this->validator.validateInteger(age) == false)
    {
        throw WrongInputException("Wrong input -> age");
    }
    if (photograph != "" && this->validator.validateDogStringPhotograph(photograph) == false)
    {
        throw WrongInputException("Wrong input -> photograph");
    }
}

void Controller::validateInteger(std::string integerToValidate)
{
    if (this->validator.validateInteger(integerToValidate) == false)
    {
        throw WrongInputException("Wrong input -> integer");
    }
}
std::vector<int> Controller::filterDogs(int age, std::string breed)
{
    std::vector<int> v = {};

    for (int i = 0; i < this->getDogRepository().getVector().size(); i++)
    {
        if (this->getDogRepository().getVector()[i].getAge() < age)
        {
            if (breed != "." && this->getDogRepository().getVector()[i].getBreed() == breed)
            {
                v.push_back(i);
            }
            else if (breed == ".")
            {
                v.push_back(i);
            }
        }
    }
    return v;
}