#pragma once
#include "Person.h"
class Student :
public Person
{
private:
    std::string student_class;

public:
    Student(const std::string& id, const std::string& name, 
        const std::string& gender, const std::string& _class);
    Student(const Student& other);

    Student& operator=(const Student& other);

    virtual ~Student();


};

