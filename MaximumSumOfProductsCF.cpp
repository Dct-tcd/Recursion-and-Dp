#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int modpowIter(int a, int b, int c)
{
        int ans = 1;
        while (b != 0)
        {
                if (b % 2 == 1)
                        ans = (ans * a) % c;

                a = (a * a) % c;
                b /= 2;
        }
        return ans;
}
vector<ll>a(5000);
vector<ll>b(5000);
ll dp[5000][5000];
ll compute(int i,int j)
{
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(i==j)
        return dp[i][j]=a[i]*b[i];
        if(abs(i-j)==1)
        {
                return dp[i][j]=a[i]*b[j]+a[j]*b[i];
        }
        return dp[i][j]=a[i]*b[j]+b[i]*a[j]+compute(i+1,j-1);
}
int main()
{


                ll n;
                cin>>n;
                memset(dp,-1,sizeof(dp));
                for(int i=0;i<n;i++)
                {
                        cin>>a[i];
                }
                for(int i=0;i<n;i++)
                {
                        cin>>b[i];
                }
                vector<ll>pref(n);
                vector<ll>suff(n);
                pref[0]=0;
                suff[n-1]=0;
                for(int i=1;i<n;i++)
                {
                        pref[i]=a[i-1]*b[i-1]+pref[i-1];
                }
                for(int i=n-2;i>=0;i--)
                {
                        suff[i]=a[i+1]*b[i+1]+suff[i+1];
                }
                ll ans=0;
                for(int i=0;i<n;i++)
                {
                        for(int j=i;j<n;j++)
                        {
                                ans=max(pref[i]+compute(i,j)+suff[j],ans);
                        }
                }
                cout<<ans<<endl;
        }
                
