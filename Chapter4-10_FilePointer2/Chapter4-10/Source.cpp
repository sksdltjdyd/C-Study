#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

bool FileIsExist(const char* file) {
	FILE* fp = fopen(file, "r");

	if (fp != nullptr) fclose(fp);
	
	return fp != nullptr;
}

int main() {

	/*
	fopen(...)
	- fopen�� ����� ������ �� ����ó�� fclose(...)�� ���� �Ʒ��ʿ� ����� �ΰ� �� ���̿� �ڵ��� �ϴ°��� ����
	- �̴� �ٸ� ���α׷��ֿ����� ���������ε� �ٸ� ���α׷��� ������ �Ȱ��� ������ ���� ������ �ݱ� �����̴�
	*/

	/*
	fclose(..)
	- fclose �Լ��� nulptr�� �Ķ���ͷ� �޾��� ��� ��Ÿ�� ������ �߻��ϰ� �ȴ�
	- fopen�� "r"�ɼ����� ������ ��쿡 ������ ���ٸ� nullptr�� �����ϰ� �Ǵµ� �� ��츦 �����ؼ� ���α׷����� �ؾ��Ѵ�
	*/

	/*
	FILE* infile = fopen("Sample.txt", "r");
	if (infile != nullptr) fclose(infile);
	bool FileIsExist = infile != nullptr;
	*/
	
	/*
	bool exist = FileIsExist("sample.txt");

	if (exist)
	{
		printf("file is existed\n");
	}
	else
	{
		printf("file is not existed\n");
	}
	*/
	
	/*
	FILE* outfile = fopen("out.txt", "w");
	fprintf(outfile,"%d Hello World %d", 100, 100);
	fclose(outfile);
	*/

	/*
	�ؽ�Ʈ ���ڵ� ����
	- C++�� �⺻������ MS�⺻ ���ڵ��̳� ANSI ���ڵ��� Ȱ���Ͽ� ���ڿ��� �����ϰ� Ȱ���Ѵ�
	- �̸� �츮�� �������� ���� ���¿��� �ٸ� �ؽ�Ʈ �����͸� Ȱ���Ͽ� ����� ���ڿ��� �ҷ����� �Ǹ� �ѱ� �� �����ڰ� �ƴ� �ٸ� ���ڵ��� �ùٸ��� ���� ���ڿ��� ��Ÿ���� �ȴ�
	- ���忡�� �ѱ۷� �����ص� ������ ����. �׷��� ������ ����� ������ �����Ѵ�
	*/

	FILE* infile = fopen("in.txt", "r");
	char line[256];
	int data1;
	int data2;

	// fscanf(infile, "%d %d", &data1, &data2);

	/*
	fscanf(infile, "%255[^\n]s", line); // fscanf�� �ҷ��ö��� ���� ���پ� �ҷ����°� ���� ���ϴ�
	fgetc(infile); // ���ڿ� �����ٷ� �ѱ�� ���ؼ� ���� �Լ�. ������ ���� �����Ϳ��� ���� �ϳ��� �о �������ִ� �Լ��̴�
	printf("%s\n", line);
	fscanf(infile, "%255[^\n]s", line); // fscanf�� �ҷ��ö��� ���� ���پ� �ҷ����°� ���� ���ϴ�
	printf("%s\n", line);
	fclose(infile);
	*/
	
	// ó������ ������ �е��� �ϴ� �ڵ�
	while (true)
	{
		char line[256];
		fscanf(infile, "%255[^\n]s", line);
		fgetc(infile);
		feof(infile);

		printf("%s\n", line);

		if (feof(infile) == 1) break;
	}

	return 0;
}