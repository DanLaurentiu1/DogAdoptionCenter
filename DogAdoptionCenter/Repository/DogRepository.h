#pragma once
#include "../Domain/Dog.h"
#include "../Exceptions/DogDuplicateException.h"
#include "../Exceptions/DogDoesNotExistException.h"
#include <vector>
class DogRepository
{

private:
    std::vector<Dog> vector;
    std::string fileName;

    int findDogIndex(Dog dog);

    void loadFromFile();

    void saveToFile();

public:
    // default constructor for the dogRepository
    DogRepository();
    DogRepository(std::vector<Dog> vector, std::string fileName);

    ~DogRepository();

    // Gets the vector of Dogs
    // return: the vector
    std::vector<Dog> getVector();

    // Adds a dog to the DogRepository
    // i: a dog
    void addDog(Dog dog);

    // Removes a dog from the DogRepository
    // i: the index of the dog in the DogRepository
    void removeDog(int index);

    // Updates a dog in the DogRepository
    // i: a dog
    //    the information of a dog to be updated (all are optional attributes, if not passed to this function the default value is "" for string and 0 for age)
    void updateDog(int index, std::string name = "", std::string breed = "", int age = 0, std::string photograph = "");

    // Displays all dogs from the DogRepository
    void displayAllDogs();

    // Displays one dog with the index specified
    void displayDog(int index);

    bool isDogInRepository(Dog dog);
};