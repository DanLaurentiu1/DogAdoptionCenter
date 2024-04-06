#include "../Controller/Controller.h"
#include "../Repository/Repository.h"
#include "../Tests/Tests.h"
#include <iostream>
#include <string>

void displayAdministrator()
{
    std::cout << std::endl;
    std::cout << " Welcome to the Dog Adoption Centre! " << std::endl;
    std::cout << "Press 1 to display all the dogs up for adoption" << std::endl;
    std::cout << "Press 2 to adopt a dog" << std::endl;
    std::cout << "Press 3 to update the details of a dog" << std::endl;
    std::cout << "Press 4 to add a new dog for adoption" << std::endl;
    std::cout << "Press 5 to quit" << std::endl;
    std::cout << "-> ";
}

void displayUser()
{
}

void startAdministrator()
{
    std::vector<Dog> vector;
    Repository repository(vector);
    Controller controller(repository);

    bool cond = true;
    while (cond)
    {
        displayAdministrator();
        int option;
        std::cin >> option;
        switch (option)
        {
        case 1: // display all the dogs
            controller.displayDogs();
            break;
        case 2: // adopt a dog
        {
            std::cout << "From this list, choose which dog to adopt " << std::endl;
            controller.displayDogs();

            int index;
            std::cout << "Enter the index of the dog you would like to adopt: " << std::endl;
            std::cin >> index;

            if (index < 0 || index > controller.getRepository().getVector().size())
            {
                std::cout << "There is no dog with that index" << std::endl;
                break;
            }
            controller.removeDog(index);
            break;
        }

        case 3: // update a dog
        {
            std::string breed, name, photograph;
            int age, choice;

            std::cout << "From this list, choose which dog to update " << std::endl;
            controller.displayDogs();

            std::cout << "-> ";
            std::cin >> choice;

            if (choice < 0 || choice > controller.getRepository().getVector().size())
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

            controller.updateDog(choice, breed, name, age, photograph);

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
            controller.addDog(dog);
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
    repository.~Repository();
}

void startUser()
{
}

int main()
{
    DogTests();
    RepositoryTests();
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
