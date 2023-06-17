//
// Created by Zhiyu Zhang on 6/17/23.
//

// Course.h
#pragma once
// Course.h

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    Course(unsigned int id, const std::string& name,
           unsigned int credit, unsigned int preCourse);

    unsigned int getId() const;
    const std::string& getName() const;
    unsigned int getCredit() const;
    unsigned int getPreCourses() const;

private:
    unsigned int id;
    std::string name;
    unsigned int credit;
    unsigned int preCourses;


    static void validateCredit(unsigned int credit);
};

#endif  // COURSE_H
