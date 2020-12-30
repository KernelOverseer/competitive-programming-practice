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

vector<ull>::iterator get_lower_number(vector<ull> &numbers, ull n)
{
	int low;
	int high;
	int	mid;

	high = numbers.size() - 1;
	low = 0;
	mid = (low + high) / 2;
	while (high >= low)
	{
		if (numbers[mid] == n)
			return numbers.begin() + mid;
		else if (n > numbers[mid])
			low = mid + 1;
		else if (n < numbers[mid])
			high = mid - 1;
		mid = (low + high) / 2;
	}
	return numbers.begin() + mid;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int	n;
	int m;

	cin >> n >> m;
	vector<ull> h(n);
	vector<ull> t(m);
	for(int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < m; i++)
		cin >> t[i];

	sort(h.begin(), h.end());
	for(uint i = 0; i < t.size(); i++)
	{
		auto result = get_lower_number(h, t[i]);
		if (*result <= t[i])
			cout << *result << endl;
		else
			cout << -1 << endl;
		h.erase(result);
	}
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


