#include "Tests.h"
#include <assert.h>
#include <string.h>
#include <iostream>

void DogTests()
{
    std::cout << "Testing the Dog class" << std::endl;

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

void VectorTests()
{
    std::cout << "Testing the DynamicVector class" << std::endl;

    DynamicVector *vector = new DynamicVector(2);
    Dog *dog1 = new Dog("1", "1", 1, "1");
    Dog *dog2 = new Dog("2", "1", 1, "1");
    Dog *dog3 = new Dog("3", "1", 1, "1");
    assert(vector->getSize() == 0);

    vector->add(dog1);
    assert(vector->getSize() == 1);

    vector->add(dog2);
    vector->add(dog3);
    assert(vector->getSize() == 3);

    vector->remove(0);
    assert(vector->getSize() == 2);

    vector->update(dog2, "NEWNAMe", "breedname", 123, "photolink");

    /* NEED HELP WITH THIS
        int indexOfDog = vector->findDog(dog2);
        assert(indexOfDog == 0);


        int indexOfDogError = vector->findDog(dog1);
        assert(indexOfDogError == -1);
    */
    vector->~DynamicVector();
    dog1->~Dog();
    dog2->~Dog();
    dog3->~Dog();

    std::cout << "Test done, no errors!" << std::endl;
    std::cout << std::endl;
}
void RepositoryTests()
{
}

void ControllerTests()
{
}