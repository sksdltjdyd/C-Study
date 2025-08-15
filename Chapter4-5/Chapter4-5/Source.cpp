#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
// #include <cstring>
#include <string> // std::string�� ���� ���� ����ϴ� ��� ����, strcpy�� ��� �� �� �ִ�
#include <iostream> // std::cout�� ���� ���� ����ϴ� �������

/*
namespcae�� ����ϴ� ����
- ���α׷��ӳ��� ���� �̸��� ������� �ʵ��� �̸����� �������ִ� ������ �ʿ��߱� ������ ����ϱ� ����
- �� namespace�� Java������ package�� �Ҹ��� c#������ �����ϰ� namesapce��� �θ���

- :: ǥ�ô� [���Ĵٵ� Namespace]�� C++���� ���� �⺻������ namespace�� ����ϱ� ���� ����ϴ� ǥ�ô�
*/

// std ���̴°� ���ŷӱ⿡ �̸� std�� �������ش�. �̷��� �������ָ� std�� �� �̻� �Ⱥٿ��� �ȴ�
using namespace std;

// ���� �̸��� �Լ��� �ߺ����� �ʵ���  namespace�� ������
namespace hong {
	
	void foo();
	class Animal {
	public:
		Animal();
		
		void printinf(int a);
	};

}

namespace kim {

	void foo();
	

}

/*
���۷���(Reference) Ÿ��
- �Ķ���͸� ���� �� Ÿ�� �����ʿ� &(���ۼ���) ��ȣ�� �̿��ϰ� �Ǹ� �Ķ���͸� ���۷��� Ÿ������ ���� �� �ְ� �ȴ�
- �⺻������ std�� ���� ������ �������� �۵����� �ʰ� ���� Ŭ�����̱⿡ �����͸� ��뿡 ������ �ִ�. �׷��Ƿ� ���۷��� Ÿ���� ����ϴ� ���̴�
- �� ���۷��� Ÿ���� �Ķ���ͷ� �Ͼ�� �� ���縦 �����־� ����ӵ��� ������ �� �� �ִٴ� ������ �ִ�
*/

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;

}

void swapword(std::string& a, std::string& b) {
	std::string temp;
	temp = a;
	a = b;
	b = temp;

}

int main() {

	/*
	- ������ C��� ���ڿ� ���� �� ��� ���
	char string[100];
	strcpy(string, "Hello World\n");
	strcat(string, "Hello C++\n");

	printf("%s", string);
	--> ���� ����� ���ڿ� ����� ���� ����ؾ� �ϴ� �Լ��� ���� ��뿡 �������� �����Ѵ�
	*/

	/*
	std::string
	- C++���� ���ڿ��� Ȱ���ϱ� ���� Ŭ������ ���ڿ� Ÿ��
	- string ������Ͽ� ���ǵǾ� �ִ�
	- std::string���� ���ڿ��� �̿��� �������� ������ �� �� �ֵ��� ���� ����Լ��� ���ǵǾ� �ִ�

	- ���� ���ڿ��� �����͸� �ڵ����� �������ֱ� ������ �ϳ��ϳ� �����͸� ������ �ʿ� ���� ������ ������ Ŭ���� �ν��Ͻ��� Ȱ���� �� �ִ�
	*/

	string mystr = "Hello World\n"; //std::string�� ���� ���ڿ� ����, =�� ������ ������ ������ ������ �����ε� ���� ������ �����Ѱ��̴�
	mystr = mystr + "Hello C++\n"; //std::string�� ���� ���ڿ� ���� �� ���ڿ� �̾� ���̱�

	/*
	std ���� ���ڿ� Ŭ���� ��� ���
	1) std::string::c_str()
	- const char*�� �������ִ� ���ڿ� Ŭ������ ��� �Լ�
	- �̸� Ȱ���ؼ� c��Ÿ���� ���ڿ��� const char*�� �޾ƿü� �ִ�
	- printf�� Ȱ���ϱ� ���ؼ��� �� ��� �Լ� ȣ���� �ʿ��ϴ�
	
	2) std::cout << ������
	- ���� ���������� std ���� ������ ����ϱ� ���� ����ϴ� ���. <iostream> ��� ������ �����ؾ� ��� �����ϴ�. �ٸ� �ٸ� ���� �� ������ ������ �������� ����̱⿡ �ٸ� �� ����Ѵٸ� ���� �� �ʿ䰡 �ִ�
	*/

	printf("%s", mystr.c_str()); // 1�� ����� ���
	// std::cout << mystr; // 2�� ���

	string str1 = "apple";
	string str2 = "banana";

	

	/*
	std::string::compare(...����)
	- strcmp��� �Լ��� ������ ���� �ϴ� ��� �Լ�
	- ���� ���ڿ� Ŭ������ ���ڿ��� �Ķ���ͷ� �Է¹��� ���ڿ��� ���Ͽ� 
	1) ���ٸ� 0
	2) ���� ���ڿ� Ŭ������ �켱������ ���ٸ� 1
	3) �Ķ���ͷ� ���� ���ڿ� �켱������ ���ٸ� 2
	�� �����Ѵ�
	*/

	if (str1.compare(str2) == 0) {
		printf("�� ���ڰ� �����ϴ�\n");
	}
	else
	{
		printf("�� ���ڴ� �ٸ��ϴ�\n");
	}

	hong::foo();
	kim::foo();
	
	// ���۷��� Ÿ������ ������ ���� �Լ� ���
	int v1 = 100;
	int v2 = 200;

	swap(v1, v2);
	printf("v1 = %d\n", v1);
	printf("v2 = %d\n", v2);

	// std ���۷��� Ÿ��
	std::string v3 = "Hello";
	std::string v4 = "world";
	swapword(v3, v4);
	printf("v3 = %s\n", v3.c_str());
	printf("v4 = %s\n", v4.c_str());

	return 0;
}

// ������ ���� �ϰ� �Ʒ��� ��ü ����
void hong::foo() {
	printf("ȫ�浿�� ���� foo\n");
}

void kim::foo() {
	printf("��ö���� ���� foo\n");
}

// Ŭ������ �Ȱ��� �۵�
hong::Animal::Animal() {

}

void hong::Animal::printinf(int a) {
	printf("�Լ� ����");
}