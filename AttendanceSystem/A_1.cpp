#include <iostream>
#include <vector>


// 添加学生记录
bool AttendanceSystem::addStudentRecord(const Student& student) {
    // 检查学号是否唯一
    if (isStudentIdExists(student.getStudentId())) {
        return false; // 学号已存在，添加失败
    }

    students.push_back(student);
    return true; // 添加成功
}

// 添加缺课记录
void AttendanceSystem::addAttendance(const Attendance& record) {
    Attendances.push_back(record);
}

// 查询学生记录
std::vector<Student> AttendanceSystem::queryStudentRecord(const std::string& query) {
    std::vector<Student> results;

    for (const auto& student : students) {
        // 根据学号或姓名进行查询
        if (student.getStudentId() == query || student.getStudentName() == query) {
            results.push_back(student);
        }
    }

    return results;
}

// 查询缺课记录
std::vector<Attendance> AttendanceSystem::queryAttendance(const std::string& query) {
    std::vector<Attendance> results;

    for (const auto& record : Attendances) {
        // 根据课程名或学生姓名进行查询
        if (record.getCourse() == query || record.getStudent() == query) {
            results.push_back(record);
        }
    }

    return results;
}

// 显示所有学生记录
void AttendanceSystem::displayAllStudentRecords() {
    for (const auto& student : students) {
        displayStudentRecord(student);
    }
}

// 显示所有缺课记录
void AttendanceSystem::displayAllAttendances() {
    for (const auto& record : Attendances) {
        displayAttendance(record);
    }
}

// 编辑学生记录
bool AttendanceSystem::editStudentRecord(const std::string& studentId, const Student& newStudent) {
    auto it = findStudentById(studentId);

    if (it != students.end()) {
        // 检查学号是否唯一（排除当前记录）
        if (studentId != newStudent.getStudentId() && isStudentIdExists(newStudent.getStudentId())) {
            return false; // 学号已存在，编辑失败
        }

        *it = newStudent;
        return true; // 编辑成功
    }

    return false; // 未找到记录，编辑失败
}

// 编辑缺课记录
void AttendanceSystem::editAttendance(const Attendance& oldRecord, const Attendance& newRecord) {
    auto it = findAttendance(oldRecord);

    if (it != Attendances.end()) {
        *it = newRecord;
    }
}

// 删除学生记录
void AttendanceSystem::deleteStudentRecord(const std::string& studentId) {
    auto it = findStudentById(studentId);

    if (it != students.end()) {
        students.erase(it);
    }
}

// 删除缺课记录
void AttendanceSystem::deleteAttendance(const Attendance& record) {
    auto it = findAttendance(record);

    if (it != Attendances.end()) {
        Attendances.erase(it);
    }
}

// 统计课程旷课情况
std::vector<std::pair<std::string, int>> AttendanceSystem::countCourseAbsences() {
    std::vector<std::pair<std::string, int>> courseCounts;

    for (const auto& record : Attendances) {
        // 根据课程名统计旷课次数
        auto it = std::find_if(courseCounts.begin(), courseCounts.end(), [&](const auto& count) {
            return count.first == record.getCourse();
            });

        if (it != courseCounts.end()) {
            it->second++;
        }
        else {
            courseCounts.emplace_back(record.getCourse(), 1);
        }
    }

    // 按旷课次数降序排序
    std::sort(courseCounts.begin(), courseCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    return courseCounts;
}

// 统计学生旷课情况
std::vector<std::pair<std::string, int>> AttendanceSystem::countStudentAbsences() {
    std::vector<std::pair<std::string, int>> studentCounts;

    for (const auto& record : Attendances) {
        // 根据学生姓名统计旷课次数
        auto it = std::find_if(studentCounts.begin(), studentCounts.end(), [&](const auto& count) {
            return count.first == record.getStudent();
            });

        if (it != studentCounts.end()) {
            it->second++;
        }
        else {
            studentCounts.emplace_back(record.getStudent(), 1);
        }
    }

    // 按旷课次数降序排序
    std::sort(studentCounts.begin(), studentCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    return studentCounts;
}





// 检查学号是否存在
bool AttendanceSystem::isStudentIdExists(const std::string& studentId) {
    auto it = findStudentById(studentId);
    return it != students.end();
}

// 根据学号查找学生记录
std::vector<Student>::iterator AttendanceSystem::findStudentById(const std::string& studentId) {
    return std::find_if(students.begin(), students.end(), [&](const auto& student) {
        return student.getStudentId() == studentId;
        });
}

// 查找缺课记录
std::vector<Attendance>::iterator AttendanceSystem::findAttendance(const Attendance& record) {
    return std::find(Attendances.begin(), Attendances.end(), record);
}

// 显示学生记录
void AttendanceSystem::displayStudentRecord(const Student& student) {
    // 在Qt界面中实现显示学生记录的逻辑
}

// 显示缺课记录
void AttendanceSystem::displayAttendance(const Attendance& record) {
    // 在Qt界面中实现显示缺课记录的逻辑
}

