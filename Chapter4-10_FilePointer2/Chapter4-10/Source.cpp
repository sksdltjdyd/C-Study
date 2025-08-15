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
	- fopen을 사용할 때에는 꼭 습관처럼 fclose(...)를 먼저 아래쪽에 만들어 두고 그 사이에 코딩을 하는것이 좋다
	- 이는 다른 프로그래밍에서도 마찬가지인데 다른 프로그래밍 언어에서도 똑같이 파일을 열고 파일을 닫기 때문이다
	*/

	/*
	fclose(..)
	- fclose 함수는 nulptr을 파라미터로 받았을 경우 런타임 오류가 발생하게 된다
	- fopen을 "r"옵션으로 열었을 경우에 파일이 없다면 nullptr을 리턴하게 되는데 이 경우를 생각해서 프로그래밍을 해야한다
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
	텍스트 인코딩 문제
	- C++는 기본적으로 MS기본 인코딩이나 ANSI 인코딩을 활용하여 문자열을 저장하고 활용한다
	- 이를 우리가 인지하지 못한 상태에서 다른 텍스트 에디터를 활용하여 저장된 문자열을 불러오게 되면 한글 등 영문자가 아닌 다른 문자들이 올바르지 않은 문자열로 나타나게 된다
	- 저장에는 한글로 저장해도 문제가 없다. 그러나 가급적 영어로 저장을 권장한다
	*/

	FILE* infile = fopen("in.txt", "r");
	char line[256];
	int data1;
	int data2;

	// fscanf(infile, "%d %d", &data1, &data2);

	/*
	fscanf(infile, "%255[^\n]s", line); // fscanf로 불러올때는 한줄 한줄씩 불러오는게 마음 편하다
	fgetc(infile); // 문자열 다음줄로 넘기기 위해서 쓰는 함수. 원래는 현재 포인터에서 문자 하나를 읽어서 리턴해주는 함수이다
	printf("%s\n", line);
	fscanf(infile, "%255[^\n]s", line); // fscanf로 불러올때는 한줄 한줄씩 불러오는게 마음 편하다
	printf("%s\n", line);
	fclose(infile);
	*/
	
	// 처음부터 끝까지 읽도록 하는 코드
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