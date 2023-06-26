#include "AttendanceSystem.h"

/*相关辅助函数，用于内部调用，与Qt无关*/
//解析函数，用于用于读取文件时分析字符串，并用数据创建相关的类
template<typename T>
T AttendanceSystem::parseRecord(const std::string& line, const std::string& recordType) const {
    size_t pos = line.find(":") + 1;
    std::string recordData = line.substr(pos);
    return T::fromString(recordData);
}

template<typename T>
std::string AttendanceSystem::toString() const {
    std::ostringstream oss;
    for (const T& record : records) {
        oss << record.toString() << std::endl;
    }
    return oss.str();
}

//一个循环，执行保存记录的操作
template<typename T>
void AttendanceSystem::saveRecords(std::ofstream& outFile, const std::vector<T>& records, const std::string& recordType) const {
    for (const T& record : records) {
        outFile << recordType << ": " << record.toString() << std::endl;
    }
}

template<typename T>
T T::fromString(const std::string& recordData) {
    std::istringstream iss(recordData);
    // 解析并提取 recordData 字符串中的数据
    // 使用提取的数据创建并返回类的新实例
}

template<typename T>
std::string T::toString() const {
    std::ostringstream oss;
    // 将类数据转换为字符串表示形式
    // 将数据附加到 oss 字符串流，并将其作为字符串返回
}



/*文件读取/保存函数，与Qt无关*/

// 从文件中读取记录
bool AttendanceSystem::readRecordsFromFile(const std::string& filename) {
    std::ifstream inFile(filename);

    if (inFile.is_open()) {
        std::string line;

        while (std::getline(inFile, line)) {
            if (line.find("Student:") != std::string::npos) {
                Student student = parseRecord<Student>(line, "Student");  // 解析学生记录
                students.push_back(student);
            }
            else if (line.find("Teacher:") != std::string::npos) {
                Teacher teacher = parseRecord<Teacher>(line, "Teacher");  // 解析教师记录
                teachers.push_back(teacher);
            }
            else if (line.find("Course:") != std::string::npos) {
                Course course = parseRecord<Course>(line, "Course");     // 解析课程记录
                courses.push_back(course);
            }
            else if (line.find("Attendance:") != std::string::npos) {
                Attendance attendance = parseRecord<Attendance>(line, "Attendance");  // 解析考勤记录
                attendances.push_back(attendance);
            }
        }

        inFile.close();
        return true;
    }
    return false;
}

// 保存记录到文件
bool AttendanceSystem::saveRecordsToFile(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        saveRecords<Student>(outFile, students, "Student");  // 保存学生记录
        saveRecords<Teacher>(outFile, teachers, "Teacher");  // 保存教师记录
        saveRecords<Course>(outFile, courses, "Course");     // 保存课程记录
        saveRecords<Attendance>(outFile, attendances, "Attendance");  // 保存考勤记录

        outFile.close();
        return true;
    }
    return false;
}



/*没有输入输出流的函数，适配Qt*/




// 查询学生记录，返回学生记录列表-学号
std::vector<Student> AttendanceSystem::queryStudentRecord(unsigned int studentId) const {
    std::vector<Student> results;
    for (const Student& student : students) {
        if (student.getId() == studentId) {
            results.push_back(student);
        }
    }
    return results;
}
// 查询学生记录，返回学生记录列表-姓名
std::vector<Student> AttendanceSystem::queryStudentRecord(const std::string& studentName) const {
    std::vector<Student> results;
    for (const Student& student : students) {
        if (student.getName() == studentName) {
            results.push_back(student);
        }
    }
    return results;
}

// 查询缺课记录，返回缺课记录列表-课程/学生
std::vector<Attendance> AttendanceSystem::queryAttendance(const std::string& query) const{
    std::vector<Attendance> results;
    for (const Attendance& record : attendances) {
        // 根据课程名或学生姓名进行查询
        if (record.getCourse().getName() == query || record.getStudent().getName() == query) {
            results.push_back(record);
        }
    }
    return results;
}

void AttendanceSystem::calculateAbsenteeism(const std::string& courseName) const {
    int totalAbsenteeism = 0;

    for (const Attendance& attendance : attendances) {
        if (attendance.getCourse().getName() == courseName && attendance.getAbsenceType() == Attendance::Unexcused) {
            totalAbsenteeism++;
        }
    }

    std::cout << "Total Absenteeism for Course " << courseName << ": " << totalAbsenteeism << std::endl;
}

void AttendanceSystem::calculateAbsenteeismByStudent(const std::string& studentName) const {
    int totalAbsenteeism = 0;

    for (const Attendance& attendance : attendances) {
        if (attendance.getStudent().getName() == studentName && attendance.getAbsenceType() == Attendance::Unexcused) {
            totalAbsenteeism++;
        }
    }

    std::cout << "Total Absenteeism for Student " << studentName << ": " << totalAbsenteeism << std::endl;
}



/*有输入输出流,为了测试/非QT化地运行*/
// 添加学生记录
void AttendanceSystem::addStudentRecord(const Student& student) {
    // 检查学号是否唯一
    for (const Student& existingStudent : students) {
        if (existingStudent.getId() == student.getId()) {
            std::cout << "Error: Duplicate student ID. Record not added." << std::endl;
            return;
        }
    }

    students.push_back(student);
    std::cout << "Student record added successfully." << std::endl;
}
// 添加缺课记录
void AttendanceSystem::addAttendanceRecord(const Attendance& attendance) {
    attendances.push_back(attendance);
    std::cout << "Attendance record added successfully." << std::endl;
}

void AttendanceSystem::displayAllStudentRecords() const {
    std::cout << "All Student Records:" << std::endl;
    for (const Student& student : students) {
        std::cout << "ID: " << student.getId() << ", Name: " << student.getName() << std::endl;
    }
}

void AttendanceSystem::displayAllAttendanceRecords() const {
    std::cout << "All Attendance Records:" << std::endl;
    for (const Attendance& attendance : attendances) {
        std::cout << "Student Name: " << attendance.getStudent().getName() << ", Course Name: " << attendance.getCourse().getName() << std::endl;
    }
}

void AttendanceSystem::editStudentRecord(unsigned int studentId, const Student& newStudent) {
    for (Student& student : students) {
        if (student.getId() == studentId) {
            student = newStudent;
            std::cout << "Record updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Error: Student record not found." << std::endl;
}

void AttendanceSystem::editAttendanceRecord(const std::string& studentName, const std::string& courseName, const Date& date, Attendance::AbsenceType newAbsenceType) {
    for (Attendance& attendance : attendances) {
        if (attendance.getStudent().getName() == studentName && attendance.getCourse().getName() == courseName && attendance.getDate() == date) {
            attendance.setAbsenceType(newAbsenceType);
            std::cout << "Attendance record updated successfully." << std::endl;
            return;
        }
    }

    std::cout << "Error: Attendance record not found." << std::endl;
}

void AttendanceSystem::deleteStudentRecord(unsigned int studentId) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == studentId) {
            students.erase(it);
            std::cout << "Student record deleted successfully." << std::endl;
            return;
        }
    }

    std::cout << "Error: Student record not found." << std::endl;
}

void AttendanceSystem::deleteAttendanceRecord(const std::string& studentName, const std::string& courseName, const Date& date) {
    for (auto it = attendances.begin(); it != attendances.end(); ++it) {
        if (it->getStudent().getName() == studentName && it->getCourse().getName() == courseName && it->getDate() == date) {
            attendances.erase(it);
            std::cout << "Attendance record deleted successfully." << std::endl;
            return;
        }
    }

    std::cout << "Error: Attendance record not found." << std::endl;
}