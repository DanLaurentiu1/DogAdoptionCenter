#include "../Controller/Controller.h"
#include "../Tests/Tests.h"
#include <iostream>
#include <string>

void displayAdministrator()
{
    std::cout << std::endl;
    std::cout << " Welcome to the Dog Adoption Centre! " << std::endl;
    std::cout << " Administrator Account " << std::endl;
    std::cout << "Press 1 to display all the dogs up for adoption" << std::endl;
    std::cout << "Press 2 to adopt a dog" << std::endl;
    std::cout << "Press 3 to update the details of a dog" << std::endl;
    std::cout << "Press 4 to add a new dog for adoption" << std::endl;
    std::cout << "Press 5 to quit" << std::endl;
    std::cout << "-> ";
}

void displayUser()
{
    std::cout << std::endl;
    std::cout << " Welcome to the Dog Adoption Centre! " << std::endl;
    std::cout << " User Account " << std::endl;
    std::cout << "Press 1 to choose dogs to adopt" << std::endl;
    std::cout << "Press 2 to filter dogs and then choose dogs to adopt" << std::endl;
    std::cout << "Press 3 to display your current adoption list" << std::endl;
    std::cout << "Press 4 to quit" << std::endl;
    std::cout << "-> ";
}

void displayUserChoice()
{
    std::cout << "Press 1 if you want to adopt this dog" << std::endl;
    std::cout << "Press 2 if you don't want to adopt this dog" << std::endl;
    std::cout << "Press 3 if you want to quit" << std::endl;
}
void startAdministrator()
{
    std::vector<Dog> vector;
    DogRepository repository(vector, "../TextFiles/dogRepository.txt");
    Controller controller(repository, -1);

    bool cond = true;
    while (cond)
    {
        displayAdministrator();
        int option;
        std::cin >> option;
        switch (option)
        {
        case 1: // display all the dogs
            controller.DogRepository_displayDogs();
            break;
        case 2: // adopt a dog
        {
            std::cout << "From this list, choose which dog to adopt " << std::endl;
            controller.DogRepository_displayDogs();

            int index;
            std::cout << "Enter the index of the dog you would like to adopt: " << std::endl;
            std::cin >> index;

            if (index < 0 || index > controller.getDogRepositoryVector().size())
            {
                std::cout << "There is no dog with that index" << std::endl;
                break;
            }
            controller.DogRepository_removeDog(index);
            break;
        }

        case 3: // update a dog
        {
            std::string breed, name, photograph;
            int age, choice;

            std::cout << "From this list, choose which dog to update " << std::endl;
            controller.DogRepository_displayDogs();

            std::cout << "-> ";
            std::cin >> choice;

            if (choice < 0 || choice > controller.getDogRepositoryVector().size())
            {
                std::cout << "There is no dog with that index" << std::endl;
                break;
            }

            std::cout << "Enter a new breed name: ";
            std::cin >> breed;
            std::cout << std::endl;

            std::cout << "Enter a new name: ";
            std::cin >> name;
            std::cout << std::endl;

            std::cout << "Enter a new age: ";
            std::cin >> age;
            std::cout << std::endl;

            std::cout << "Enter a new photograph link: ";
            std::cin >> photograph;
            std::cout << std::endl;

            if (controller.validateInputString(breed) == false || controller.validateInputString(name) == false || controller.validateInputString(photograph) == false)
            {
                std::cout << "Wrong input" << std::endl;
                break;
            }

            controller.DogRepository_updateDog(choice, breed, name, age, photograph);

            break;
        }

        case 4: // add a dog
        {
            std::string breed, name, photograph;
            int age;

            std::cout << "Enter a breed name: ";
            std::cin >> breed;
            std::cout << std::endl;

            std::cout << "Enter a name: ";
            std::cin >> name;
            std::cout << std::endl;

            std::cout << "Enter a age: ";
            std::cin >> age;
            std::cout << std::endl;

            std::cout << "Enter a photograph link: ";
            std::cin >> photograph;
            std::cout << std::endl;

            if (controller.validateInputString(breed) == false || controller.validateInputString(name) == false || controller.validateInputString(photograph) == false)
            {
                std::cout << "Wrong input" << std::endl;
                break;
            }

            Dog dog(breed, name, age, photograph);
            controller.DogRepository_addDog(dog);
            break;
        }
        case 5: // quit
            cond = false;
            break;
        default:
            std::cout << "Wrong input, quitting" << std::endl;
            cond = false;
        }
    }

    controller.~Controller();
    repository.~DogRepository();
}

