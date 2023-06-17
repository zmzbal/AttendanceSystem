#pragma once
#include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H
class Student: public Person {
protected:
    std::string student_class;
    std::string major;
public:
    Student(unsigned id, const std::string& name,
        const std::string& gender, const std::string password,
        unsigned age, const std::string& _class,
        const std::string major);

    Student(const Student& other);

    Student& operator=(const Student& other);

    virtual ~Student();

    const std::string& getClass() const;
    const std::string& getMajor() const;


    void setClass(const std::string& new_class);
    void setMajor(const std::string& new_major);
};

#endif // !STUDENT_H