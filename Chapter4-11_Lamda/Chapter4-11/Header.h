#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <vector>
/*
#include <functionl>
- std::function�� ����ϱ� ���� �������
- �� ��������� �����ؾ� std::function�� ����� �� �ִ�
- ���ٸ� ����ϱ� ���� �� ����� �ʿ�� ������ �ص��� ������ ������� ������ �����
*/
#include <cmath>
#include <functional>

class Person {
public:
	std::string name;
};

class Marine {
public:
	void attact(const char* target) {
		printf("Marine Attact %s\n", target);
	}
};

void goo();

int sum(int a, int b);