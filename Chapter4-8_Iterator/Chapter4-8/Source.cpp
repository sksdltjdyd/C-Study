#include <cstdio>
#include <vector> // std::vector<T>를 사용하기 위해 선언해줘야 하는 전처리
#include <algorithm> // 배열 정리 함수를 사용하기 위해 선언하는 전처리
#include <map> // map을 사용하기 위해 선언
#include <string>



int main() {

	/*
	기본 자료형 구조 1 : std::vector<T>
	- std::vector<T>는 vector 헤더파일에 작성되어 있다
	- std::vector<T>를 활용하게 되면 유동적인 배열을 편안하게 활용 할 수 있다
	- std::vector<T>는 우리가 일반적으로 배열을 사용하듯 사용할 수 있으며 이 순회자를 이용해 algorithm에 작성되어 있는 sort(..)함수를 이용해 값을 정렬 할 수 있다
	- 다만 성능 저하가 있기 때문에 적절하게 사용해야 한다
	*/

	std::vector<int> myvec = { 1, 32, 2 };

	myvec.push_back(100); // myvec 자료형에 값을 넣어주는 함수
	myvec.push_back(200);
	myvec.push_back(300);

	myvec[2] = 50; // 배열처럼 인덱스 값을 바꿔줄 수 있다

	/*
	순회자(iterator)
	- 순회자는 기본 자료구조들이 갖고있는 원소 탐색 객치이다
	- 이 탐색 객체를 이용하면 원소들을 차례대로 가져올 수 있고 이 순회자를 이용해 for 루프를 돌 수도 있다
	- 순회자의 값을 가져올 때에는 포인터의 값을 가져오는 것 처럼 *(애스터리스크) 연산자를 활용한다
	for(auto it = v.begin(); it=!v.end(); it++){
	...
	}
	*/

	// std::sort(myvec.begin(), myvec.end()); // 배열을 숫자 크기대로 정렬해준다

	// 배열을 크기대로 정렬하고 나열하는 코드
	for (/*std::vector<int>::const_iterator --> 이 코드는 auto와 같다. 너무 길어서 축약한것*/auto it = myvec.begin(); it != myvec.end(); it++) {
		printf("%d, ", *it);
	}

	printf("%\n");

	for (int i = 0; i < myvec.size(); i++) // myvec.size()는 해당 자료형의 크기를 알아보는 함수
	{
		printf("%d, ", myvec[i]);
	}

	/*
	std::map<k,v>
	- std::map은 map 헤더파일에 작성되어 있다
	- std::map은 배열과 비슷하지만 좀 더 확장성이 있는 배열로 키와 그에 맞는 값 쌍을 저장할 수 있다
	- 키는 배열처럼 연속적이지 않아도 되며, std::string 등 꼭 integer가 아니더라도 키값을 가질 수 있다는 것이 가장 큰 장점이다
	- map은 원소 삽입과 동시에 자동으로 값이 정렬되는 특징이 있다
	*/

	std::map<std::string, std::string> capitals;

	capitals["korea"] = "seoul";
	capitals["usa"] = "washington";
	capitals["japan"] = "tokyo";

	capitals.count("korea"); // korea에 해당하는 값이 존재하는지 아닌지 값을 리턴해주는 함수. 숫자를 리턴

	// capitals.erase("korea"); // 존재하는 값을 지워주는 함수

	if (capitals.count("korea") == 1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	/*
	std::map의 순회
	- std::map은 순회를 하기 위해 일반적인 for 루프를 활용 할 수 없고, iterator(순회자)를 활용한 순회만 가능하다
	for (auto it = myvec.begin(); it != myvec.end(); it++) {
		it->first; // map의 각각 키
		it->second; // map의 각각 값
	}
	*/

	for (auto it = capitals.begin(); it != capitals.end(); it++) {
		/*
		printf("first : %s\n", it->first.c_str());
		printf("second : %s\n", it->second.c_str());
		*/
		printf("capitals[%s] = %s\n", it->first.c_str(), it->second.c_str()); // 값은 값이 나온다
		// 출력시 키 값의 순서가 바뀌어 나올 수 있는데 이것은 해당 자료형 함수가 내부적으로 트리라는 시스템으로 자동으로 정렬해주기 떄문이다
	}

	printf("%s", capitals["usa"].c_str()); // korea에 대응하는 문자가 나온다


	return 0;
}