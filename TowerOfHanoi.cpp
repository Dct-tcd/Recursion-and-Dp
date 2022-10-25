#include <bits/stdc++.h>
using namespace std;
 
void towerOfHanoi(int n, char src, char dest, char extra)
{
    if (n == 0) 
    {
        return;
    }
    towerOfHanoi(n - 1, src, extra, dest);
    cout << "Move disk " << n << " from rod " << src << " to rod " << dest << endl;
    towerOfHanoi(n - 1, extra, dest, src);
}
 
int main()
{
    int n;
    cin>>n;
    // A, B and C are names of rods
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
