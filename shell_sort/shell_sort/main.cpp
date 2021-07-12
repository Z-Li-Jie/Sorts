#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void shell_sort(vector<int>& array)
{
	int increment = array.size();
	while (increment > 1)
	{
		//增量序列
		increment = increment / 3 + 1;
		for (int i = increment; i < array.size(); i++)
		{
			int j = i;
			int key = array[i];
			while (j - increment >= 0 && key < array[j - increment])
			{
				array[j] = array[j - increment];
				j = j - increment;
			}
			array[j] = key;
		}
	}
}

int main()
{
	vector<int> ans = { 6,1,2,11,5,22,4,9,7,21,8,10,3,21,9 };
	cout << "排序前：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;
	shell_sort(ans);
	cout << "排序后：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}