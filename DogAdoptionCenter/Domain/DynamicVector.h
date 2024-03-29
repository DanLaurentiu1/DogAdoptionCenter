#pragma once
#include "Dog.h"

class DynamicVector
{ // TODO: remove and update at the vector level
private:
    Dog *elems;
    int size;
    int capacity;

public:
    // default constructor for a DynamicVector
    DynamicVector(int capacity = 10);

    // copy constructor for a DynamicVector
    DynamicVector(const DynamicVector &v);
    ~DynamicVector();

    // assignment operator for a DynamicVector
    DynamicVector operator=(const DynamicVector &v);

    // Adds a dog to the current DynamicVector.
    void add(Dog *element);

    // Deletes a dog from the DynamicVector;
    void remove(int index);

    // Updates a dog in the DynamicVector
    // i: a pointer to a dog
    //    the information of a dog to be updated (all are optional attributes, if not passed to this function the default value is "" for string and 0 for age)
    void update(Dog *element, std::string name, std::string breed, int age, std::string photograph);

    // Finds a dog in the DynamicVector
    // i: a pointer to a dog
    // o: the index of that dog or -1
    int findDog(Dog *element);

    // Displays 1 dog from the DynamicVector
    void displayDog(int index);

    // Displays all dogs from the DynamicVector
    void displayAllDogs();

    /*
    Overloading the subscript operator
    Input: pos - a valid position within the vector.
    Output: a reference to the dog on position pos.
    */
    Dog &operator[](int pos);

    int getSize() const;

    Dog *getElements();

private:
    // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
    void resize(int factor = 2);
};