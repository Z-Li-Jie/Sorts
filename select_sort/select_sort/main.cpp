#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ѡ������
void select_sort(vector<int>& array)
{
	for (int i = 0; i <array.size() ; i++)
	{
		int index = i;
		int key = array[i];
		for (int j = i + 1; j < array.size(); j++)
		{
			if (array[j] < key)
			{
				index = j;
				key = array[j];
			}
		}
		swap(array[i], array[index]);
	}
}


int main()
{
	vector<int> ans = { 5,2,1,6,3,2,11,8,23,4,10,7,18,21,13 };
	cout << "����ǰ��";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	select_sort(ans);

	cout << "�����";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;
}