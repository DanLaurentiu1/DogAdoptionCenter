#pragma once
#include "../Domain/DynamicVector.h"
#include "../Domain/Dog.h"

class Repository
{

private:
    DynamicVector *vector;

public:
    Repository(DynamicVector *vector);

    ~Repository();

    DynamicVector *getVector();

    void addDog(Dog *dog);

    void removeDog(int index);

    void updateDog(Dog *dog, std::string name, std::string breed, int age, std::string photograph);

    void displayAllDogs();
};