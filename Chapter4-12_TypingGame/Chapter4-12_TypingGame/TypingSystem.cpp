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
			// �α���
			// �Է��� �޾Ƽ� ���ڿ��� ������ ���ϸ��� ������ ���Ͽ��� �����͸� �о�ͼ� ���Ÿ��, ��Ÿ�� ���������� �ҷ����� ����
			putStringOnPosition(6, 4, "Press ID : ");
			std::string username = getstring();
			curenttUser = new User(username);
			
		}
		else if (input == '1' && curenttUser != nullptr) {
			// �α׾ƿ�
			delete curenttUser;
			curenttUser = nullptr;
		}
		else if (input == '2' && curenttUser != nullptr) {
			// Ÿ�ڿ���
			typingstart();
		}
		else if (input == '3' && curenttUser != nullptr) {
			curenttUser->printuserinfo();
		}
		else if (input == 'x' || input == 'X') {
			// ����
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
		// sprintf�� ���ؼ� ���� �迭
		// ���������� ���
		char buff[128];

		// �ð� ���
		
		sprintf(buff, "Types Per Min : %.f / Average Types : %.2f", types_per_min, curenttUser ->avgSpeed);
		putStringOnPosition(6, 5, buff);

		float start = (float)clock() / CLOCKS_PER_SEC;
		int target = rand() % sentences.size();
		sprintf(buff, "Sentence : %s", sentences[target].c_str());
		putStringOnPosition(6, 6, buff);
		
		// ���ڿ� �Է�
		putStringOnPosition(6, 7, "Press : ");
		std::string input = getstring();

		// �Էµ� ���ڿ��� �ش� ���ڿ��� ��ġ��, �Է� �ӵ� ��� ���
		float end = (float)clock() / CLOCKS_PER_SEC;
		float delta = end - start;

		// �д� Ÿ�� ���
		types_per_min = sentences[target].size() / delta * 60;

		int match = compare(sentences[target], input);
		float match_ratio = (float)match / sentences[target].size();

		types_per_min = types_per_min * match_ratio;

		// Ÿ���� ī��Ʈ ���
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
		// �Ķ���Ϳ� �ִ� ���� �ϳ��� �޾Ƽ� �����ϴ� �Լ�
		if (original.at(i) == input.at(i)) {
			count++;
		}
	}

	return count;
}
