#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//构建大根堆
void maxheap(vector<int>& array, int start, int end)
{
	int j = 2 * start + 1;
	while(j<=end-1)
	{
		//判断左右孩子的值
		if (j <= end - 1 && array[j] < array[j + 1])
			j++;
		if (array[j] < array[start])
			break;
		else
		{
			swap(array[j], array[start]);
			start = j;
			j = 2 * j + 1;
		}
	}
}

//堆排序
void heapsort(vector<int>& array, int len)
{
	//构建大根堆，叶子节点不用参与
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		maxheap(array, i, len - 1);
	}

	for (int i = len - 1; i >= 1; i--)
	{
		//将堆顶的根节点（此时的最大值）和末尾元素交换
		swap(array[0], array[i]);
		//将0~i-1之间的元素重新构建大根堆
		maxheap(array, 0, i-1);
	}
}

int main()
{
	vector<int> ans = { 3,7,8,1,2,12,4,10,8,22,16,1,5,27,19,6,100 };

	cout << "排序前的数组：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	int len = ans.size();
	heapsort(ans,len);
	cout << "排序后：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}
