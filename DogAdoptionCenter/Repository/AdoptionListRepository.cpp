#include "AdoptionListRepository.h"
#include <iostream>
#include <fstream>
AdoptionListRepository::AdoptionListRepository()
{
}
AdoptionListRepository::AdoptionListRepository(std::vector<Dog> vector, std::string fileName)
{
    this->vector = vector;
    this->fileName = fileName;
    loadFromFile();
}
void AdoptionListRepository::loadFromFile()
{
    std::ifstream fileIn(fileName, std::ios::in);
    Dog dog;
    while (fileIn >> dog)
    {
        this->vector.push_back(dog);
    }
    fileIn.close();
}

void AdoptionListRepository::saveToFile()
{
    std::ofstream fout(fileName, std::ios::trunc);
    for (Dog dog : this->vector)
        fout << dog << '\n';
    fout.close();
}

AdoptionListRepository::~AdoptionListRepository() = default;

std::vector<Dog> AdoptionListRepository::getVector()
{
    return this->vector;
}

void AdoptionListRepository::addDog(Dog dog)
{
    if (this->isDogInRepository(dog) == false)
    {
        throw DogDuplicateException("There is another dog with the same attributes!");
    }
    this->vector.push_back(dog);
    saveToFile();
}

void AdoptionListRepository::displayAllDogs()
{
    for (int i = 0; i < this->vector.size(); i++)
    {
        std::cout << std::to_string(i) << ": "
                  << "Dog(" + this->vector[i].getBreed() + " " + this->vector[i].getName() + " " + std::to_string(this->vector[i].getAge()) + " " + this->vector[i].getPhotograph() + ")" << std::endl;
    }
}
bool AdoptionListRepository::isDogInRepository(Dog dog)
{
    for (Dog d : this->vector)
    {
        if (dog == d)
        {
            return false;
        }
    }
    return true;
}