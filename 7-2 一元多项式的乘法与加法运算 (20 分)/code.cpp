#include <iostream>
using namespace std;

int** polynomials = nullptr;
int multRes[2100] = { 0 };
int addRes[1001] = { 0 };

int main(int argc, char** argv)
{
	polynomials = new int*[2];
	polynomials[0] = new int[2100] { 0 };
	polynomials[1] = new int[2100] { 0 };
	int k = 0;
	int coe = 0;
	int exp = 0;
	for (int i = 0; i < 2; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> coe >> exp;
			polynomials[i][exp] = coe;
		}
	}
	for (int i = 0; i <= 1000; i++)
	{
		if (polynomials[0][i])
		{
			for (int j = 0; j <= 1000; j++)
			{
				if (polynomials[1][j])
					multRes[i + j] += polynomials[0][i] * polynomials[1][j];
			}
		}
	}
	bool hasPrinted = false;
	for (int i = 2000; i >= 0; i--)
		if (multRes[i]) 
		{
			if (hasPrinted) cout << " ";
			cout << multRes[i] << " " << i;
			hasPrinted = true;
		}
	if (!hasPrinted) cout << "0 0";
	cout << endl;
	for (int i = 0; i <= 1000; i++)
		addRes[i] = polynomials[0][i] + polynomials[1][i];
	hasPrinted = false;
	for (int i = 1000; i >= 0; i--)
		if (addRes[i])
		{
			if (hasPrinted) cout << " ";
			cout << addRes[i] << " " << i;
			hasPrinted = true;
		}
	if (!hasPrinted) cout << "0 0";
	return 0;
}
