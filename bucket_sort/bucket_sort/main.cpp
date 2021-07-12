#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��������
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


//Ͱ����
void bucket_sort(vector<int>& array, int sz, int minval, int maxval)
{
	//ÿ��Ͱ�������
	int bucketcnt = floor((maxval - minval) / sz) + 1;
	vector<vector<int>> bucket(sz);

	//��ÿ��Ԫ�ط��䵽��Ӧ��Ͱ�����
	for (int i = 0; i < array.size(); i++)
	{
		bucket[floor((array[i] - minval) / bucketcnt)].push_back(array[i]);
	}
	int index = 0;

	for (int i = 0; i < sz; i++)
	{
		//�����ÿ��Ͱ�����ò�������
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
	//�趨Ͱ��
	int sz = 6;
	cout << "����ǰ��";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	//�ҳ������е����Ԫ��ֵ����СԪ��ֵ
	int minval = *min_element(ans.begin(), ans.end());
	int maxval = *max_element(ans.begin(), ans.end());
	
	bucket_sort(ans, sz, minval, maxval);

	cout << "�����";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}