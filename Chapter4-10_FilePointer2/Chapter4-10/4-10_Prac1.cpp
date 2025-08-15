#include "Header.h"

int main() {

	std::vector<Student> students;
	FILE* infile = fopen("Student.txt", "r");
	while (true) {
		if (feof(infile) == 1) break;
		char name[100];
		int korean;
		int math;
		int eng;
		int result;

		result = fscanf(infile, "Name : %99[^\n]s", name);
		if (result == -1) break;
		fgetc(infile);

		result = fscanf(infile, "Korean : %d / Math : %d / English : %d", &korean, &math, &eng);
		if (result == -1) break;
		fgetc(infile);

		Student s = Student(name, korean, math, eng);
		students.push_back(s);
	}
	fclose(infile);

	while (true)
	{
		for (int i = 0; i < students.size(); i++)
		{
			students[i].printinfo();
		}
		std::string name = StudentName("Student Name : ");
		int korean = GetScore("Korean : ");
		int math = GetScore("Math : ");
		int eng = GetScore("English : ");

		Student s = Student(name, korean, math, eng);
		students.push_back(s);

		FILE* outfile = fopen("Student.txt", "w");
		for (int i = 0; i < students.size(); i++)
		{
			fprintf(outfile, "Name : %s\n", students[i].name.c_str());
			fprintf(outfile, "Korean : %d / Math : %d / English : %d\n", students[i].korean, students[i].math, students[i].eng);
		}
		fclose(outfile);
	}
}

std::string StudentName(const char* prompt) {
	char name[100];
	printf(prompt);
	fseek(stdin, 0, SEEK_END);
	scanf(" %99[^\n]s", name);
	return name;
}

int GetScore(const char* prompt) {
	int input = 0;
	printf(prompt);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &input);
	return input;
}

Student::Student(std::string name, int korean, int math, int eng) {
	this->name = name;
	this->korean = korean;
	this->math = math;
	this->eng = eng;
}

void Student::printinfo() {
	printf("Name : %s\n", name.c_str());
	printf("Korean : %d / Math : %d / English : %d\n", korean, math, eng);

}