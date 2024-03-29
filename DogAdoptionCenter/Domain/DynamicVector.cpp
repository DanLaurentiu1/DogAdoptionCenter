#include "DynamicVector.h"
#include <string>
#include <iostream>
DynamicVector::DynamicVector(int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->elems = new Dog[capacity];
}

DynamicVector::DynamicVector(const DynamicVector &v)
{
    this->size = v.size;
    this->capacity = v.capacity;
    this->elems = new Dog[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    // maybe a leak here
    // should free this->elems before changing the pointer to the new vector
}

DynamicVector::~DynamicVector()
{
    delete[] this->elems;
}

DynamicVector DynamicVector::operator=(const DynamicVector &v)
{
    if (this == &v)
        return *this;

    this->size = v.size;
    this->capacity = v.capacity;

    delete[] this->elems;
    this->elems = new Dog[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->elems[i] = v.elems[i];

    return *this;

    // maybe a leak here
    // should free this->elems before changing the pointer to the new vector
}

int DynamicVector::findDog(Dog *element)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->elems[i] == *element)
        {
            return i;
        }
    }
    return -1;
}

void DynamicVector::displayDog(int index)
{
    std::cout << "Dog with index:" << index << "   ";
    std::cout << "Name:" << this->elems[index].getName();
    std::cout << "  Breed:" << this->elems[index].getBreed();
    std::cout << "  Age:" << this->elems[index].getAge();
    std::cout << "  Photograph:" << this->elems[index].getPhotograph() << std::endl;
}

void DynamicVector::displayAllDogs()
{
    for (int i = 0; i < this->getSize(); i++)
    {
        this->displayDog(i);
    }
}

void DynamicVector::add(Dog *element)
{
    int index = findDog(element);

    if (index == -1)
    {
        if (this->size == this->capacity)
            this->resize();
        this->elems[this->size] = *element;
        this->size++;
    }
    else
    {
        std::cout << "This dog alredy exists in the database" << std::endl;
    }
}

void DynamicVector::remove(int index)
{

    if (index != -1)
    {
        for (int i = index; i < this->size - 1; i++)
        {
            this->elems[i] = this->elems[i + 1];
        }
        this->size--;
    }
    else
    {
        std::cout << "This entity does not exist" << std::endl;
    }
}

void DynamicVector::update(Dog *dog, std::string name, std::string breed, int age, std::string photograph)
{
    int index = findDog(dog);

    if (index != -1)
    {
        dog->setName(name);
        dog->setBreed(breed);
        dog->setPhotograph(photograph);
        dog->setAge(age);
    }
    else
    {
        std::cout << "This entity does not exist" << std::endl;
    }
}

void DynamicVector::resize(int factor)
{
    this->capacity *= factor;

    Dog *els = new Dog[this->capacity];
    for (int i = 0; i < this->size; i++)
        els[i] = this->elems[i];

    delete[] this->elems;
    this->elems = els;
}

Dog &DynamicVector::operator[](int pos)
{
    return this->elems[pos];
}

int DynamicVector::getSize() const
{
    return this->size;
}
Dog *DynamicVector::getElements()
{
    return this->elems;
}