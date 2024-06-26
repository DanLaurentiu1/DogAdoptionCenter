#pragma once
#include "../Domain/Dog.h"
#include "../Exceptions/DogDuplicateException.h"
#include "../Exceptions/DogDoesNotExistException.h"
#include <vector>
class AdoptionListRepository
{

private:
    std::vector<Dog> vector;
    std::string fileName;
    void loadFromFile();
    void saveToFile();

public:
    // Default constructor for adoptionListRepo
    AdoptionListRepository();
    AdoptionListRepository(std::vector<Dog> vector, std::string fileName);

    ~AdoptionListRepository();

    // Gets the vector
    // the vector
    std::vector<Dog> getVector();

    // Adds a dog to the AdoptionListRepository
    // i: a dog
    void addDog(Dog dog);

    // Displays all dogs from the AdoptionListRepository
    void displayAllDogs();

    bool isDogInRepository(Dog dog);
};