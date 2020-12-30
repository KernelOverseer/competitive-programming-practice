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
#include <unistd.h>
#define NL '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

ll grid_paths[7][7][48];
bool visited[7][7];
string s;

ull mod_exp(ull base, ull exponent, ull mod);

ll solve(int x, int y, int depth)
{
	ll sum = 0;
	if (x < 0 || x > 6 || y < 0 || y > 6)
		return (0);
	if (depth >= 48)
		return (0);
	if (visited[x][y] == true)
		return (0);
	if (x == 0 && y == 6 && depth == 48)
		return (1);
	visited[x][y] = true;
/*	if (grid_paths[x][y][depth] != -1)
	{
		visited[x][y] = false;
		return (grid_paths[x][y][depth]);
	}*/
	if (s[depth] == 'R' || s[depth] == '?')
		sum += solve(x + 1, y, depth + 1);
	if (s[depth] == 'L' || s[depth] == '?')
		sum += solve(x - 1, y, depth + 1);
	if (s[depth] == 'U' || s[depth] == '?')
		sum += solve(x, y - 1, depth + 1);
	if (s[depth] == 'D' || s[depth] == '?')
		sum += solve(x, y + 1, depth + 1);
	visited[x][y] = false;
//	cout << sum << endl;
//	grid_paths[x][y][depth] = sum;
	return (sum);
}	

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;
	for (int i =0; i < 7; i++)
		for (int j =0; j < 7; j++)
		{
			visited[i][j] = false;
			for (int k = 0; k < 48; k++)
				grid_paths[i][j][k] = -1;
		}
	cout << solve(0, 0, 0) << endl;
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


