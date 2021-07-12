#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> ans = { 3,7,1,3,22,6,9,2,4,6 };
	cout << "ÅÅÐòÇ°£º";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;
	bool flag = true;
	for (int i = 0; i < ans.size()&&flag; i++)
	{
		flag = false;
		for (int j = ans.size() - 2; j >= 0; j--)
		{
			if (ans[j] > ans[j + 1])
			{
               swap(ans[j], ans[j + 1]);
			   flag = true;
			}
				
		}
	}
	cout << "ÅÅÐòºó£º";
	for (auto &num : ans)
		cout << num << " ";
	cout << endl;

	return 0;
}