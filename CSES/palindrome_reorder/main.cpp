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

ull mod_exp(ull base, ull exponent, ull mod);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	string s;
	vector < pair<int, char> >letters(26, make_pair(0, 0));

	cin >> s;
	string result(s);
	for (uint i = 0; i < s.size(); i++)
	{
		result[i] = '-';
		letters[s[i] - 'A'].first++;
		letters[s[i] - 'A'].second = s[i];
	}
	sort(letters.rbegin(), letters.rend());
	int error = 0;
	int offset = 0;
	int lastindex = -1;
	for (uint i = 0; i < 26 && letters[i].first > 0; i++)
	{
		if (letters[i].first & 1)
		{
			error += 1;
			lastindex = i;
			if (error <= 1)
				continue ;
		}
		if (error > 1)
			break;
		for (int j = 0; j < letters[i].first; j++)
		{
			if (j & 1)
				result[offset + j/2] = letters[i].second;
			else
				result[s.size() - offset - j/2 - 1] = letters[i].second;
		}
		offset += letters[i].first / 2;
	}
	if (lastindex != -1)
	{
		int i = lastindex;
		for (int j = 0; j < letters[i].first; j++)
		{
			if (j & 1)
				result[offset + j/2] = letters[i].second;
			else
				result[s.size() - offset - j/2 - 1] = letters[i].second;
		}
	}
	if (error > 1)
		cout << "NO SOLUTION" << endl;
	else
		cout << result << endl;
	return (0);
}

ull mod_exp(ull base, ull exponent, ull mod)
{
    base %= mod;
    ull res = 1;
    while (exponent > 0) {
        if (exponent & 1)
            res = res * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    return res;
}


