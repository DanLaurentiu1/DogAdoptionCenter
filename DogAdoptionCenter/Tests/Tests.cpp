#include "Tests.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include <vector>

void DogTests()
{
    std::cout << "Testing the Dog class" << std::endl;

    // Here I am testing if the Dog attributes are correct and consistent
    // Testing the getters and setters
    Dog dogStack("breed1", "name1", 1, "photo1");
    Dog *dogHeap = new Dog("breed2", "name2", 2, "photo2");
    Dog *dogUnk = new Dog();
    Dog *dogComparison1 = new Dog("1", "1", 1, "1");
    Dog *dogComparison2 = new Dog("1", "1", 1, "1");
    assert(dogStack.getName() == "name1");
    assert(dogStack.getBreed() == "breed1");
    assert(dogStack.getAge() == 1);
    assert(dogStack.getPhotograph() == "photo1");

    assert(dogHeap->getName() == "name2");
    assert(dogHeap->getBreed() == "breed2");
    assert(dogHeap->getAge() == 2);
    assert(dogHeap->getPhotograph() == "photo2");

    assert(dogUnk->getName() == "unknown");
    assert(dogUnk->getBreed() == "unknown");
    assert(dogUnk->getAge() == 0);
    assert(dogUnk->getPhotograph() == "unknown");

    dogHeap->setAge(1);
    dogHeap->setPhotograph("1");
    dogHeap->setBreed("1");
    dogHeap->setName("1");

    assert(dogHeap->getName() == "1");
    assert(dogHeap->getBreed() == "1");
    assert(dogHeap->getAge() == 1);
    assert(dogHeap->getPhotograph() == "1");

    // Here I am testing if the comparsion between 2 dogs is working
    bool comparison;
    if (*dogComparison2 == *dogComparison1)
    {
        comparison = true;
    }
    else
    {
        comparison = false;
    }

    assert(comparison == true);

    dogComparison1->~Dog();
    dogComparison2->~Dog();
    dogHeap->~Dog();
    dogUnk->~Dog();

    std::cout << "Test done, no errors!" << std::endl;
    std::cout << std::endl;
}

void DogRepositoryTests()
{
    std::cout << "Testing the DogRepository class" << std::endl;
    std::vector<Dog> vector;
    DogRepository repo(vector);

    // Testing the add function
    Dog d1("a", "a", 1, "a");
    repo.addDog(d1);

    // Testing the getter
    assert(repo.getVector()[10] == d1);

    // Testing the remove function
    repo.removeDog(10);
    assert(repo.getVector().size() == 10);

    // Testing the update function
    repo.updateDog(0, "a", "a", 1, "a");

    // Testing the getter
    assert(repo.getVector()[0].getAge() == 1);
    assert(repo.getVector()[0].getName() == "a");
    assert(repo.getVector()[0].getBreed() == "a");
    assert(repo.getVector()[0].getPhotograph() == "a");

    // Testing to see if I add another dog with the same attributes, then it won't add it
    Dog d2("a", "a", 1, "a");
    repo.addDog(d2);
    assert(repo.getVector().size() == 10);

    std::cout << "Test done, no errors!" << std::endl;
    std::cout << std::endl;
}
void AdoptionListRepositoryTests()
{
    std::cout << "Testing the AdoptionListRepository class" << std::endl;
    std::vector<Dog> vector;
    AdoptionListRepository repo(vector);

    // Testing the add function
    Dog d1("a", "a", 1, "a");
    repo.addDog(d1);

    // Testing the getter
    assert(repo.getVector()[0] == d1);
    assert(repo.getVector().size() == 1);

    // Testing to see if I add another dog with the same attributes, then it won't add it
    Dog d2("a", "a", 1, "a");
    repo.addDog(d2);
    assert(repo.getVector().size() == 1);

    std::cout << "Test done, no errors!" << std::endl;
    std::cout << std::endl;
}
void ControllerTests()
{
    std::cout << "Testing the Controller class" << std::endl;

    std::vector<Dog> vector;
    std::vector<Dog> vector1;
    std::vector<Dog> vector2;

    DogRepository repo(vector);
    Dog dog1("poodle", "a", 1, "A");
    Dog dog2("poodle", "a", 12, "asd");
    Dog dog3("a", "a", 1, "a");
    Dog dog4("a", "a", 2, "a");

    repo.addDog(dog1);
    repo.addDog(dog2);
    repo.addDog(dog3);
    repo.addDog(dog4);

    Controller controller(repo, 0);
    vector1.push_back(dog1);
    vector1.push_back(dog2);
    vector2.push_back(dog1);

    // Testing the string validation and the filter function
    assert(controller.validateInputString("asdasd") == true);
    assert(controller.validateInputString("as12sd") == false);
    assert(controller.validateInputString("as dasd") == false);
    assert(controller.filterDogs(20, "poodle").size() == vector1.size());
    assert(controller.filterDogs(5, "poodle").size() == vector2.size());

    std::cout << "Test done, no errors!" << std::endl;
    std::cout << std::endl;
}