#include "User.h"

User::User(const std::string username)
{
	this->username = username;

	FILE* fp = fopen(username.c_str(), "r");
	bool exist = fp != nullptr;

	if(exist) fclose(fp);

	if (exist) {
		putStringOnPosition(6, 5, "User is Existed... Loading...");
		load();
		putStringOnPosition(6, 6, "Press Enter");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}
	else {
		putStringOnPosition(6, 5, "User is not Existed... Saving...");
		save();
		putStringOnPosition(6, 6, "Press Enter");
		fseek(stdin, 0, SEEK_END);
		fgetc(stdin);
	}
	
	
}

void User::save()
{
	FILE* outfile = fopen(username.c_str(), "w");
	fprintf(outfile, "%f\n", avgSpeed);
	fprintf(outfile, "%d", TypingCount);
	fclose(outfile);
}

void User::load()
{
	FILE* infile = fopen(username.c_str(), "r");
	fscanf(infile, "%f", &avgSpeed);
	fgetc(infile);
	fscanf(infile, "%d", &TypingCount);
	fclose(infile);
}

void User::printuserinfo()
{
	char avgSpeed[50];
	sprintf(avgSpeed, "Average Typing Speed : %f", this->avgSpeed);

	char count[50];
	sprintf(count, "Typing Count : %d", TypingCount);

	putStringOnPosition(6, 6, avgSpeed);
	putStringOnPosition(6, 7, count);
	putStringOnPosition(6, 8, "press Enter to continue");
	fseek(stdin, 0, SEEK_END);
	fgetc(stdin);
}
