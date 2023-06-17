#include "Student.h"
Student::Student(const std::string& id, const std::string& name,
    const std::string& gender, const std::string& _class):Person(id, name, gender), 
    student_class(_class){}

Student::Student(const Student& other): Person(other),
    student_class(other.student_class){}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Person::operator=(other);
        student_class = other.student_class;
    }
    return *this;
}

const std::string& Student::getClass() const {
    return student_class;
}

std::string& Student::setClass(std::string new_class) {
    student_class = new_class;
}