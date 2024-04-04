#include "Repository.h"
#include <iostream>

Repository::Repository()
{
}
Repository::Repository(std::vector<Dog> vector)
{
    this->vector = vector;

    Dog dog1("Greyhound", "Bella", 6, "https://en.wikipedia.org/wiki/Italian_Greyhound");
    Dog dog2("Boston Terrier", "Max", 0, "https://en.wikipedia.org/wiki/Boston_Terrier");
    Dog dog3("Border Collie", "Daisy", 2, "https://en.wikipedia.org/wiki/Border_Collie");
    Dog dog4("Labrador Retriever", "Charlie", 1, "https://en.wikipedia.org/wiki/Labrador_Retriever");
    Dog dog5("German Shepherd", "Lucy", 8, "https://simple.wikipedia.org/wiki/German_Shepherd");
    Dog dog6("Golden Retriever", "Cooper", 0, "https://en.wikipedia.org/wiki/Golden_Retriever");
    Dog dog7("Beagle", "Molly", 0, "https://en.wikipedia.org/wiki/Beagle");
    Dog dog8("French Bulldog", "Buddy", 4, "https://en.wikipedia.org/wiki/French_Bulldog");
    Dog dog9("Poodle ", "Luna", 2, "https://en.wikipedia.org/wiki/Poodle");
    Dog dog10("Dachshund", "Rocky", 0, "https://en.wikipedia.org/wiki/Dachshund");

    this->addDog(dog1);
    this->addDog(dog2);
    this->addDog(dog3);
    this->addDog(dog4);
    this->addDog(dog5);
    this->addDog(dog6);
    this->addDog(dog7);
    this->addDog(dog8);
    this->addDog(dog9);
    this->addDog(dog10);
}
std::vector<Dog> Repository::getVector()
{
    return this->vector;
}

Repository::~Repository() = default;

void Repository::addDog(Dog dog)
{
    this->vector.push_back(dog);
}
void Repository::removeDog(int index)
{
    this->vector.erase(this->vector.begin() + index);
}

void Repository::updateDog(Dog dog, std::string name, std::string breed, int age, std::string photograph)
{
    // pass
}

void Repository::displayAllDogs()
{
    for (auto dog : this->vector)
    {
        std::cout << "Dog(" + dog.getBreed() + " " + dog.getName() + " " + std::to_string(dog.getAge()) + " " + dog.getPhotograph() + ")" << std::endl;
    }
}