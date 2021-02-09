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
    int n;
    string s;

    cin >> n;
    cin >> s;
    for (uint len = 1; len <= n; len++)
    {
        set<string> subs;
        for (uint start = 0; start <= n; start++)
        {
            string sub = s.substr(start, len);
        }
    }
    return (0);
}