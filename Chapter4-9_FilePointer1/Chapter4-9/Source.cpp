/*
File Pointer
- 파일 포인터는 물리적 디스크의 파일에 접근하는 타입 구성요소에는 다음의 3가지가 있다
1) 파일의 시작 지점
2) 파일의 종료 지점
3) 현재 읽고 있는 위치
*/

/*
C형식 File IO
File*fopen(char*filename, char*mode);
- filename : 대상 파일명 c스타일 파일 이름
- Mode : 파일을 여는 방법
1) w : 쓰기(존재하지 않으면 새로 생성, 존재하면 지우고 다시 생성)
2) r : 읽기(존재하지 않으면 오류, 존재하면 처음부터 읽어나가기)
3) a : 파일을 이어나가기(존재하지 않으면 새로 생성, 존재하면 파일의 마지막부터 쓰기)
4) w+ : 쓰기 또는 읽기(존재하지 않으면 새로 생성, 존재하면 지우고 다시 생성), 지우고 다시 생성하기 때문에 많이 쓰진 않는다
5) r+ : 쓰기 또는 읽기(존재하지 않으면 오류, 존재하면 처음부터 읽고 쓰기)
6) a+ : 이어나가기 또는 읽고 쓰기(존재하지 않으면 새로 생성, 존재하면 파일의 마지막부터)

int fclose(FILE* stream)
- 열려있는 파일을 닫는다.fp 파일 포인터 종료
- 성공 시 0을, 실패 시 EOF(-1)를 반환
- 파일을 사용 후 반드시 종료해주어야 한다

char fgetc(FILE*fp);
- fp로부터 다음 char를 1개 읽는다. fp를 1만큼 뒤로 이동한다

char* fgets(char*buff, int size, FILE*fp);
- fp로부터 다음 char*를 size만큼 읽는다. fp를 size만큼 뒤로 이동한다

int fscanf(FILE*fp, const char*str,...);
- 우리가 알고 있는 scanf 함수와 동일하게 사용. 단, fp를 처음에 파라미터로 넘겨야 한다. fp는 읽은 만큼 뒤로 이동
- 몇개의 argument가 성공적으로 assign 되었는지를 반환, 모두 실패시 EOF 반환

int fseek(FILE*fp, long pos, int origin);
- fp를 origin 기준으로 pos만큼 이동한다
(origin:SEEK_SET, SEEK_CUR, SEEK_END)
1) SEEK_SET : fp의 최초 시작점
2) SEEK_CUR : fp의 현재 시점
3) SEEK_END : fp의 마지막
- 성공 시 0, 실패 시 0이 아닌 값을 반환

int fputc(int character, FILE* stream);
- 파일에 한 문자를 쓴다. 성공 시 쓴 문자의 ASCII 코드 값을, 실패 시 EOF를 반환

int fprintf(FILE* stream, const char* format, ...);
- printf처럼 서식을 지정하여 파일에 데이터를 쓴다. 성공 시 출력된 문자의 수를 반환
- 몇개의 arguments를 성공적으로 fp에 출력했는가를 리턴. 오류시 0보다 작은값을 반환

int feof(FILE* stream);
- 파일의 끝(End-Of-File)에 도달했는지 확인
- 끝에 도달했으면 0이 아닌 값을 반환

EOF
- 매크로 상수. stdio.h에 정의됨

size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);
- 파일에 데이터 블록을 쓴다
- ptr이 가리키는 메모리에 있는 size 크기의 데이터를 count 개수만큼 파일에 쓴다
- 성공 시 쓴 전체 항목의 수를 반환

size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
- 파일에서 데이터 블록을 읽는다
- size 크기의 데이터를 count 개수만큼 읽어 ptr이 가리키는 메모리에 저장
- 성공 시 읽은 전체 항목의 수를 반환
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int main() {

	/*
	FILE* infile = fopen("text.txt", "w");
	fprintf(infile, "Hello World");
	fclose(infile); // 반드시 종료해줘야 한다
	*/ 

	/*
	FILE* infile = fopen("text.txt", "r");
	char input[100];
	fscanf(infile, "%99[^\n]s", input);
	printf("%s", input);
	fclose(infile); // 반드시 종료해줘야 한다
	*/

	/*
	FILE* infile = fopen("text.txt", "w");
	int value = 4876520;
	fprintf(infile, "%d", value);
	fclose(infile); // 반드시 종료해줘야 한다
	*/

	/*
	FILE* infile = fopen("text.txt", "w");
	int value = 4876520;
	fwrite(&value, sizeof(int), 1, infile);
	fclose(infile); // 반드시 종료해줘야 한다
	*/
	
	FILE* infile = fopen("text.txt", "r");
	int value;
	fread(&value, sizeof(int), 1, infile);
	fclose(infile); // 반드시 종료해줘야 한다
	
	printf("%d", value);

}