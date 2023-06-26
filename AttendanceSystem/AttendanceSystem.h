#ifndef ATTENDANCESYSTEM_H
#define ATTENDANCESYSTEM_H

#include <vector>
#include <algorithm> // For sorting
#include <fstream>   // For file operations
#include "Attendance.h"
#include "Teacher.h"
class AttendanceSystem{
private:
    std::vector<Student> students;// 学生记录列表
    std::vector<Attendance> attendances;// 缺课记录列表
    std::vector<Course> courses;
    std::vector<Teacher> teachers;
public:
    /*文件读取/保存函数，与Qt无关*/
    // 从文件读取记录
    bool readRecordsFromFile(const std::string& filename);
    // 保存记录到文件
    bool saveRecordsToFile(const std::string& filename) const;


    /*没有输入输出流的函数，适配Qt*/
    
    // 查询学生记录，返回学生记录列表
    std::vector<Student> queryStudentRecord(unsigned int studentId) const;//学号
    std::vector<Student> queryStudentRecord(const std::string& studentName) const;//姓名
    // 查询缺课记录，返回缺课记录列表-课程/学生
    std::vector<Attendance> queryAttendance(const std::string& query) const;
    // 统计旷课信息
    void calculateAbsenteeism(const std::string& courseName) const;//课程
    void calculateAbsenteeismByStudent(const std::string& studentName) const;//学生


    /*有输入输出流,为了测试/非QT化地运行*/

    // 添加学生记录
    void addStudentRecord(const Student& student);
    // 添加缺课记录
    void addAttendanceRecord(const Attendance& attendance);

    // 显示所有学生记录
    void displayAllStudentRecords() const;
    // 显示所有缺课记录
    void displayAllAttendanceRecords() const;

    // 编辑学生记录
    void editStudentRecord(unsigned int studentId, const Student& newStudent);
    // 编辑缺课记录
    void editAttendanceRecord(const std::string& studentName, const std::string& courseName, const Date& date, Attendance::AbsenceType newAbsenceType);

    // 删除学生记录
    void deleteStudentRecord(unsigned int studentId);
    // 删除缺课记录
    void deleteAttendanceRecord(const std::string& studentName, const std::string& courseName, const Date& date);

};
#endif






/*
*添加功能模块：
学生记录添加：允许老师添加学生记录，包括学号、姓名、性别、年龄、班级等信息。
缺课记录添加：允许老师添加学生的缺课记录，包括缺课日期、第几节课、课程名称、学生姓名、缺课类型（迟到、早退、请假和旷课）。

查询功能模块：
学生记录查询：根据学号、姓名等信息查询已添加的学生记录。
缺课记录查询：根据课程名、学生姓名等信息查询缺课记录。

显示功能模块：
学生记录显示：显示当前系统中所有学生的记录。
缺课记录显示：显示当前系统中所有的缺课记录。

编辑功能模块：
学生记录编辑：根据查询结果对学生记录进行修改。
缺课记录编辑：根据查询结果对缺课记录进行修改。

删除功能模块：
学生记录删除：删除已添加的学生记录。
缺课记录删除：删除已添加的缺课记录。

统计功能模块：
课程旷课统计：按课程名统计学生旷课情况。
学生旷课统计：按姓名统计任一学生的旷课情况。

保存功能模块：
记录保存：将各类记录存入文件中，以便后续读取和使用。

读取功能模块：
记录读取：从文件中读取保存的信息，并加载到系统中供用户使用。
*/