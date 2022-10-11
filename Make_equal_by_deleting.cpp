#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int rec(string s1, string s2, int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    if (dp[n][m] != -1) return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
    {
        return dp[n][m] =  1 + rec(s1, s2, n - 1, m - 1);
    }
    return dp[n][m] = max(rec(s1, s2, n - 1, m), rec(s1, s2, n, m -1));
}

int main()
{
  memset(dp, -1, sizeof(dp));
  string a, b;
  cin >> a >> b;
  
  int ans = a.size() + b.size() - 2 * rec(a, b, a.size(), b.size());
  
  cout << ans << endl;
  return 0;
}
