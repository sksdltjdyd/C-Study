/*
File Pointer
- ���� �����ʹ� ������ ��ũ�� ���Ͽ� �����ϴ� Ÿ�� ������ҿ��� ������ 3������ �ִ�
1) ������ ���� ����
2) ������ ���� ����
3) ���� �а� �ִ� ��ġ
*/

/*
C���� File IO
File*fopen(char*filename, char*mode);
- filename : ��� ���ϸ� c��Ÿ�� ���� �̸�
- Mode : ������ ���� ���
1) w : ����(�������� ������ ���� ����, �����ϸ� ����� �ٽ� ����)
2) r : �б�(�������� ������ ����, �����ϸ� ó������ �о����)
3) a : ������ �̾����(�������� ������ ���� ����, �����ϸ� ������ ���������� ����)
4) w+ : ���� �Ǵ� �б�(�������� ������ ���� ����, �����ϸ� ����� �ٽ� ����), ����� �ٽ� �����ϱ� ������ ���� ���� �ʴ´�
5) r+ : ���� �Ǵ� �б�(�������� ������ ����, �����ϸ� ó������ �а� ����)
6) a+ : �̾���� �Ǵ� �а� ����(�������� ������ ���� ����, �����ϸ� ������ ����������)

int fclose(FILE* stream)
- �����ִ� ������ �ݴ´�.fp ���� ������ ����
- ���� �� 0��, ���� �� EOF(-1)�� ��ȯ
- ������ ��� �� �ݵ�� �������־�� �Ѵ�

char fgetc(FILE*fp);
- fp�κ��� ���� char�� 1�� �д´�. fp�� 1��ŭ �ڷ� �̵��Ѵ�

char* fgets(char*buff, int size, FILE*fp);
- fp�κ��� ���� char*�� size��ŭ �д´�. fp�� size��ŭ �ڷ� �̵��Ѵ�

int fscanf(FILE*fp, const char*str,...);
- �츮�� �˰� �ִ� scanf �Լ��� �����ϰ� ���. ��, fp�� ó���� �Ķ���ͷ� �Ѱܾ� �Ѵ�. fp�� ���� ��ŭ �ڷ� �̵�
- ��� argument�� ���������� assign �Ǿ������� ��ȯ, ��� ���н� EOF ��ȯ

int fseek(FILE*fp, long pos, int origin);
- fp�� origin �������� pos��ŭ �̵��Ѵ�
(origin:SEEK_SET, SEEK_CUR, SEEK_END)
1) SEEK_SET : fp�� ���� ������
2) SEEK_CUR : fp�� ���� ����
3) SEEK_END : fp�� ������
- ���� �� 0, ���� �� 0�� �ƴ� ���� ��ȯ

int fputc(int character, FILE* stream);
- ���Ͽ� �� ���ڸ� ����. ���� �� �� ������ ASCII �ڵ� ����, ���� �� EOF�� ��ȯ

int fprintf(FILE* stream, const char* format, ...);
- printfó�� ������ �����Ͽ� ���Ͽ� �����͸� ����. ���� �� ��µ� ������ ���� ��ȯ
- ��� arguments�� ���������� fp�� ����ߴ°��� ����. ������ 0���� �������� ��ȯ

int feof(FILE* stream);
- ������ ��(End-Of-File)�� �����ߴ��� Ȯ��
- ���� ���������� 0�� �ƴ� ���� ��ȯ

EOF
- ��ũ�� ���. stdio.h�� ���ǵ�

size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream);
- ���Ͽ� ������ ����� ����
- ptr�� ����Ű�� �޸𸮿� �ִ� size ũ���� �����͸� count ������ŭ ���Ͽ� ����
- ���� �� �� ��ü �׸��� ���� ��ȯ

size_t fread(void* ptr, size_t size, size_t count, FILE* stream);
- ���Ͽ��� ������ ����� �д´�
- size ũ���� �����͸� count ������ŭ �о� ptr�� ����Ű�� �޸𸮿� ����
- ���� �� ���� ��ü �׸��� ���� ��ȯ
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

int main() {

	/*
	FILE* infile = fopen("text.txt", "w");
	fprintf(infile, "Hello World");
	fclose(infile); // �ݵ�� ��������� �Ѵ�
	*/ 

	/*
	FILE* infile = fopen("text.txt", "r");
	char input[100];
	fscanf(infile, "%99[^\n]s", input);
	printf("%s", input);
	fclose(infile); // �ݵ�� ��������� �Ѵ�
	*/

	/*
	FILE* infile = fopen("text.txt", "w");
	int value = 4876520;
	fprintf(infile, "%d", value);
	fclose(infile); // �ݵ�� ��������� �Ѵ�
	*/

	/*
	FILE* infile = fopen("text.txt", "w");
	int value = 4876520;
	fwrite(&value, sizeof(int), 1, infile);
	fclose(infile); // �ݵ�� ��������� �Ѵ�
	*/
	
	FILE* infile = fopen("text.txt", "r");
	int value;
	fread(&value, sizeof(int), 1, infile);
	fclose(infile); // �ݵ�� ��������� �Ѵ�
	
	printf("%d", value);

}