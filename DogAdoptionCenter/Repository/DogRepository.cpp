#include "DogRepository.h"
#include <iostream>

DogRepository::DogRepository()
{
}
DogRepository::DogRepository(std::vector<Dog> vector)
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
    Dog dog9("Poodle", "Luna", 2, "https://en.wikipedia.org/wiki/Poodle");
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
std::vector<Dog> DogRepository::getVector()
{
    return this->vector;
}

DogRepository::~DogRepository() = default;

void DogRepository::addDog(Dog dog)
{
    for (Dog d : this->vector)
    {
        if (dog == d)
        {
            std::cout << "There already is a dog with the same attributes" << std::endl;
            return;
        }
    }
    this->vector.push_back(dog);
}
void DogRepository::removeDog(int index)
{
    this->vector.erase(this->vector.begin() + index);
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
}
void DogRepository::updateDog(int index, std::string name, std::string breed, int age, std::string photograph)
{
    this->vector[index].setAge(age);
    this->vector[index].setBreed(breed);
    this->vector[index].setName(name);
    this->vector[index].setPhotograph(photograph);
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