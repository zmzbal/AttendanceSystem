#pragma once
#include "Person.h"
#ifndef TEACHER_H
#define TEACHER_H

class Teacher: public Person {

protected:
    std::string position;

public:
    Teacher(const std::string& id, const std::string& name, 
        const std::string& gender, const std::string& position);

    Teacher(const Teacher& other);

    Teacher& operator=(const Teacher& other);
    
    virtual ~Teacher();

    const std::string& getPosition() const;

    void setPosition(const std::string& newPosition);


};

#endif // !TEACHER_H