#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//插入排序
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


//桶排序
void bucket_sort(vector<int>& array, int sz, int minval, int maxval)
{
	//每个桶最大的深度
	int bucketcnt = floor((maxval - minval) / sz) + 1;
	vector<vector<int>> bucket(sz);

	//将每个元素分配到对应的桶序号中
	for (int i = 0; i < array.size(); i++)
	{
		bucket[floor((array[i] - minval) / bucketcnt)].push_back(array[i]);
	}
	int index = 0;

	for (int i = 0; i < sz; i++)
	{
		//这里对每个桶都运用插入排序
		insert_sort(bucket[i]);
		for (int j = 0; j < bucket[i].size(); j++)
		{
			array[index++] = bucket[i][j];
		}
	}
}


int main()
{
	vector<int> ans = { 3,7,3,1,3,7,9,2,4,6,1,12,10,19,27,90,45,9,41,27,34 };
	//设定桶数
	int sz = 6;
	cout << "排序前：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	//找出数组中的最大元素值和最小元素值
	int minval = *min_element(ans.begin(), ans.end());
	int maxval = *max_element(ans.begin(), ans.end());
	
	bucket_sort(ans, sz, minval, maxval);

	cout << "排序后：";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}