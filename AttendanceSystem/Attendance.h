//
// Created by Zhiyu Zhang on 6/20/23.
//

#ifndef ATTENDANCESYSTEM_ATTENDANCE_H
#define ATTENDANCESYSTEM_ATTENDANCE_H
#include "Student.h"
#include "Course.h"
#include "Date.h"
class Attendance {
private:
    Student student;
    Course course;
    AbsenceType type;
    Date date;
public:
    enum AbsenceType {
        Sick,  //病
        Leave, //请假
        Unexcused //无故缺席
    };
    Attendance(Student student1, Course course1, AbsenceType type1,
               Date date1);
    const Student& getStudent() const;
    const Course& getCourse() const;
    const AbsenceType getAbsenceType() const;
    const Date& getDate() const;


};

#endif //ATTENDANCESYSTEM_ATTENDANCE_H
