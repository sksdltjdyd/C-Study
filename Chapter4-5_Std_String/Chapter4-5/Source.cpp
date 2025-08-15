#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
// #include <cstring>
#include <string> // std::string을 쓰기 위해 사용하는 헤더 파일, strcpy도 사용 할 수 있다
#include <iostream> // std::cout을 쓰기 위해 사용하는 헤더파일

/*
namespcae를 사용하는 이유
- 프로그래머끼리 같은 이름을 사용하지 않도록 이름들을 구분해주는 역할이 필요했기 때문에 사용하기 시작
- 이 namespace는 Java에서는 package로 불리며 c#에서는 동일하게 namesapce라고 부른다

- :: 표시는 [스탠다드 Namespace]로 C++에서 가장 기본적으로 namespace를 사용하기 위해 사용하는 표시다
*/

// std 붙이는게 번거롭기에 미리 std를 선언해준다. 이렇게 선언해주면 std를 더 이상 안붙여도 된다
using namespace std;

// 같은 이름의 함수가 중복되지 않도록  namespace로 나눴다
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
레퍼런스(Reference) 타입
- 파라미터를 받을 때 타입 오른쪽에 &(앰퍼센드) 기호를 이용하게 되면 파라미터를 레퍼런스 타입으로 받을 수 있게 된다
- 기본적으로 std와 같은 선언문은 동적으로 작동하지 않고 정적 클래스이기에 포인터를 사용에 문제가 있다. 그러므로 레퍼런스 타입을 사용하는 것이다
- 이 레퍼런스 타입은 파라미터로 일어나는 값 복사를 막아주어 실행속도를 빠르게 할 수 있다는 장점이 있다
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
	- 기존의 C언어 문자열 정의 및 출력 방식
	char string[100];
	strcpy(string, "Hello World\n");
	strcat(string, "Hello C++\n");

	printf("%s", string);
	--> 기존 방식은 문자열 출력을 위해 사용해야 하는 함수도 많고 사용에 불편함이 존재한다
	*/

	/*
	std::string
	- C++에서 문자열을 활용하기 위한 클래스형 문자열 타입
	- string 헤더파일에 정의되어 있다
	- std::string에는 문자열을 이용한 여러가지 동작을 할 수 있도록 여러 멤버함수가 정의되어 있다

	- 또한 문자열의 포인터를 자동으로 관리해주기 때문에 하나하나 포인터를 관리할 필요 없이 정적인 형태의 클래스 인스턴스로 활용할 수 있다
	*/

	string mystr = "Hello World\n"; //std::string을 통한 문자열 선언, =로 구현이 가능한 이유는 연산자 오버로딩 원리 떄문에 가능한것이다
	mystr = mystr + "Hello C++\n"; //std::string을 통한 문자열 선언 후 문자열 이어 붙이기

	/*
	std 선언 문자열 클래스 출력 방법
	1) std::string::c_str()
	- const char*를 리턴해주는 문자열 클래스의 멤버 함수
	- 이를 활용해서 c스타일의 문자열의 const char*를 받아올수 있다
	- printf를 활용하기 위해서는 이 멤버 함수 호출이 필요하다
	
	2) std::cout << 변수명
	- 가장 보편적으로 std 선언 변수를 출력하기 위해 사용하는 방법. <iostream> 헤더 파일을 선언해야 사용 가능하다. 다만 다른 언어와 비교 했을때 굉장히 이질적인 방법이기에 다른 언어도 사용한다면 주의 할 필요가 있다
	*/

	printf("%s", mystr.c_str()); // 1번 방식의 출력
	// std::cout << mystr; // 2번 방법

	string str1 = "apple";
	string str2 = "banana";

	

	/*
	std::string::compare(...변수)
	- strcmp라는 함수와 동일한 일을 하는 멤버 함수
	- 현재 문자열 클래스의 문자열과 파라미터로 입력받은 문자열을 비교하여 
	1) 같다면 0
	2) 현재 문자열 클래스가 우선순위가 높다면 1
	3) 파라미터로 받은 문자열 우선순위가 높다면 2
	를 리턴한다
	*/

	if (str1.compare(str2) == 0) {
		printf("두 문자가 같습니다\n");
	}
	else
	{
		printf("두 문자는 다릅니다\n");
	}

	hong::foo();
	kim::foo();
	
	// 레퍼런스 타입으로 선언한 변수 함수 사용
	int v1 = 100;
	int v2 = 200;

	swap(v1, v2);
	printf("v1 = %d\n", v1);
	printf("v2 = %d\n", v2);

	// std 레퍼런스 타입
	std::string v3 = "Hello";
	std::string v4 = "world";
	swapword(v3, v4);
	printf("v3 = %s\n", v3.c_str());
	printf("v4 = %s\n", v4.c_str());

	return 0;
}

// 위에서 선언만 하고 아래에 몸체 정의
void hong::foo() {
	printf("홍길동이 만든 foo\n");
}

void kim::foo() {
	printf("김철수가 만든 foo\n");
}

// 클래스도 똑같이 작동
hong::Animal::Animal() {

}

void hong::Animal::printinf(int a) {
	printf("함수 선언");
}