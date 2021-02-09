#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned char uchar;

// #define DEBUG
#define MOD 1000000007

bool step_to_sort(vector<int> &order)
{
    int current;
    int current_pos;

    current = order[0];
    current_pos = current-1;

}

int main(void)
{
    // freopen("sleepy.in", "r", stdin);
    // freopen("sleepy.out", "w", stdout);

    int         n,id;
    vector<int> order;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        order.push_back(id);
    }
    cout << steps_to_sort(order) << endl;
    return (0);
}