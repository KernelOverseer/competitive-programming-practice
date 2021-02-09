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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    uint n, k, c;
    cin >> k >> n;
    vector < vector<int> >    initial_diff(n, vector<int>(n, 0));
    int result = (n * (n-1)) / 2;
    for (uint i = 0; i < k; i++)
    {
        vector<int> pos(n);
        for(uint j = 0; j < n; j++)
        {
            cin >> c;
            pos[c-1] = j;
        }
        for (uint c1 = 0; c1 < n; c1++)
        {
            for (uint c2 = c1+1; c2 < n; c2++)
            {
                int diff;

                if (pos[c1] > pos[c2])
                    diff = 1;
                else
                    diff = -1;
                if (i == 0)
                {
                    initial_diff[c1][c2] = diff;
                    initial_diff[c2][c1] = diff;
                }
                else
                {
                    if (initial_diff[c1][c2] != 0 && initial_diff[c1][c2] != diff)
                    {
                        initial_diff[c1][c2] = 0;
                        initial_diff[c2][c1] = 0;
                        result--;
                    }
                }
            }
        }
    }
    cout << result << endl;
    return (0);
}