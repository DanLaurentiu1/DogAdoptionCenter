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
    Validator validator;
    std::vector<Dog> vector;
    DogRepository repository(vector, "../TextFiles/dogRepository.txt");
    Controller controller(repository, -1, validator);

    bool cond = true;
    while (cond)
    {
        displayAdministrator();
        std::string optionTemp;
        std::cin >> optionTemp;

        controller.validateInteger(optionTemp);

        int option = std::stoi(optionTemp);

        switch (option)
        {
        case 1: // display all the dogs
            controller.DogRepository_displayDogs();
            break;
        case 2: // adopt a dog
        {
            std::cout << "From this list, choose which dog to adopt " << std::endl;
            controller.DogRepository_displayDogs();

            std::cout
                << "Enter the index of the dog you would like to adopt: " << std::endl;
            std::string indexTemp;
            std::cin >> indexTemp;

            controller.validateInteger(indexTemp);
            int index = std::stoi(indexTemp);

            if (index < 0 || index >= controller.getDogRepositoryVector().size())
            {
                throw IndexOutOfBoundsException("Index is out of bounds");
            }
            controller.DogRepository_removeDog(index);
            break;
        }

        case 3: // update a dog
        {
            std::string breed, name, photograph, age, choiceTemp;
            int choice;

            std::cout << "From this list, choose which dog to update " << std::endl;
            controller.DogRepository_displayDogs();

            std::cout << "-> ";
            std::cin >> choiceTemp;
            controller.validateInteger(choiceTemp);
            choice = std::stoi(choiceTemp);

            if (choice < 0 || choice >= controller.getDogRepositoryVector().size())
            {
                throw IndexOutOfBoundsException("Index is out of bounds");
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

            controller.validateInputDogAttributes(breed, name, age, photograph);
            controller.DogRepository_updateDog(choice, breed, name, std::stoi(age), photograph);

            break;
        }

        case 4: // add a dog
        {
            std::string breed, name, photograph, age;

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

            controller.validateInputDogAttributes(breed, name, age, photograph);

            Dog dog(breed, name, std::stoi(age), photograph);
            controller.DogRepository_addDog(dog);
            break;
        }
        case 5: // quit
            cond = false;
            break;
        default:
            throw WrongInputException("There is no option with that index");
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
    Validator validator;
    AdoptionListRepository adoptionListRepository(adoptionListVector, "../TextFiles/adoptionListRepository.txt");
    DogRepository dogRepository(dogVector, "../TextFiles/dogRepository.txt");
    Controller controller(dogRepository, adoptionListRepository, validator);

    bool cond = true;
    while (cond)
    {
        displayUser();
        std::string optionTemp;
        std::cin >> optionTemp;
        controller.validateInteger(optionTemp);
        int option = std::stoi(optionTemp);
        switch (option)
        {
        case 1:
        { // choose dogs to adopt
            bool flag = true;
            int index = 0;
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
                std::string choiceTemp;
                std::cin >> choiceTemp;
                controller.validateInteger(choiceTemp);
                int choice = std::stoi(choiceTemp);

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
                    index++;
                    break;
                }
                case 3:
                    std::cout << "Quitting" << std::endl;
                    flag = false;
                    break;
                default:
                    throw WrongInputException("There is no option with that index");
                    flag = false;
                    break;
                }
            }
            break;
        }
        case 2: // filter and then choose
        {
            std::vector<int> dogList;
            std::string breed, ageTemp;
            int age;

            std::cout << "Input the age for the filter: " << std::endl;
            std::cin >> ageTemp;

            controller.validateInteger(ageTemp);
            age = std::stoi(ageTemp);

            std::cout << "Input the breed for the filter: " << std::endl;
            std::cin >> breed;

            controller.validateInputDogAttributes(breed);
            dogList = controller.filterDogs(age, breed);

            bool flag = true;
            int index = 0;
            while (flag && dogList.size() && dogRepository.getVector().size())
            {

                if (index == dogList.size())
                {
                    index = 0;
                }
                std::cout
                    << "Here is dog number " << std::to_string(index + 1) << std::endl;
                dogRepository.displayDog(dogList[index]);
                displayUserChoice();
                std::string choiceTemp;
                std::cin >> choiceTemp;

                controller.validateInteger(choiceTemp);
                int choice = std::stoi(choiceTemp);

                switch (choice)
                {
                case 1:
                {
                    int dogRepositoryAge = dogRepository.getVector()[dogList[index]].getAge();
                    std::string dogRepositoryName = dogRepository.getVector()[dogList[index]].getName();
                    std::string dogRepositoryBreed = dogRepository.getVector()[dogList[index]].getBreed();
                    std::string dogRepositoryPhotograph = dogRepository.getVector()[dogList[index]].getPhotograph();

                    Dog newDog(dogRepositoryBreed, dogRepositoryName, dogRepositoryAge, dogRepositoryPhotograph);

                    std::cout << newDog << std::endl;
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
                    throw WrongInputException("There is no option with that index");
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
            throw WrongInputException("There is no option with that index");
            cond = false;
        }
    }

    controller.~Controller();
    dogRepository.~DogRepository();
    adoptionListRepository.~AdoptionListRepository();
}

int main()
{
    // DogTests();
    // DogRepositoryTests();
    // AdoptionListRepositoryTests();
    // ControllerTests();

    std::string option;
    std::cout << "Login as User or Administrator" << std::endl;
    std::cin >> option;
    try
    {
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
            throw WrongInputException("There is no option with that index");
        }
    }
    catch (WrongInputException e)
    {
        std::cerr << e.getMessage() << '\n';
    }
    catch (DogDoesNotExistException e)
    {
        std::cerr << e.getMessage() << '\n';
    }
    catch (DogDuplicateException e)
    {
        std::cerr << e.getMessage() << '\n';
    }
    catch (IndexOutOfBoundsException e)
    {
        std::cerr << e.getMessage() << '\n';
    }
}
