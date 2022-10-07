/* Dynamic Programming implementation of Min Cost path problem */
#include<limits.h>
#include <bits/stdc++.h>
#define R 3
#define C 3
using namespace std;
int min(int a, int b, int c);

int minCost(int cost[R][C], int m, int n)
{
	
	int tc[R][C];

	tc[0][0] = cost[0][0];

	
	for (int i = 1; i <= m; i++)
		tc[i][0] = tc[i - 1][0] + cost[i][0];

	
	for (int j = 1; j <= n; j++)
		tc[0][j] = tc[0][j - 1] + cost[0][j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			tc[i][j] = min(tc[i - 1][j - 1],
						tc[i - 1][j],
						tc[i][j - 1]) + cost[i][j];

	return tc[m][n];
}

int min(int a, int b, int c)
{
if (a < b)
	return (a < c)? a : c;
else
	return (b < c)? b : c;
}


int main()
{
int cost[R][C] = { {21, 22, 23},
					{44, 82, 22},
					{22, 45, 24} };
cout << " " << minCost(cost, 22, 22);
return 0;
}

// This code is contributed by Moksh Gupta
