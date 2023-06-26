#include <iostream>
#include <vector>


// ���ѧ����¼
bool AttendanceSystem::addStudentRecord(const Student& student) {
    // ���ѧ���Ƿ�Ψһ
    if (isStudentIdExists(student.getStudentId())) {
        return false; // ѧ���Ѵ��ڣ����ʧ��
    }

    students.push_back(student);
    return true; // ��ӳɹ�
}

// ���ȱ�μ�¼
void AttendanceSystem::addAttendance(const Attendance& record) {
    Attendances.push_back(record);
}

// ��ѯѧ����¼
std::vector<Student> AttendanceSystem::queryStudentRecord(const std::string& query) {
    std::vector<Student> results;

    for (const auto& student : students) {
        // ����ѧ�Ż��������в�ѯ
        if (student.getStudentId() == query || student.getStudentName() == query) {
            results.push_back(student);
        }
    }

    return results;
}

// ��ѯȱ�μ�¼
std::vector<Attendance> AttendanceSystem::queryAttendance(const std::string& query) {
    std::vector<Attendance> results;

    for (const auto& record : Attendances) {
        // ���ݿγ�����ѧ���������в�ѯ
        if (record.getCourse() == query || record.getStudent() == query) {
            results.push_back(record);
        }
    }

    return results;
}

// ��ʾ����ѧ����¼
void AttendanceSystem::displayAllStudentRecords() {
    for (const auto& student : students) {
        displayStudentRecord(student);
    }
}

// ��ʾ����ȱ�μ�¼
void AttendanceSystem::displayAllAttendances() {
    for (const auto& record : Attendances) {
        displayAttendance(record);
    }
}

// �༭ѧ����¼
bool AttendanceSystem::editStudentRecord(const std::string& studentId, const Student& newStudent) {
    auto it = findStudentById(studentId);

    if (it != students.end()) {
        // ���ѧ���Ƿ�Ψһ���ų���ǰ��¼��
        if (studentId != newStudent.getStudentId() && isStudentIdExists(newStudent.getStudentId())) {
            return false; // ѧ���Ѵ��ڣ��༭ʧ��
        }

        *it = newStudent;
        return true; // �༭�ɹ�
    }

    return false; // δ�ҵ���¼���༭ʧ��
}

// �༭ȱ�μ�¼
void AttendanceSystem::editAttendance(const Attendance& oldRecord, const Attendance& newRecord) {
    auto it = findAttendance(oldRecord);

    if (it != Attendances.end()) {
        *it = newRecord;
    }
}

// ɾ��ѧ����¼
void AttendanceSystem::deleteStudentRecord(const std::string& studentId) {
    auto it = findStudentById(studentId);

    if (it != students.end()) {
        students.erase(it);
    }
}

// ɾ��ȱ�μ�¼
void AttendanceSystem::deleteAttendance(const Attendance& record) {
    auto it = findAttendance(record);

    if (it != Attendances.end()) {
        Attendances.erase(it);
    }
}

// ͳ�ƿγ̿������
std::vector<std::pair<std::string, int>> AttendanceSystem::countCourseAbsences() {
    std::vector<std::pair<std::string, int>> courseCounts;

    for (const auto& record : Attendances) {
        // ���ݿγ���ͳ�ƿ��δ���
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

    // �����δ�����������
    std::sort(courseCounts.begin(), courseCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    return courseCounts;
}

// ͳ��ѧ���������
std::vector<std::pair<std::string, int>> AttendanceSystem::countStudentAbsences() {
    std::vector<std::pair<std::string, int>> studentCounts;

    for (const auto& record : Attendances) {
        // ����ѧ������ͳ�ƿ��δ���
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

    // �����δ�����������
    std::sort(studentCounts.begin(), studentCounts.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    return studentCounts;
}





// ���ѧ���Ƿ����
bool AttendanceSystem::isStudentIdExists(const std::string& studentId) {
    auto it = findStudentById(studentId);
    return it != students.end();
}

// ����ѧ�Ų���ѧ����¼
std::vector<Student>::iterator AttendanceSystem::findStudentById(const std::string& studentId) {
    return std::find_if(students.begin(), students.end(), [&](const auto& student) {
        return student.getStudentId() == studentId;
        });
}

// ����ȱ�μ�¼
std::vector<Attendance>::iterator AttendanceSystem::findAttendance(const Attendance& record) {
    return std::find(Attendances.begin(), Attendances.end(), record);
}

// ��ʾѧ����¼
void AttendanceSystem::displayStudentRecord(const Student& student) {
    // ��Qt������ʵ����ʾѧ����¼���߼�
}

// ��ʾȱ�μ�¼
void AttendanceSystem::displayAttendance(const Attendance& record) {
    // ��Qt������ʵ����ʾȱ�μ�¼���߼�
}

