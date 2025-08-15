#include "TypingSystem.h"

void TypingSystem::loaddata() {
	FILE* infile = fopen("sentences.txt", "r");

	for (;;) {
		if (feof(infile) == 1) break;
		char line[512] = { 0, };
		fscanf(infile, "%511[^\n]s", line);
		fgetc(infile);
		sentences.push_back(line);
	}

	fclose(infile);
}

void TypingSystem::printdata()
{
	for (int i = 0; i < sentences.size(); i++) {
		printf("%s\n", sentences[i].c_str());
	}
}

void TypingSystem::start()
{
	this->loaddata();
	for (;;) {
		clear();
		printmenu();
		char input = getchar();

		if (input == '1' && curenttUser == nullptr) {
			// 로그인
			// 입력을 받아서 문자열과 동일한 파일명이 있으면 파일에서 데이터를 읽어와서 평균타수, 총타자 연습갯수를 불러오는 로직
			putStringOnPosition(6, 4, "Press ID : ");
			std::string username = getstring();
			curenttUser = new User(username);
			
		}
		else if (input == '1' && curenttUser != nullptr) {
			// 로그아웃
			delete curenttUser;
			curenttUser = nullptr;
		}
		else if (input == '2' && curenttUser != nullptr) {
			// 타자연습
			typingstart();
		}
		else if (input == '3' && curenttUser != nullptr) {
			curenttUser->printuserinfo();
		}
		else if (input == 'x' || input == 'X') {
			// 종료
			putStringOnPosition(6, 13, "Program Exit");
			break;
		}
		
	}
}

void TypingSystem::printmenu()
{
	if (curenttUser == nullptr) {
		putStringOnPosition(6, 3, "1. Sign in");
	}
	else
	{
		putStringOnPosition(6, 3, "1. Sign Out");
		putStringOnPosition(6, 4, "2. Typing practice");
		putStringOnPosition(6, 5, "3. My Average");
	}
	putStringOnPosition(6, 12, "Check Your Menu[Press X to EXIT] : ");
}

char TypingSystem::getchar()
{
	fseek(stdin, 0, SEEK_END);
	char c;
	scanf("%c", &c);
	return c;
}

std::string TypingSystem::getstring()
{
	char input[100];
	fseek(stdin, 0, SEEK_END);
	scanf("%99[^\n]s", input);
	return input;
}

void TypingSystem::typingstart()
{
	float types_per_min = 0.0f;
	for (int i = 0; i < 5; i++)
	{
		clear();
		// sprintf를 위해서 만든 배열
		// 지속적으로 사용
		char buff[128];

		// 시간 출력
		
		sprintf(buff, "Types Per Min : %.f / Average Types : %.2f", types_per_min, curenttUser ->avgSpeed);
		putStringOnPosition(6, 5, buff);

		float start = (float)clock() / CLOCKS_PER_SEC;
		int target = rand() % sentences.size();
		sprintf(buff, "Sentence : %s", sentences[target].c_str());
		putStringOnPosition(6, 6, buff);
		
		// 문자열 입력
		putStringOnPosition(6, 7, "Press : ");
		std::string input = getstring();

		// 입력된 문자열과 해당 문자열의 일치율, 입력 속도 계산 출력
		float end = (float)clock() / CLOCKS_PER_SEC;
		float delta = end - start;

		// 분당 타수 계산
		types_per_min = sentences[target].size() / delta * 60;

		int match = compare(sentences[target], input);
		float match_ratio = (float)match / sentences[target].size();

		types_per_min = types_per_min * match_ratio;

		// 타이핑 카운트 계산
		curenttUser->TypingCount++; 
		curenttUser->avgSpeed = (curenttUser->avgSpeed * ((float)curenttUser->TypingCount - 1.0) + types_per_min) / (float)curenttUser->TypingCount;
		
	}

	curenttUser->save();
	putStringOnPosition(6, 8, "Typing Is Over");
	putStringOnPosition(6, 9, "Press Enter to continue");
	fseek(stdin, 0, SEEK_END);
	fgetc(stdin);
}

int TypingSystem::compare(const std::string& original, const std::string& input)
{
	int count = 0;

	int size = original.size() < input.size() ? original.size() : input.size();

	for (int i = 0; i < size; i++)
	{
		// 파라미터에 있는 문자 하나를 받아서 리턴하는 함수
		if (original.at(i) == input.at(i)) {
			count++;
		}
	}

	return count;
}
