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
	vector <int> letters(26, 0);
	cin >> s;
	for (uint i = 0; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			cout << "error in index : " << i << endl;
			exit(0);
		}
		letters[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++)
		cout << (char)('A' + i) << " : " << letters[i] << endl;
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


