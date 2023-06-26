#pragma once
#include "Person.h"
#ifndef TEACHER_H
#define TEACHER_H

class Teacher: public Person {
protected:
    std::string position;
    std::string faculty;

public:
    Teacher(unsigned id, const std::string& name,
            const std::string& gender, const std::string& password,
            unsigned age, const std::string& position,
            const std::string& faculty);

    Teacher(const Teacher& other);

    Teacher& operator=(const Teacher& other);
    
    virtual ~Teacher() noexcept;

    const std::string& getPosition() const;

    const std::string& getFaculty() const;

    void setPosition(const std::string& newPosition);

    void setFaculty(const std::string& newFaculty);

};

#endif // !TEACHER_H