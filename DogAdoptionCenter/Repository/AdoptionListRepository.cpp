#include "AdoptionListRepository.h"
#include <iostream>

AdoptionListRepository::AdoptionListRepository()
{
}
AdoptionListRepository::AdoptionListRepository(std::vector<Dog> vector)
{
    this->vector = vector;
}

AdoptionListRepository::~AdoptionListRepository() = default;

std::vector<Dog> AdoptionListRepository::getVector()
{
    return this->vector;
}

void AdoptionListRepository::addDog(Dog dog)
{
    this->vector.push_back(dog);
}

void AdoptionListRepository::displayAllDogs()
{
    for (int i = 0; i < this->vector.size(); i++)
    {
        std::cout << std::to_string(i) << ": "
                  << "Dog(" + this->vector[i].getBreed() + " " + this->vector[i].getName() + " " + std::to_string(this->vector[i].getAge()) + " " + this->vector[i].getPhotograph() + ")" << std::endl;
    }
}
