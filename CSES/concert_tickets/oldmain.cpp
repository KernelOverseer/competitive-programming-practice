/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:57:35 by abiri             #+#    #+#             */
/*   Updated: 2020/02/21 22:58:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	vector < pair<int, int> > customers;
	vector < pair<int, int> > tickets;

	int n, m, t;

	cin >> n >> m;
	vector <int> results(m, -1);
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		tickets.push_back(make_pair(t, 0));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		customers.push_back(make_pair(t, i));
	}
//	sort(customers.rbegin(), customers.rend());
	sort(tickets.rbegin(), tickets.rend());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tickets[i].first <= customers[j].first && results[customers[j].second] == -1)
			{
				tickets[i].second = 1;
				results[customers[j].second] = tickets[i].first;
				break ;
			}
		}
	}
/*	int iter;
	iter = 0;
	for (int i = 0; i < m; i++)
	{
		while (iter < n && tickets[iter] > customers[i].first)
			iter++;
		if (iter < n)
		{
			cout << "customer : " << customers[i].second << " pays max : " << customers[i].first << " gets ticket " << tickets[iter] << endl;
			results[customers[i].second] = tickets[iter];
			iter++;
		}
		else
			cout << "customer : " << customers[i].second << " pays max : " << customers[i].first << " gets nothing" << endl;
	}*/
	for (int i = 0; i < m; i++)
		cout << results[i] << endl;
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
