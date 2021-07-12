#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(vector<int>& array, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	merge_sort(array, left, mid);
	merge_sort(array, mid + 1, right);
	int l = left, r = mid + 1;
	int len = right - left + 1;
	int i = 0;
	vector<int> tmp(len,0);
	//��ʱ�����������������Ԫ�طֱ���������ʹ��ϲ�����Ҳ����
	while (l <= mid && r <= right)
	{
		if (array[l] <= array[r])
			tmp[i++] = array[l++];
		else
			tmp[i++] = array[r++];
	}
	//������������ʣ��Ԫ�أ����򣩼������
	while (l <= mid)
		tmp[i++] = array[l++];
	//������������ʣ��Ԫ�أ����򣩼������
	while (r <= right)
		tmp[i++] = array[r++];

	for (int j = 0; j < len; j++)
		array[left + j] = tmp[j];
}



int main()
{
	//��ʼ����������Ԫ��
	vector<int> ans = { 3,6,2,8,3,54,11,10,23,17,12,7,10,9,32,6 };
	/*
	//2���������ʼֵ
	vector<int> ans;
	int x;
	while (cin >> x)
	{
		ans.push_back(x);
	}
	*/
	cout << "����ǰ���飺";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	int left = 0, right = ans.size() - 1;
	merge_sort(ans, left, right);
	cout << "��������飺";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}