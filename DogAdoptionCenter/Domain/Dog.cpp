#include "Dog.h"
#include <string>
#include <iostream>

Dog::Dog()
{
    this->breed = "unknown";
    this->name = "unknown";
    this->age = 0;
    this->photograph = "unknown";
}

Dog::Dog(std::string breed, std::string name, int age, std::string photograph)
{
    // TODO: some data validation here
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
std::ostream &operator<<(std::ostream &os, Dog &dog)
{
    return os << dog.toString();
}