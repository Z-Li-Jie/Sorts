#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���������
void maxheap(vector<int>& array, int start, int end)
{
	int j = 2 * start + 1;
	while(j<=end-1)
	{
		//�ж����Һ��ӵ�ֵ
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

//������
void heapsort(vector<int>& array, int len)
{
	//��������ѣ�Ҷ�ӽڵ㲻�ò���
	for (int i = len / 2 - 1; i >= 0; i--)
	{
		maxheap(array, i, len - 1);
	}

	for (int i = len - 1; i >= 1; i--)
	{
		//���Ѷ��ĸ��ڵ㣨��ʱ�����ֵ����ĩβԪ�ؽ���
		swap(array[0], array[i]);
		//��0~i-1֮���Ԫ�����¹��������
		maxheap(array, 0, i-1);
	}
}

int main()
{
	vector<int> ans = { 3,7,8,1,2,12,4,10,8,22,16,1,5,27,19,6,100 };

	cout << "����ǰ�����飺";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	int len = ans.size();
	heapsort(ans,len);
	cout << "�����";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}
