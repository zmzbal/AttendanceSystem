#include "Teacher.h"
Teacher::Teacher(const std::string& id, const std::string& name, const std::string& gender, const std::string& position)
    : Person(id, name, gender), position(position) {}

Teacher::Teacher(const Teacher& other)
    : Person(other), position(other.position) {}

// Copy assignment operator
Teacher& Teacher::operator=(const Teacher& other) {
    if (this != &other) {
        Person::operator=(other);
        position = other.position;
    }
    return *this;
}

// Destructor
Teacher::~Teacher() {}

// Accessor function
const std::string& Teacher::getPosition() const { return position; }

// Mutator function
void Teacher::setPosition(const std::string& newPosition) { position = newPosition; }
