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

	// 1. 단어, 뜻 입력
	// 2. 단어 찾기
	// 3. 프로그램 종료
	
	Dict* d = new Dict;

	printf("나만의 단어장입니다\n\n");

	for (;;) {
		int button = getint("사용할 기능을 입력해주세요 [1. 단어와 뜻 입력 2. 단어 찾기 3. 프로그램종료] : ");
		if (button == 1)
		{
			std::string word = getchar("단어를 입력해주세요 : ");
			std::string mean = getchar("뜻을 입력해주세요 : ");
			
			if (d->exist(word) == true) {
				printf("단어가 이미 입력되어 있습니다\n");
			}
			else
			{
				d->insertword(word, mean);
				printf("등록이 완료되었습니다\n");
			}
		}
		else if (button == 2)
		{
			std::string search = getchar("검색할 단어를 입력해 주세요 : ");
			if (d->exist(search) == true) {
				printf("뜻 : %s\n\n", d->getmean(search).c_str());
			}
			else
			{
				printf("단어가 존재하지 않습니다\n\n");
			}
		}
		else if (button == 3) {
			printf("프로그램을 종료합니다");
			break;
		}
		else
		{
			printf("입력을 잘못했습니다\n\n");
		}

	}

	/*
	- 숙제로 내가 한 버전

	std::map<std::string, std::string> dic;

	printf("나만의 단어장입니다\n\n");

	for (;;) {
		int button = getint("사용할 기능을 입력해주세요 [1. 단어와 뜻 입력 2. 단어 찾기 3. 프로그램종료] : ");
		if (button == 1)
		{
			std::string word = getchar("단어를 입력해주세요 : ");
			std::string mean = getchar("뜻을 입력해주세요 : ");
			if (dic.count(word)) {
				printf("단어가 이미 입력되어 있습니다");
			}
			else
			{
				dic[word] = mean;
			}
		}
		else if (button == 2)
		{
			std::string search = getchar("검색할 단어를 입력해 주세요 : ");
			for (auto  it = dic.begin(); it != dic.end(); it++)
			{
				if (search == it->first)
				{
					printf("단어 뜻 : %s\n", dic[search].c_str());
				}
			}
		}
		else if (button == 3) {
			printf("프로그램을 종료합니다");
			break;
		}
		else
		{
			printf("입력을 잘못했습니다\n\n");
		}

	}
	*/


	return 0;
}