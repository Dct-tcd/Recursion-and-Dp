// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;
int dp[1001][10000];
// // top-down approach
// void solve(vector<int>& vp, int n,int sum)
// {
//     int i,j,k;
//     // initialization
//     for(i=0;i<=sum;i++)
//     {
//         dp[0][i]=0;
//     }
//     for(i=0;i<=n;i++)
//     {
//         dp[i][0]=1;
//     }

//     // calculation
//     for(i=1;i<=n;i++)
//     {
//         for(j=1;j<=sum;j++)
//         {
//             if(j<vp[i-1])
//             dp[i][j]=dp[i-1][j];
//             else
//             dp[i][j]=dp[i-1][j] + dp[i-1][j-vp[i-1]];
//         }
//     }
//     // for(i=0;i<=n;i++)
//     // {
//     //     for(j=0;j<=sum;j++)
//     //     cout<<dp[i][j]<<" ";
//     //     cout<<"\n";
//     // }
// }

// int countSub(vector<int>& vp, int n, int diff)
// {
// 	   int i,j,k,sum=0,count=0;
//        if((diff+sum)%2)
//        return 0;
//        for(auto itr:vp)
//        sum+=itr;
//        solve(vp,n,sum);
       
//        return dp[n][(diff+sum)/2];
    

// }

// Driver code
// memoization
int solve(vector<int>& vp, int n,int cap )
{
    int i,j,k;
    // base conditions
    if(cap==0)
    return 1;
    if(n==0)
    return 0;
    // pre calculated 
    if(dp[n][cap]!=-1)
    return dp[n][cap];

    // main function call
    if(vp[n-1]>cap)
    return dp[n][cap]=solve(vp,n-1,cap);
    else
    return dp[n][cap]=solve(vp,n-1,cap)+solve(vp,n-1,cap-vp[n-1]);

}

int countSub(vector<int>& vp, int n, int diff)
{
	   int i,j,k,sum=0,count=0;
     
       for(auto itr:vp)
       sum+=itr; 
        if((diff+sum)%2)
       return 0;
       memset(dp,-1,sizeof(dp));
       solve(vp,n,(diff+sum)/2);
        for(i=0;i<=n;i++)
    {
        for(j=0;j<=sum;j++)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
       
       return dp[n][(diff+sum)/2];
    

}
int main()
{
	int N = 5;
	vector<int> arr = { 1, 2, 3, 1, 2 };
	int diff = 1;
	

	// Function call
	cout << countSub(arr, N, diff) << endl;
	return 0;
}



