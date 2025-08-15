#ifndef __HEADER_H__
#define __HEADER_H__

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <vector>

// 학생 이름 입력 함수
std::string StudentName(const char* prompt);

// 학생 점수 입력 함수
int GetScore(const char* prompt);

// 학생 점수
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
