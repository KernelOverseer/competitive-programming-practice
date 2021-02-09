#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

int main(void)
{
    freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);
    int n;
    string city, state;

    cin >> n;
    int relations = 0;
    map<string, int> state_city;
    while (n--)
    {
        cin >> city >> state;
        city = city.substr(0, 2);
        state_city[state+city]++;
    }
    cout << relations << endl;
    return (0);
}