#ifndef __USER_H__
#define __USER_H__

#include "Header.h"

class User
{
public:
	// ���ϸ�
	std::string username;

	// ��� Ÿ��
	float avgSpeed = 0.0f;

	// Ÿ�� ������ �󸶳� �Է��ߴ°�
	int TypingCount = 0;
	User(const std::string username);
	void save();
	void load();
	void printuserinfo();
};

#endif // !__USER_H__
