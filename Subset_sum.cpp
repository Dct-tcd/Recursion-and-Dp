


#include<bits/stdc++.h> 
using namespace std; 



//memoization
int dp[101][100001];
class Solution{   
public:

int solve(int n,vector<int>arr,int req_sum)
{
    
    if(req_sum==0)
    {
        return 1;
    }
    if(n==0||req_sum<0)
    {
        
        return 0;
    }
    if(dp[n][req_sum]!=-1)
    return dp[n][req_sum];
    else
    return dp[n][req_sum]=( solve(n-1 , arr,req_sum-arr[n-1])||solve(n-1, arr,req_sum));
    
    
}
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
      return solve(n,arr,sum) ;
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 


// class Solution{   
// public:
// top-down approach
//     bool isSubsetSum(vector<int>arr, int sum){
//        int i,j,k,sz=arr.size();
//        bool dp[sz+1][sum+1];
//        for(j=0;j<=sum;j++)
//        dp[0][j]=false;
//        for(i=0;i<=sz;i++)
//        dp[i][0]=true;
//        for(i=1;i<=sz;i++)
//        {
//            for(j=1;j<=sum;j++)
//            {
//               if(arr[i-1]>j)
//               dp[i][j]=dp[i-1][j];
//               else if(arr[i-1]<=j)
//               dp[i][j]=(dp[i-1][j]|| dp[i-1][j-arr[i-1]]);
//            }
//        }
//       return dp[sz][sum];
       
//     }
// };

