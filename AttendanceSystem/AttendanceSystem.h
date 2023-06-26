#ifndef ATTENDANCESYSTEM_H
#define ATTENDANCESYSTEM_H

#include <vector>
#include <algorithm> // For sorting
#include <fstream>   // For file operations
#include "Attendance.h"
#include "Teacher.h"
class AttendanceSystem{
private:
    std::vector<Student> students;// ѧ����¼�б�
    std::vector<Attendance> attendances;// ȱ�μ�¼�б�
    std::vector<Course> courses;
    std::vector<Teacher> teachers;
public:
    /*�ļ���ȡ/���溯������Qt�޹�*/
    // ���ļ���ȡ��¼
    bool readRecordsFromFile(const std::string& filename);
    // �����¼���ļ�
    bool saveRecordsToFile(const std::string& filename) const;


    /*û������������ĺ���������Qt*/
    
    // ��ѯѧ����¼������ѧ����¼�б�
    std::vector<Student> queryStudentRecord(unsigned int studentId) const;//ѧ��
    std::vector<Student> queryStudentRecord(const std::string& studentName) const;//����
    // ��ѯȱ�μ�¼������ȱ�μ�¼�б�-�γ�/ѧ��
    std::vector<Attendance> queryAttendance(const std::string& query) const;
    // ͳ�ƿ�����Ϣ
    void calculateAbsenteeism(const std::string& courseName) const;//�γ�
    void calculateAbsenteeismByStudent(const std::string& studentName) const;//ѧ��


    /*�����������,Ϊ�˲���/��QT��������*/

    // ���ѧ����¼
    void addStudentRecord(const Student& student);
    // ���ȱ�μ�¼
    void addAttendanceRecord(const Attendance& attendance);

    // ��ʾ����ѧ����¼
    void displayAllStudentRecords() const;
    // ��ʾ����ȱ�μ�¼
    void displayAllAttendanceRecords() const;

    // �༭ѧ����¼
    void editStudentRecord(unsigned int studentId, const Student& newStudent);
    // �༭ȱ�μ�¼
    void editAttendanceRecord(const std::string& studentName, const std::string& courseName, const Date& date, Attendance::AbsenceType newAbsenceType);

    // ɾ��ѧ����¼
    void deleteStudentRecord(unsigned int studentId);
    // ɾ��ȱ�μ�¼
    void deleteAttendanceRecord(const std::string& studentName, const std::string& courseName, const Date& date);

};
#endif






/*
*��ӹ���ģ�飺
ѧ����¼��ӣ�������ʦ���ѧ����¼������ѧ�š��������Ա����䡢�༶����Ϣ��
ȱ�μ�¼��ӣ�������ʦ���ѧ����ȱ�μ�¼������ȱ�����ڡ��ڼ��ڿΡ��γ����ơ�ѧ��������ȱ�����ͣ��ٵ������ˡ���ٺͿ��Σ���

��ѯ����ģ�飺
ѧ����¼��ѯ������ѧ�š���������Ϣ��ѯ����ӵ�ѧ����¼��
ȱ�μ�¼��ѯ�����ݿγ�����ѧ����������Ϣ��ѯȱ�μ�¼��

��ʾ����ģ�飺
ѧ����¼��ʾ����ʾ��ǰϵͳ������ѧ���ļ�¼��
ȱ�μ�¼��ʾ����ʾ��ǰϵͳ�����е�ȱ�μ�¼��

�༭����ģ�飺
ѧ����¼�༭�����ݲ�ѯ�����ѧ����¼�����޸ġ�
ȱ�μ�¼�༭�����ݲ�ѯ�����ȱ�μ�¼�����޸ġ�

ɾ������ģ�飺
ѧ����¼ɾ����ɾ������ӵ�ѧ����¼��
ȱ�μ�¼ɾ����ɾ������ӵ�ȱ�μ�¼��

ͳ�ƹ���ģ�飺
�γ̿���ͳ�ƣ����γ���ͳ��ѧ�����������
ѧ������ͳ�ƣ�������ͳ����һѧ���Ŀ��������

���湦��ģ�飺
��¼���棺�������¼�����ļ��У��Ա������ȡ��ʹ�á�

��ȡ����ģ�飺
��¼��ȡ�����ļ��ж�ȡ�������Ϣ�������ص�ϵͳ�й��û�ʹ�á�
*/