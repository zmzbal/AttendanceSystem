#include "Teacher.h"
Teacher::Teacher(unsigned id, const std::string& name,
                 const std::string& gender, const std::string& password,
                 unsigned age, const std::string& position,
                 const std::string& faculty)
    : Person(id, name, gender, password, age),
    position(position), faculty(faculty) {}

Teacher::Teacher(const Teacher& other)
    : Person(other), position(other.position),
    faculty(other.faculty){}

// Copy assignment operator
Teacher& Teacher::operator=(const Teacher& other) {
    if (this != &other) {
        Person::operator=(other);
        position = other.position;
        faculty = other.faculty;
    }
    return *this;
}

// Destructor
Teacher::~Teacher() noexcept {}

// Accessor function
const std::string& Teacher::getPosition() const { return position; }

const std::string& Teacher::getFaculty() const { return faculty; }
// Mutator function
void Teacher::setPosition(const std::string& newPosition) { position = newPosition; }

void Teacher::setFaculty(const std::string &newFaculty) {faculty = newFaculty; }