#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//计数排序
void counting_sort(vector<int>& array,int minval,int maxval)
{
	int len = maxval - minval + 1;
	vector<int> bucket(len, 0);
	for (auto &num : array)
	{
		bucket[num - minval]++;
	}
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		while (bucket[i] > 0)
		{
			array[index++] = i + minval;
			bucket[i]--;
		}
	}
}

int main()
{
	vector<int> ans = { 3,6,1,3,5,2,5,7,2,4,6,8,2,1,4,6,8,2,4,6,7,11,21,12,35,11,21,19,10,9 };
	cout << "排序前：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	//找出数组中最大的元素值和最小元素值
	int minval = *min_element(ans.begin(), ans.end());
	int maxval = *max_element(ans.begin(), ans.end());

	counting_sort(ans, minval, maxval);

	cout << "排序后：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}