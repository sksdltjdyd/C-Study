#include "Header.h"

/*
람다 함수를 쓰는 이유
1) 람다(Lambda) 함수는 '일회용 익명 함수'를 코드 중간에 즉석에서 만들어 쓰기 위해 사용
- 일반 함수는 어떤 작업을 지시하기 위해 별도의 '업무 지침서'를 제대로 작성해서 책장에 꽂아두고, 필요할 때마다 "책장 가서 그 지침서 보고 일해"라고 시키는 것과 같다
- 람다 함수는 지침서를 만들 만큼 거창한 일이 아닐 때, 그냥 포스트잇에 "이거 해!"라고 간단히 적어서 필요한 곳에 바로 붙여주는 것과 같다
2) 코드가 간결해지고 가독성이 높아진다 -> 알고리즘 함수 등을 사용할 때, 비교나 조건 검사를 위한 간단한 함수를 그 자리에서 바로 정의할 수 있어 편리하다. 코드가 여기저기 흩어지지 않고 한곳에 모여있어 이해하기 쉽다.
3) '일회용' 함수를 만들기 편하다 --> find_if (조건에 맞는 첫 원소 찾기), for_each (각 원소에 대해 작업 수행) 등 한 번만 쓰고 버릴 간단한 기능에 대해 굳이 함수 이름을 지어줄 필요가 없다. 이는 불필요한 함수들이 전역 공간을 어지럽히는 것을 막아준다
4) 주변의 변수를 '기억'해서 사용할 수 있다 (캡처 기능) -> 람다 함수는 자신이 만들어진 위치의 주변 변수들을 '캡처(capture)'해서 함수 안으로 가져와 사용할 수 있다. 이는 람다를 매우 강력하게 만드는 핵심 기능
5) 대부분 callback 함수에 사용한다
*/

int main() {

	/*
	Lamda 함수의 구조
	[캡처](파라미터...)->리턴{...}

	[캡처] : 람다함수 외부의 값을 캡처하는 곳
	(파라미터...) : 람다함수의 파라미터
	-> 리턴 : 람다함수의 리턴값을 정의
	{...} : 함수의 몸통
	*/

	/*
	// 람다 함수 사용
	// &표시 레퍼런스로 대괄호 안에 값을 가져오면 값이 변하면서 문제가 생길 수 있기 때문에 최근에는 아래와 같은 형식으로 그냥 값을 가져와서 사용한다
	int value = 100;
	
	Person* p = new Person();
	p->name = "David";

	std::function<void(int, float)> foo = [=](int value1, float value2) {
		printf("Hello World %s", p->name.c_str());
		};

	// 밑에서 값이 바뀌어도 알아서 바꿔서 출력해준다
	p->name = "Holland";

	foo(2, 3.14f);
	*/
	
	/*
	std::function<T>
	- 람다함수는 std::function의 변수형에 지정될 수 있다
	- 이 지정된 변수는 함수의 리턴타입과 파라미터 타입에 따라 정해지게 되는데 예를 들어 리턴타입이 bool이고 파라미터를 int, float로 두개를 받는다면 템플릿 타입은 다음과 같다
	std::function<bool(int, float)> someFunction;
	*/

	int value = 100;

	Person* p = new Person();
	p->name = "David";

	// 앞이 너무 길어지기 때문에 auto로 변경해서 사용 가능
	auto foo = [=](int value1, int value2) -> int/*리턴타입은 필요하면 지정해주면 된다*/ {
		return value1 + value2;
		};

	// 밑에서 값이 바뀌어도 알아서 바꿔서 출력해준다
	p->name = "Holland";

	foo(2, 3);

	/*
	std::bind
	- 람다함수는 새로운 변수형 함수를 만든다고 한다면 std::bind는 이미 존재하는 함수를 변수 형태로 만들어 std::function 클래스 인스턴스로 만들어준다
	- 이 std::bind를 활용하면 이미 존재하는 함수를 변수형태로 취급할 수 있게 된다
	*/
	

	// 미리 제작한 함수를 끌어와서 새로운 람다함수에 지정한다
	// auto는 std::function<void()>을 축약한것
	auto local_goo = std::bind(goo);
	local_goo();

	// 기존 함수에 파라미터가 존재한다면 std::placeholders 함수로 지정해줘야 한다
	// _1 이 숫자는 파라미터 개수에 따라 차례대로 넣어준다
	auto local_sum = std::bind(sum, std::placeholders::_1, std::placeholders::_2);
	int result = local_sum(2, 3);
	printf("%d\n", result);

	Marine* m = new Marine();
	auto attackTo = std::bind(&Marine::attact, m, std::placeholders::_1); // 마린클래스 레퍼런스를 가져와서 어택 함수를 불러온다. 클래스에서 m이라는 인자를 불러오고 변수 개수에 맞춰서 지정해준다
	attackTo("Zergling");

	// 람다함수의 핵심 기능 설명 -> 캡처
	auto hoo = [=](int a, int b) -> int {
		printf("Hello World / %d\n", result);
		return a + b;
	};
	int value3 = 100;
	int value4 = 200;
	int result2 = hoo(value3, value4);
	printf("%d", result2);
}

void goo() {
	printf("Hello World\n");
}

int sum(int a, int b) {
	return a + b;
}