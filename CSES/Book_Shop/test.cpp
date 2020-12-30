/* TallMorty (Aymane Biri) */
#ifndef __APPLE__
# include <bits/stdc++.h>
# define M_PI acos(-1)
#endif
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <unordered_set>
#include <limits>
#include <algorithm>

/*
**	START_TEMPLATE
*/

using namespace std;
#define NL '\n'
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> price(n), pages(n);
  for (int&v : price) cin >> v;
  for (int&v : pages) cin >> v;
  vector< vector<int> > dp(n+1,vector<int>(x+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-price[i-1];
      if (left >= 0) {
	dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
      }
    }
  }
  cout << dp[n][x] << endl;
}
