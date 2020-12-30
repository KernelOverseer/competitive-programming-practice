#ifdef __linux__
# include <bits/stdc++.h>
#endif
#ifdef __APPLE__
# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <stack>
# include <cmath>
# include <set>
# include <unordered_set>
# include <limits>
# include <algorithm>
#endif
#define NL '\n'
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;

ull mod_exp(ull base, ull exponent, ull mod);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    uint x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;

    uint xx1, xx2, yy1, yy2;

    xx1 = min(x1, x3);
    xx2 = max(x2, x4);
    yy1 = min(y1, y3);
    yy2 = max(y2, y4);

    uint square_side = max(xx2 - xx1, yy2 - yy1);
    cout << square_side * square_side << endl;
    return (0);
}