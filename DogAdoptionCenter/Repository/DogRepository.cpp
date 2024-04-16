#include "DogRepository.h"
#include <iostream>
#include <fstream>
#include <string>
DogRepository::DogRepository()
{
}
DogRepository::DogRepository(std::vector<Dog> vector, std::string fileName)
{
    this->vector = vector;
    this->fileName = fileName;
    loadFromFile();
}

void DogRepository::loadFromFile()
{
    std::ifstream fileIn;
    fileIn.open(fileName, std::ios::in);
    Dog dog;
    while (fileIn >> dog)
    {
        this->vector.push_back(dog);
    }
    fileIn.close();
}

void DogRepository::saveToFile()
{
    std::ofstream fout(fileName, std::ios::trunc);
    for (Dog dog : this->vector)
        fout << dog << '\n';
    fout.close();
}

std::vector<Dog> DogRepository::getVector()
{
    return this->vector;
}

DogRepository::~DogRepository() = default;

void DogRepository::addDog(Dog dog)
{
    if (this->isDogInRepository(dog) == false)
    {
        throw DogDuplicateException("There is another dog with the same attributes!");
    }
    this->vector.push_back(dog);
    saveToFile();
}
void DogRepository::removeDog(int index)
{
    this->vector.erase(this->vector.begin() + index);
    saveToFile();
}

int DogRepository::findDogIndex(Dog dog)
{
    for (int i = 0; i <= this->vector.size(); i++)
    {
        if (this->vector[i] == dog)
        {
            return i;
        }
    }
    return -1;
    // Dog not found exception
}
void DogRepository::updateDog(int index, std::string breed, std::string name, int age, std::string photograph)
{
    Dog dog(breed, name, age, photograph);
    if (this->isDogInRepository(dog) == false)
    {
        throw DogDuplicateException("There is another dog with the same attributes!");
    }
    this->vector[index].setAge(age);
    this->vector[index].setBreed(breed);
    this->vector[index].setName(name);
    this->vector[index].setPhotograph(photograph);
    saveToFile();
}

void DogRepository::displayAllDogs()
{
    for (int i = 0; i < this->vector.size(); i++)
    {
        std::cout << std::to_string(i) << ": "
                  << "Dog(" + this->vector[i].getBreed() + " " + this->vector[i].getName() + " " + std::to_string(this->vector[i].getAge()) + " " + this->vector[i].getPhotograph() + ")" << std::endl;
    }
}
void DogRepository::displayDog(int index)
{
    std::cout << "Dog(" + this->vector[index].getBreed() + " " + this->vector[index].getName() + " " + std::to_string(this->vector[index].getAge()) + " " + this->vector[index].getPhotograph() + ")" << std::endl;
}
bool DogRepository::isDogInRepository(Dog dog)
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