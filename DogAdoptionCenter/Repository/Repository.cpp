#include "Repository.h"
#include "../Domain/DynamicVector.h"
#include <iostream>

Repository::Repository(DynamicVector *vector)
{
    this->vector = vector;

    Dog *dog1 = new Dog("Greyhound", "Bella", 6, "https://en.wikipedia.org/wiki/Italian_Greyhound");
    Dog *dog2 = new Dog("Boston Terrier", "Max", 0, "https://en.wikipedia.org/wiki/Boston_Terrier");
    Dog *dog3 = new Dog("Border Collie", "Daisy", 2, "https://en.wikipedia.org/wiki/Border_Collie");
    Dog *dog4 = new Dog("Labrador Retriever", "Charlie", 1, "https://en.wikipedia.org/wiki/Labrador_Retriever");
    Dog *dog5 = new Dog("German Shepherd", "Lucy", 8, "https://simple.wikipedia.org/wiki/German_Shepherd");
    Dog *dog6 = new Dog("Golden Retriever", "Cooper", 0, "https://en.wikipedia.org/wiki/Golden_Retriever");
    Dog *dog7 = new Dog("Beagle", "Molly", 0, "https://en.wikipedia.org/wiki/Beagle");
    Dog *dog8 = new Dog("French Bulldog", "Buddy", 4, "https://en.wikipedia.org/wiki/French_Bulldog");
    Dog *dog9 = new Dog("Poodle ", "Luna", 2, "https://en.wikipedia.org/wiki/Poodle");
    Dog *dog10 = new Dog("Dachshund", "Rocky", 0, "https://en.wikipedia.org/wiki/Dachshund");

    this->vector->add(dog1);
    this->vector->add(dog2);
    this->vector->add(dog3);
    this->vector->add(dog4);
    this->vector->add(dog5);
    this->vector->add(dog6);
    this->vector->add(dog7);
    this->vector->add(dog8);
    this->vector->add(dog9);
    this->vector->add(dog10);

    // should i free the vector here ?
}
DynamicVector *Repository::getVector()
{
    return this->vector;
}

Repository::~Repository() = default;

void Repository::addDog(Dog *dog)
{
    this->vector->add(dog);
}
void Repository::removeDog(int index)
{
    this->vector->remove(index);
}

void Repository::updateDog(Dog *dog, std::string name, std::string breed, int age, std::string photograph)
{
    this->vector->update(dog, name, breed, age, photograph);
}

void Repository::displayAllDogs()
{
    this->vector->displayAllDogs();
}