#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n, steps; vector<vector<int>> adj; vector<int> L,R;
 
int dfs(int s) {
    int here = 0;
    for(int i: adj[s]) {
        here += dfs(i);
    }
    if(here < L[s]) {steps++; return R[s];}
    return min(R[s], here);
}
 
signed main() {
    int t; cin >> t;
    while(t--) {
        steps = 0;
        cin >> n; adj.assign(n,{}); L.assign(n, 0); R.assign(n, 0);
        for(int i = 1; i < n; i++) {
            int p; cin >> p;
            adj[--p].push_back(i);
        }
        for(int i = 0; i < n; i++)  cin >> L[i] >> R[i]; 
        dfs(0); cout << steps << endl;
    }
}
