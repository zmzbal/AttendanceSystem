#include "Student.h"
Student::Student(unsigned id, const std::string& name,
                 const std::string& gender, const std::string password,
                 unsigned age, const std::string& _class,
                 const std::string major):
                 Person(id, name, gender, password, age),
                 student_class(_class), major(major){}

Student::Student(const Student& other): Person(other),
    student_class(other.student_class), major(other.major){}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Person::operator=(other);
        student_class = other.student_class;
        major = other.major;
    }
    return *this;
}

Student::~Student() noexcept {}

const std::string& Student::getClass() const {
    return student_class;
}

const std::string& Student::getMajor() const {
    return major;
}


void Student::setClass(std::string new_class) {
    student_class = new_class;
}

void Student::setMajor(const std::string &new_major) {
    major = new_major;
}