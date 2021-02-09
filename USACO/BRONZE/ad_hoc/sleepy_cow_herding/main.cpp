#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

int min_val = INT_MAX;
int max_val = 0;

void result(vector<int> positions, int depth)
{
    int a, b, c;
    int res;
    sort(positions.begin(), positions.end());

    a = positions[0];
    b = positions[1];
    c = positions[2];


    if (c - a == 2)
    {
        min_val = min(min_val, depth);
        max_val = max(max_val, depth);
        return ;
    }
    if (abs(a-b) > 2)
    {
        positions[2] = a+2;
        result(positions, depth+1);
    }
    else if (abs(a-b) > 1)
    {
        positions[2] = a+1;
        result(positions, depth+1);
    }
    positions[2] = c;
    if (abs(b-c) > 2)
    {
        positions[0] = b+2;
        result(positions, depth+1);
    }
    else if (abs(b-c) > 1)
    {
        positions[0] = b+1;
        result(positions, depth+1);
    }
}

int main(void)
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int a, b, c;

    cin >> a >> b >> c;
    if (a>b)swap(a,b);
    if (b>c)swap(b,c);
    if (a>b)swap(a,b);
    if (c-a == 2)
        cout << 0 << endl;
    else if (b-a == 2 || c-b == 2)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    cout << max(b-a, c-b) - 1 << endl;
    
    return (0);
}