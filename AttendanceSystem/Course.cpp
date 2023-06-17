//
// Created by Zhiyu Zhang on 6/17/23.
//

#include "Course.h"
// Course.cpp

Course::Course(unsigned int id, const std::string& name,
               unsigned int credit, unsigned preCourses)
        : id(id), name(name), credit(credit), preCourses(preCourses) {
    validateCredit(credit);
}

unsigned int Course::getId() const {
    return id;
}

const std::string& Course::getName() const {
    return name;
}

unsigned int Course::getCredit() const {
    return credit;
}

unsigned Course::getPreCourses() const {
    return preCourses;
}

void Course::validateCredit(unsigned int credit) {
    if (credit < 1 || credit > 20) {
        throw std::invalid_argument("Credit must be between 1 and 20.");
    }
}