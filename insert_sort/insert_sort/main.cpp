#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insert_sort(vector<int>& array)
{
	for (int i = 1; i < array.size(); i++)
	{
		int index = i - 1;
		int key = array[i];
		while (index >= 0 && array[index] > key)
		{
			array[index + 1] = array[index];
			index--;
		}
		array[index + 1] = key;
	}
}

int main()
{
	vector<int> ans = { 6,2,1,7,11,9,21,5,8,10,26,4,17,3,20,14 };
	cout << "ÅÅÐòÇ°£º";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;
	insert_sort(ans);
	cout << "ÅÅÐòºó£º";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}