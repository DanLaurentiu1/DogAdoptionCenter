#pragma once
#include "../Domain/DynamicVector.h"
#include "../Repository/Repository.h"
#include "../Repository/Repository.h"

class Controller
{
public:
    Controller();

    ~Controller();

    Controller(Repository *repository);

    void displayDogs();

    void addDog(Dog *dog);

    void removeDog(int index);

    void updateDog(Dog *dog, std::string name, std::string breed, int age, std::string photograph);

    Repository *getRepository();

    bool validateInputString(std::string stringValue);

    bool validateInputInt(int intValue);

private:
    Repository *repository;
};