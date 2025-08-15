#ifndef __HEADER_H__
#define __HEADER_H__

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <vector>

// �л� �̸� �Է� �Լ�
std::string StudentName(const char* prompt);

// �л� ���� �Է� �Լ�
int GetScore(const char* prompt);

// �л� ����
class Student
{
public:
	std::string name;
	int korean;
	int math;
	int eng;

	Student(std::string name, int korean, int math, int eng);

	void printinfo();

};

#endif // !__HEADER_H__
