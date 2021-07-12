#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//递归求解
void quick_sort(vector<int>& array, int left, int right)
{
	if (left >= right)
		return;
	//设置基准值
	int key = array[left];
	int i = left, j = right;
	while (i < j)
	{
		//从右向左，找出小于基准的数，并进行交换
		while (i < j&&array[j] >= key)
			j--;
		array[i] = array[j];
		//从左向右，找出大于基准的数，并进行交换
		while (i < j&&array[i] <= key)
			i++;
		array[j] = array[i];
	}
	array[i] = key;
	quick_sort(array, left, i-1);
	quick_sort(array, i + 1, right);
}

int main()
{
	//1 设定初始值
	vector<int> ans = { 2,11,3,8,5,6,13,10,9,4 };
	/*
	//2自由输入初始值
	vector<int> ans;
	int x;
	while(cin >> x)
	{
	    ans.push_back(x);
	}
	*/
	cout << "排序前：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	//在最左、最右、中间选择其中的中值作为基准
	int left = 0, right = ans.size() - 1,mid = ans.size() / 2;
	if (ans[left] < ans[mid])
	{
		if (ans[mid] < ans[right])
			swap(ans[left], ans[mid]);
		else
		{
			if (ans[left] < ans[right])
				swap(ans[left], ans[right]);
		}
	}
	else
	{
		if (ans[left] > ans[right])
		{
			if (ans[mid] > ans[right])
				swap(ans[left], ans[mid]);
			else
				swap(ans[left],ans[right]);
		}
	}

	quick_sort(ans, left, right);
	cout << "快速排序之后：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}