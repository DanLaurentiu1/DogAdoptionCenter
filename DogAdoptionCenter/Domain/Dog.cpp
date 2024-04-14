#include "Dog.h"
#include <string>
#include <iostream>
#include <sstream>

Dog::Dog()
{
    this->breed = "unknown";
    this->name = "unknown";
    this->age = 0;
    this->photograph = "unknown";
}

Dog::Dog(std::string breed, std::string name, int age, std::string photograph)
{
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}
/*
Dog::Dog(Dog &dog)
{
    this->name = dog.name;
    this->breed = dog.breed;
    this->age = dog.age;
    this->photograph = dog.photograph;
}
*/
Dog::~Dog() = default;

std::string Dog::toString()
{
    return name + ", " + breed + ", " + std::to_string(age) + ", " + photograph;
}
std::string Dog::getBreed()
{
    return this->breed;
}

std::string Dog::getName()
{
    return this->name;
}

std::string Dog::getPhotograph()
{
    return this->photograph;
}

int Dog::getAge()
{
    return this->age;
}

void Dog::setBreed(std::string breed)
{
    this->breed = breed;
}

void Dog::setName(std::string name)
{
    this->name = name;
}

void Dog::setPhotograph(std::string photograph)
{
    this->photograph = photograph;
}

void Dog::setAge(int age)
{
    this->age = age;
}

bool Dog::operator==(Dog &dog)
{
    if (this->name == dog.name && this->breed == dog.breed && this->photograph == dog.photograph && this->age == dog.age)
    {
        return true;
    }

    return false;
}

std::ostream &operator<<(std::ostream &outputStream, Dog &dog)
{
    outputStream << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photograph;
    return outputStream;
}

void strip(std::string stringToBeModified)
{
    while (stringToBeModified[0] == '\n' || stringToBeModified[0] == ',' || stringToBeModified[0] == ' ')
        stringToBeModified.erase(stringToBeModified.begin());

    while (stringToBeModified[stringToBeModified.length() - 1] == '\n' ||
           stringToBeModified[stringToBeModified.length() - 1] == ',' ||
           stringToBeModified[stringToBeModified.length() - 1] == ' ')
    {
        stringToBeModified.erase(stringToBeModified.end() - 1);
    }
}

std::istream &operator>>(std::istream &inputStream, Dog &dog)
{
    std::string line;
    std::getline(inputStream, line);
    if (line.empty() || line == "\n")
        return inputStream;

    std::stringstream dogAttributes{line};
    std::string name, breed, age, photograph;

    std::getline(dogAttributes, breed, ',');
    strip(breed);

    std::getline(dogAttributes, name, ',');
    strip(name);

    std::getline(dogAttributes, age, ',');
    strip(age);
    int ageAsInt = stoi(age);

    std::getline(dogAttributes, photograph, ',');
    strip(photograph);

    dog = Dog(breed, name, ageAsInt, photograph);
    return inputStream;
}