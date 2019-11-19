#include <iostream>
using namespace std;
int *arr = nullptr;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false); cin.tie(0);
	int k = 0;
	cin >> k;
	arr = new int[k];
	int tmp = 0;
	int max = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		if (arr[i] + tmp < 0) tmp = 0;
		else
		{
			tmp += arr[i];
			if (tmp > max) max = tmp;
		}
	}
	cout << max << endl;
	return 0;
}
