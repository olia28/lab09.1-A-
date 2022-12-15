// ����������� ���������, ��Ͳ, в-11, ��, �� 09.1, ����� �, ������ 24
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialization { COMPUTER_SCIENCE, IT, MATH_AND_ECONOMICS, PHYSICS_AND_IT, WORK_EDUCATION };

string specializations[]{ "��", "�����������", "��", "Բ", "��" };

struct Student
{
    string surname = "";
    Specialization specialization = COMPUTER_SCIENCE;

    int course = 1, physicsGrade = 1, mathGrade = 1, ITGrade = 1;
};

void CreateStructure(Student* students, const int studentsCount)
{
    int specialization;

    for (int ii = 0; ii < studentsCount; ii++)
    {
        cout << "�������  � " << ii + 1 << ":" << endl;
        cin.get(); cin.sync();

        cout << "1) �������: "; getline(cin, students[ii].surname);
        cout << "2) ����: "; cin >> students[ii].course;
        cout << "3) ������������ (1 - KH, 2 - �����������, 3 - ��, 4 - Բ, 5 - ��): "; cin >> specialization;
        cout << "4) ������ � ������: "; cin >> students[ii].physicsGrade;
        cout << "5) ������ � ����������: "; cin >> students[ii].mathGrade;
        cout << "6) ������ � �����������: "; cin >> students[ii].ITGrade;

        students[ii].specialization = (Specialization)(specialization - 1);
    }
}

void DisplayStructure(Student* students, const int studentsCount)
{
    cout << "\n============================================================================================================"
        << endl;
    cout << "| � |    �������    | ���� | ������������ | ������ � ������ | ������ � ���������� | ������ � ����������� |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------"
        << endl;

    for (int ii = 0; ii < studentsCount; ii++)
    {
        cout << "| " << setw(2) << ii + 1
            << "| " << setw(15) << students[ii].surname
            << "| " << setw(5) << students[ii].course
            << "| " << setw(14) << specializations[students[ii].specialization]
            << "| " << setw(16) << students[ii].physicsGrade
            << "| " << setw(20) << students[ii].mathGrade
            << "| " << setw(21) << students[ii].ITGrade << "|" << endl;
    }

    cout << "============================================================================================================"
        << endl;
}

int GoodGradesCount(Student* students, const int studentsCount)
{
    int goodGradesCount = 0;

    for (int ii = 0; ii < studentsCount; ii++)
    {
        if (students[ii].physicsGrade == 4) goodGradesCount++;
        
        if (students[ii].mathGrade == 4) goodGradesCount++;
        
        if (students[ii].ITGrade == 4) goodGradesCount++;
    }

    return goodGradesCount;
}

float WellDoingPhysicsAndMathStudentsPercent(Student* students, const int studentsCount)
{
    int wellDoingPhysicsStudentsCount = 0;

    for (int ii = 0; ii < studentsCount; ii++)
        if (students[ii].physicsGrade == 5 && students[ii].mathGrade == 5) wellDoingPhysicsStudentsCount++;

    float percent = 100 * static_cast<float>(wellDoingPhysicsStudentsCount) / studentsCount;

    return percent;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int studentsCount;

    cout << "������ ������� ��������: "; cin >> studentsCount;

    Student* students = new Student[studentsCount];

    CreateStructure(students, studentsCount); DisplayStructure(students, studentsCount);

    cout << "\nʳ������ ������ \"�����\" � ������� ��������: " << GoodGradesCount(students, studentsCount)
        << "\n³������ ��������, �� �������� � ������ �� ���������� ������ \"5\": " 
        << WellDoingPhysicsAndMathStudentsPercent(students, studentsCount) << "%" << endl;
}
