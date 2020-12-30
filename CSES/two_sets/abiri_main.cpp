/*
 *      ╔═╗┬ ┬┌┬┐┌─┐┌┐┌┌─┐  ╔╗ ┬┬─┐┬
 *      ╠═╣└┬┘│││├─┤│││├┤   ╠╩╗│├┬┘│
 *      ╩ ╩ ┴ ┴ ┴┴ ┴┘└┘└─┘  ╚═╝┴┴└─┴
 *      1337 Coding School Khouribga
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <limits>
#include <algorithm>
#define NL '\n'
using namespace std;

typedef unsigned long long ull;
typedef unsigned int uint;

int main(void)
{
	vector <int> 	set1;
	vector <int> 	set2;
	unsigned long long	size1;
	unsigned long long	size2;
	int				n;

	size1 = 0;
	size2 = 0;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		if (size1 > size2)
		{
			set2.push_back(i);
			size2 += i;
		}
		else
		{
			set1.push_back(i);
			size1 += i;
		}
	}
	if (size1 == size2)
	{
		cout << "YES" << endl;
		cout << set1.size() << endl;
		for (uint i = 0; i < set1.size(); i++)
			cout << set1[i] << " ";
		cout << NL;
			cout << set2.size() << endl;
		for (uint i = 0; i < set2.size(); i++)
			cout << set2[i] << " ";
		cout << NL;
	}
	else
		cout << "NO" << endl;
	return (0);
}
