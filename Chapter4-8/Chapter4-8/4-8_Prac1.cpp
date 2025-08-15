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
		printf("1. ȸ������  2. ȸ������ 3. ���α׷� ����\n");
		int menu = getint("����� ��� ��ȣ�� �Է��� �ּ��� : ");

		if (menu == 1) {
			std::string id = getstring("ID�� �Է��ϼ��� : ");
			std::string pw = getstring("�н����带 �Է��ϼ��� : ");

			if (member.count(id)) {
				printf("�ߺ��� ID�Դϴ�");
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
			printf("���α׷��� �����մϴ�");
			break;
		}
		else
		{
			printf("�߸��� �Է��Դϴ�");
		}
	}

	return 0;
}