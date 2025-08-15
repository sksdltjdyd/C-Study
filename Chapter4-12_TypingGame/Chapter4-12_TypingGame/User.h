#ifndef __USER_H__
#define __USER_H__

#include "Header.h"

class User
{
public:
	// 파일명
	std::string username;

	// 평균 타수
	float avgSpeed = 0.0f;

	// 타자 문장을 얼마나 입력했는가
	int TypingCount = 0;
	User(const std::string username);
	void save();
	void load();
	void printuserinfo();
};

#endif // !__USER_H__
