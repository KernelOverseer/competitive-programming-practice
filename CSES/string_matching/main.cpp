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
#include <set>
#include <unordered_set>
#include <limits>
#include <algorithm>
#define NL '\n'
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;

ull mod_exp(ull base, ull exponent, ull mod);

ull	number_of_matches(string haystack, string needle)
{
	ull matches = 0;

	for (uint i = 0; i < haystack.size(); i++)
	{
//		cout << haystack[i] << " : ";
		for (uint j = 0; j < needle.size(); j++)
		{
//			cout << "j";
			if (haystack.size() - i < needle.size())
			{
				break;
				i = haystack.size();
			}
			if (haystack[i+j] != needle[j])
				break;
			else if (j == needle.size() - 1)
			{
				matches++;
//				i += j;
			}
		}
//		cout << endl;
	}
	return (matches);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string h, n;

	cin >> h >> n;
	cout << number_of_matches(h, n) << endl;
	return (0);
}
