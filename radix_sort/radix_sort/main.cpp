#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radix_sort(vector<int>& array, int maxdigit)
{
	int mod = 10;
	int dev = 1;
	//�ӵ�λ����λ��ÿһλ����0����9��������Ԫ�ش�С��ȡ�ࣩ��������
	for (int i = 0; i < maxdigit; i++)
	{
		vector<vector<int>> bucket(10);
		for (int j = 0; j < array.size(); j++)
		{
			//����Ͱ����
			int num = floor((array[j] % mod) / dev);
			bucket[num].push_back(array[j]);
		}

		int index = 0;
		for (int a = 0; a < bucket.size(); a++)
		{
			for (int b =0 ; b < bucket[a].size(); b++)
			{
				array[index++] = bucket[a][b];
			}
		}

		mod = mod * 10;
		dev = dev * 10;
	}
}

int main()
{
	vector<int> ans = { 5,2,7,8,2,3,4,11,45,24,78,31,3,10,9,8,31,10,23,11,45,23,7,6,85 };
	cout << "����ǰ��";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	//�����������Ԫ�ص�λ����10���ƣ�
	int maxdigit = 0;
	int maxval = *max_element(ans.begin(), ans.end());
	while (maxval > 0)
	{
		maxdigit++;
		maxval = maxval / 10;
	}

	radix_sort(ans, maxdigit);

	cout << "�����";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}