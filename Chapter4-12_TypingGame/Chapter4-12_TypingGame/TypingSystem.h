#ifndef __TYPING_SYSTEM_H__
#define __TYPING_SYSTEM_H__

#include "Header.h"
#include "User.h"

class TypingSystem{
private:
	// ������� ����� ����
	std::vector<std::string> sentences;

	// ���� �����
	User* curenttUser = nullptr;

	// ��ũ�κ��� �����͸� �о�ͼ� ���� ����Ʈ�� �ʱ�ȭ �ϴ� �Լ�
	void loaddata();

public:
	void printdata();
	void start();
	void printmenu();
	char getchar();
	std::string getstring();
	void typingstart();
	int compare(const std::string& original, const std::string& input);
};


#endif // !__TYPING_SYSTEM_H__