void startUser()
{
    std::vector<Dog> adoptionListVector;
    std::vector<Dog> dogVector;
    AdoptionListRepository adoptionListRepository(adoptionListVector, "../TextFiles/adoptionListRepository.txt");
    DogRepository dogRepository(dogVector, "../TextFiles/dogRepository.txt");
    Controller controller(dogRepository, adoptionListRepository);

    bool cond = true;
    while (cond)
    {
        displayUser();
        int option;
        std::cin >> option;
        switch (option)
        {
        case 1:
        { // choose dogs to adopt
            bool flag = true;
            int index = 0;
            int choice;
            while (flag && dogRepository.getVector().size())
            {

                if (index == dogRepository.getVector().size())
                {
                    index = 0;
                }
                std::cout
                    << "Here is dog number " << std::to_string(index + 1) << std::endl;
                dogRepository.displayDog(index);
                displayUserChoice();
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    Dog newDog("", "", 1, "");
                    int dogRepositoryAge = dogRepository.getVector()[index].getAge();
                    std::string dogRepositoryName = dogRepository.getVector()[index].getName();
                    std::string dogRepositoryBreed = dogRepository.getVector()[index].getBreed();
                    std::string dogRepositoryPhotograph = dogRepository.getVector()[index].getPhotograph();

                    newDog.setAge(dogRepositoryAge);
                    newDog.setName(dogRepositoryName);
                    newDog.setBreed(dogRepositoryBreed);
                    newDog.setPhotograph(dogRepositoryPhotograph);

                    adoptionListRepository.addDog(newDog);
                    dogRepository.removeDog(index);

                    std::cout << "You have successfully adopted a dog!" << std::endl;
                    break;
                }
                case 2:
                {
                    std::cout << "Showing you the next dog!" << std::endl;
                    break;
                }
                case 3:
                    std::cout << "Quitting" << std::endl;
                    flag = false;
                    break;
                default:
                    std::cout << "Wrong input, quitting" << std::endl;
                    flag = false;
                    break;
                }
                index++;
            }
            break;
        }
        case 2: // filter and then choose
        {
            std::vector<int> dogList;
            std::string breed;
            int age;

            std::cout << "Input the age for the filter: " << std::endl;
            std::cin >> age;

            std::cout << "Input the breed for the filter: " << std::endl;
            std::cin >> breed;

            dogList = controller.filterDogs(age, breed);

            bool flag = true;
            int index = 0;
            int choice;
            while (flag && dogList.size())
            {

                if (index == dogList.size())
                {
                    index = 0;
                }
                std::cout
                    << "Here is dog number " << std::to_string(index + 1) << std::endl;
                dogRepository.displayDog(dogList[index]);
                displayUserChoice();
                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    Dog newDog("", "", 1, "");
                    int dogRepositoryAge = dogRepository.getVector()[index].getAge();
                    std::string dogRepositoryName = dogRepository.getVector()[index].getName();
                    std::string dogRepositoryBreed = dogRepository.getVector()[index].getBreed();
                    std::string dogRepositoryPhotograph = dogRepository.getVector()[index].getPhotograph();

                    newDog.setAge(dogRepositoryAge);
                    newDog.setName(dogRepositoryName);
                    newDog.setBreed(dogRepositoryBreed);
                    newDog.setPhotograph(dogRepositoryPhotograph);

                    adoptionListRepository.addDog(newDog);
                    dogRepository.removeDog(dogList[index]);
                    dogList.erase(dogList.begin() + index);

                    std::cout << "You have successfully adopted a dog!" << std::endl;
                    break;
                }
                case 2:
                {
                    std::cout << "Showing you the next dog!" << std::endl;
                    break;
                }
                case 3:
                    std::cout << "Quitting" << std::endl;
                    flag = false;
                    break;
                default:
                    std::cout << "Wrong input, quitting" << std::endl;
                    flag = false;
                    break;
                }
                index++;
            }
            break;
        }

        case 3: // display the adoption list
        {
            adoptionListRepository.displayAllDogs();
            break;
        }

        case 4: // quit
            cond = false;
            break;
        default:
            std::cout << "Wrong input, quitting" << std::endl;
            cond = false;
        }
    }

    controller.~Controller();
    dogRepository.~DogRepository();
    adoptionListRepository.~AdoptionListRepository();
}

int main()
{
    DogTests();
    DogRepositoryTests();
    AdoptionListRepositoryTests();
    ControllerTests();

    std::string option;
    std::cout << "Login as User or Administrator" << std::endl;
    std::cin >> option;

    if (option == "Administrator")
    {
        startAdministrator();
    }
    else if (option == "User")
    {
        startUser();
    }
    else
    {
        std::cout << "Wrong input";
    }
}
