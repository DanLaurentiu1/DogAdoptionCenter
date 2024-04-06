#pragma once
#include "../Repository/DogRepository.h"
#include "../Repository/AdoptionListRepository.h"

class Controller
{
private:
    DogRepository dogRepository;
    AdoptionListRepository adoptionListRepository;

public:
    // default controller constructor
    Controller();

    // destructor
    ~Controller();

    // this is used when we are in user mode (need to keep track of both repos)
    Controller(DogRepository dogRepository, AdoptionListRepository adoptionListRepository);

    // this is used when we are in admin mode (dont need adoptionRepo)
    Controller(DogRepository dogRepository, int noAdoptionListRepository);

    std::vector<Dog> getDogRepositoryVector();

    // Displays all dogs from the DogRepository
    void DogRepository_displayDogs();

    // Adds a dog to the DogRepository
    // i: a dog
    void DogRepository_addDog(Dog dog);

    // Removes a dog from the DogRepository
    // i: the index of the dog in the DogRepository
    void DogRepository_removeDog(int index);

    // Updates a dog in the DogRepository
    // i: a dog
    //    the information of a dog to be updated (all are optional attributes, if not passed to this function the default value is "" for string and 0 for age)
    void DogRepository_updateDog(int index, std::string name = "", std::string breed = "", int age = 0, std::string photograph = "");

    // Gets the DogRepository
    // return: the repository
    DogRepository getDogRepository();

    // Gets the adoptionListRepository
    // return: the repository
    AdoptionListRepository getAdoptionListRepository();

    // Displays all dogs from the adoptionListRepository
    void AdoptionListRepository_displayDogs();

    // Adds a dog to the adoptionListRepository
    // i: a dog
    void AdoptionListRepository_addDog(Dog dog);

    // Filters the dogs from the dogRepository based on age and breed
    // return: the vector with the indexes of the dogs found in the DogRepostiory
    std::vector<int> filterDogs(int age, std::string breed);

    // Sees if a string is made of letters only, if yes -> true else -> false
    // true or false
    bool validateInputString(std::string stringValue);
};