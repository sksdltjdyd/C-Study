#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>

int getint(const char* prompt) {
	int input;
	printf("%s", prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}

std::string getchar(const char* prompt) {
	printf("%s", prompt);
	char str[100];
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", str);
	return str;
}

class Dict {
private:
	std::map<std::string, std::string> dic;

public:
	void insertword(const std::string& word, const std::string& mean) {
		dic[word] = mean;
	}

	bool exist(std::string word) {
		return dic.count(word) == 1;
		/*
		if (dic.count(word) == 1) {
			return true;
		}
		return false;
		*/
	}

	std::string getmean(std::string word) {
		return dic[word];
	}
};

int main() {

	// 1. �ܾ�, �� �Է�
	// 2. �ܾ� ã��
	// 3. ���α׷� ����
	
	Dict* d = new Dict;

	printf("������ �ܾ����Դϴ�\n\n");

	for (;;) {
		int button = getint("����� ����� �Է����ּ��� [1. �ܾ�� �� �Է� 2. �ܾ� ã�� 3. ���α׷�����] : ");
		if (button == 1)
		{
			std::string word = getchar("�ܾ �Է����ּ��� : ");
			std::string mean = getchar("���� �Է����ּ��� : ");
			
			if (d->exist(word) == true) {
				printf("�ܾ �̹� �ԷµǾ� �ֽ��ϴ�\n");
			}
			else
			{
				d->insertword(word, mean);
				printf("����� �Ϸ�Ǿ����ϴ�\n");
			}
		}
		else if (button == 2)
		{
			std::string search = getchar("�˻��� �ܾ �Է��� �ּ��� : ");
			if (d->exist(search) == true) {
				printf("�� : %s\n\n", d->getmean(search).c_str());
			}
			else
			{
				printf("�ܾ �������� �ʽ��ϴ�\n\n");
			}
		}
		else if (button == 3) {
			printf("���α׷��� �����մϴ�");
			break;
		}
		else
		{
			printf("�Է��� �߸��߽��ϴ�\n\n");
		}

	}

	/*
	- ������ ���� �� ����

	std::map<std::string, std::string> dic;

	printf("������ �ܾ����Դϴ�\n\n");

	for (;;) {
		int button = getint("����� ����� �Է����ּ��� [1. �ܾ�� �� �Է� 2. �ܾ� ã�� 3. ���α׷�����] : ");
		if (button == 1)
		{
			std::string word = getchar("�ܾ �Է����ּ��� : ");
			std::string mean = getchar("���� �Է����ּ��� : ");
			if (dic.count(word)) {
				printf("�ܾ �̹� �ԷµǾ� �ֽ��ϴ�");
			}
			else
			{
				dic[word] = mean;
			}
		}
		else if (button == 2)
		{
			std::string search = getchar("�˻��� �ܾ �Է��� �ּ��� : ");
			for (auto  it = dic.begin(); it != dic.end(); it++)
			{
				if (search == it->first)
				{
					printf("�ܾ� �� : %s\n", dic[search].c_str());
				}
			}
		}
		else if (button == 3) {
			printf("���α׷��� �����մϴ�");
			break;
		}
		else
		{
			printf("�Է��� �߸��߽��ϴ�\n\n");
		}

	}
	*/


	return 0;
}