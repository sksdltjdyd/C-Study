#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>
#include <vector>
/*
#include <functionl>
- std::function을 사용하기 위한 헤더파일
- 이 헤더파일을 포함해야 std::function을 사용할 수 있다
- 람다를 사용하기 위해 꼭 사용할 필요는 없지만 해두지 않으면 여러모로 문제가 생긴다
*/
#include <cmath>
#include <functional>

class Person {
public:
	std::string name;
};

class Marine {
public:
	void attact(const char* target) {
		printf("Marine Attact %s\n", target);
	}
};

void goo();

int sum(int a, int b);