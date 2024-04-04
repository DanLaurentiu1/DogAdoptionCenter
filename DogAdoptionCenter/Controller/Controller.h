#pragma once
#include "../Repository/Repository.h"

class Controller
{
public:
    Controller();

    ~Controller();

    Controller(Repository repository);

    // Displays all dogs from the repository
    void displayDogs();

    // Adds a dog to the repository
    // i: a pointer to a dog
    void addDog(Dog dog);

    // Removes a dog from the repository
    // i: the index of the dog in the repository
    void removeDog(int index);

    // Updates a dog in the repository
    // i: a pointer to a dog
    //    the information of a dog to be updated (all are optional attributes, if not passed to this function the default value is "" for string and 0 for age)
    void updateDog(Dog dog, std::string name, std::string breed, int age, std::string photograph);

    // Gets the repository
    Repository getRepository();

    bool validateInputString(std::string stringValue);

    bool validateInputInt(int intValue);

private:
    Repository repository;
};