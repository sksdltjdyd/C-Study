#ifndef __TYPING_SYSTEM_H__
#define __TYPING_SYSTEM_H__

#include "Header.h"
#include "User.h"

class TypingSystem{
private:
	// 문장들을 여기다 저장
	std::vector<std::string> sentences;

	// 현재 사용자
	User* curenttUser = nullptr;

	// 디스크로부터 데이터를 읽어와서 문장 리스트를 초기화 하는 함수
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
