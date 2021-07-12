#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�ݹ����
void quick_sort(vector<int>& array, int left, int right)
{
	if (left >= right)
		return;
	//���û�׼ֵ
	int key = array[left];
	int i = left, j = right;
	while (i < j)
	{
		//���������ҳ�С�ڻ�׼�����������н���
		while (i < j&&array[j] >= key)
			j--;
		array[i] = array[j];
		//�������ң��ҳ����ڻ�׼�����������н���
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
	//1 �趨��ʼֵ
	vector<int> ans = { 2,11,3,8,5,6,13,10,9,4 };
	/*
	//2���������ʼֵ
	vector<int> ans;
	int x;
	while(cin >> x)
	{
	    ans.push_back(x);
	}
	*/
	cout << "����ǰ��";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	//���������ҡ��м�ѡ�����е���ֵ��Ϊ��׼
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
	cout << "��������֮��";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}