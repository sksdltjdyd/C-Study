#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm> 
#include <map> 
#include <string>

int getint(const char* prompt) {
	int input;
	fseek(stdin, 0, SEEK_END);
	printf("%s", prompt);
	scanf("%d", &input);
	return input;
}

std::string getstring(const char* prompt) {
	printf("%s", prompt);
	char str[100];
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", str);
	return str;
}

int main() {

	std::map<std::string, std::string> member;
	

	for (;;) {
		printf("1. 회원가입  2. 회원정보 3. 프로그램 종료\n");
		int menu = getint("사용할 기능 번호를 입력해 주세요 : ");

		if (menu == 1) {
			std::string id = getstring("ID를 입력하세요 : ");
			std::string pw = getstring("패스워드를 입력하세요 : ");

			if (member.count(id)) {
				printf("중복된 ID입니다");
			}
			else
			{
				member[id] = pw;
			}
		}
		else if (menu == 2)
		{
			int index = 1;
			for (auto it = member.begin(); it != member.end(); it++) {
				printf("%d. ID : %s, PW : %s\n", index, it->first.c_str(), it->second.c_str());
				index++;
			}
		}
		else if (menu == 3) {
			printf("프로그램을 종료합니다");
			break;
		}
		else
		{
			printf("잘못된 입력입니다");
		}
	}

	return 0;
}