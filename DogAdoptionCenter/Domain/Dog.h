#pragma once
#include <string>

class Dog
{
private:
    std::string breed;
    std::string name;
    int age;
    std::string photograph;

public:
    Dog();

    Dog(std::string breed, std::string name, int age, std::string photograph);

    ~Dog();

    // Dog(Dog &dog);

    std::string toString();

    // Gets the breed of the dog
    std::string getBreed();

    // Gets the name of the dog
    std::string getName();

    // Gets the photograph of the dog
    std::string getPhotograph();

    // Gets the age of the dog
    int getAge();

    // Sets the breed of the dog
    void setBreed(std::string breed);

    // Sets the name of the dog
    void setName(std::string name);

    // Sets the photograph of the dog
    void setPhotograph(std::string photograph);

    // Sets the age of the dog
    void setAge(int age);

    // Comparison between 2 dogs
    bool operator==(Dog &dog);

    friend std::ostream &operator<<(std::ostream &os, Dog &dog);
};