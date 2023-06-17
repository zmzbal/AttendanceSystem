#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<string>

class Person {
protected:
    std::string name;
    std::string gender;
    const std::string id;

public:
    // Parameterized constructor
    Person(const std::string& id, const std::string& name, const std::string& gender)
        : id(id), name(name), gender(gender) {}

    // Copy constructor
    Person(const Person& other)
        : id(other.id), name(other.name), gender(other.gender) {}

    // Copy assignment operator
    Person& operator=(const Person& other){
        if (this != &other) {
            //id = other.id;
            name = other.name;
            gender = other.gender;
        }
        return *this;
    }

    // Destructor
    virtual ~Person() {}

    // Accessor functions
    const std::string& getName() const { return name; }
    const std::string& getGender() const { return gender; }
    const std::string& getId() const { return id; }

    // Mutator functions
    void setName(const std::string& newName) { name = newName; }
    void setGender(const std::string& newGender) { gender = newGender; }
    //void setId(const std::string& newId) { id = newId; }

};




#endif