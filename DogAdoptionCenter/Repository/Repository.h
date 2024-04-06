#pragma once
#include "../Domain/Dog.h"
#include <vector>
class Repository
{

private:
    std::vector<Dog> vector;

    int findDogIndex(Dog dog);

public:
    Repository();
    Repository(std::vector<Dog> vector);

    ~Repository();

    std::vector<Dog> getVector();

    // Adds a dog to the repository
    // i: a dog
    void addDog(Dog dog);

    // Removes a dog from the repository
    // i: the index of the dog in the repository
    void removeDog(int index);

    // Updates a dog in the repository
    // i: a dog
    //    the information of a dog to be updated (all are optional attributes, if not passed to this function the default value is "" for string and 0 for age)
    void updateDog(int index, std::string name, std::string breed, int age, std::string photograph);

    // Displays all dogs from the repository
    void displayAllDogs();
};