#pragma once
#include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H
class Student: public Person {
protected:
    std::string student_class;

public:
    Student(const std::string& id, const std::string& name,
        const std::string& gender, const std::string& _class);

    Student(const Student& other);

    Student& operator=(const Student& other);

    virtual ~Student();

    const std::string& getClass() const;

    std::string& setClass(std::string new_class);
};

#endif // !STUDENT_H