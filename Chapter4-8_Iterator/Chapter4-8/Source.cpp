#include <cstdio>
#include <vector> // std::vector<T>�� ����ϱ� ���� ��������� �ϴ� ��ó��
#include <algorithm> // �迭 ���� �Լ��� ����ϱ� ���� �����ϴ� ��ó��
#include <map> // map�� ����ϱ� ���� ����
#include <string>



int main() {

	/*
	�⺻ �ڷ��� ���� 1 : std::vector<T>
	- std::vector<T>�� vector ������Ͽ� �ۼ��Ǿ� �ִ�
	- std::vector<T>�� Ȱ���ϰ� �Ǹ� �������� �迭�� ����ϰ� Ȱ�� �� �� �ִ�
	- std::vector<T>�� �츮�� �Ϲ������� �迭�� ����ϵ� ����� �� ������ �� ��ȸ�ڸ� �̿��� algorithm�� �ۼ��Ǿ� �ִ� sort(..)�Լ��� �̿��� ���� ���� �� �� �ִ�
	- �ٸ� ���� ���ϰ� �ֱ� ������ �����ϰ� ����ؾ� �Ѵ�
	*/

	std::vector<int> myvec = { 1, 32, 2 };

	myvec.push_back(100); // myvec �ڷ����� ���� �־��ִ� �Լ�
	myvec.push_back(200);
	myvec.push_back(300);

	myvec[2] = 50; // �迭ó�� �ε��� ���� �ٲ��� �� �ִ�

	/*
	��ȸ��(iterator)
	- ��ȸ�ڴ� �⺻ �ڷᱸ������ �����ִ� ���� Ž�� ��ġ�̴�
	- �� Ž�� ��ü�� �̿��ϸ� ���ҵ��� ���ʴ�� ������ �� �ְ� �� ��ȸ�ڸ� �̿��� for ������ �� ���� �ִ�
	- ��ȸ���� ���� ������ ������ �������� ���� �������� �� ó�� *(�ֽ��͸���ũ) �����ڸ� Ȱ���Ѵ�
	for(auto it = v.begin(); it=!v.end(); it++){
	...
	}
	*/

	// std::sort(myvec.begin(), myvec.end()); // �迭�� ���� ũ���� �������ش�

	// �迭�� ũ���� �����ϰ� �����ϴ� �ڵ�
	for (/*std::vector<int>::const_iterator --> �� �ڵ�� auto�� ����. �ʹ� �� ����Ѱ�*/auto it = myvec.begin(); it != myvec.end(); it++) {
		printf("%d, ", *it);
	}

	printf("%\n");

	for (int i = 0; i < myvec.size(); i++) // myvec.size()�� �ش� �ڷ����� ũ�⸦ �˾ƺ��� �Լ�
	{
		printf("%d, ", myvec[i]);
	}

	/*
	std::map<k,v>
	- std::map�� map ������Ͽ� �ۼ��Ǿ� �ִ�
	- std::map�� �迭�� ��������� �� �� Ȯ�强�� �ִ� �迭�� Ű�� �׿� �´� �� ���� ������ �� �ִ�
	- Ű�� �迭ó�� ���������� �ʾƵ� �Ǹ�, std::string �� �� integer�� �ƴϴ��� Ű���� ���� �� �ִٴ� ���� ���� ū �����̴�
	- map�� ���� ���԰� ���ÿ� �ڵ����� ���� ���ĵǴ� Ư¡�� �ִ�
	*/

	std::map<std::string, std::string> capitals;

	capitals["korea"] = "seoul";
	capitals["usa"] = "washington";
	capitals["japan"] = "tokyo";

	capitals.count("korea"); // korea�� �ش��ϴ� ���� �����ϴ��� �ƴ��� ���� �������ִ� �Լ�. ���ڸ� ����

	// capitals.erase("korea"); // �����ϴ� ���� �����ִ� �Լ�

	if (capitals.count("korea") == 1)
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	/*
	std::map�� ��ȸ
	- std::map�� ��ȸ�� �ϱ� ���� �Ϲ����� for ������ Ȱ�� �� �� ����, iterator(��ȸ��)�� Ȱ���� ��ȸ�� �����ϴ�
	for (auto it = myvec.begin(); it != myvec.end(); it++) {
		it->first; // map�� ���� Ű
		it->second; // map�� ���� ��
	}
	*/

	for (auto it = capitals.begin(); it != capitals.end(); it++) {
		/*
		printf("first : %s\n", it->first.c_str());
		printf("second : %s\n", it->second.c_str());
		*/
		printf("capitals[%s] = %s\n", it->first.c_str(), it->second.c_str()); // ���� ���� ���´�
		// ��½� Ű ���� ������ �ٲ�� ���� �� �ִµ� �̰��� �ش� �ڷ��� �Լ��� ���������� Ʈ����� �ý������� �ڵ����� �������ֱ� �����̴�
	}

	printf("%s", capitals["usa"].c_str()); // korea�� �����ϴ� ���ڰ� ���´�


	return 0;
}