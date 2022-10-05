//If we have to find a sum of  all elements of the given range of a subarray 
//and also we have to update some of the values ,for this there are generally 2 methods 
//1-> Naive updation in value ,then calculating the sum of the given range
// Time Complexity  updation->O(1) QueryProcessing->O(n) ie {range of the query}
// 2->Using Prefix Sum ,but here updation of a value in the array is costly
// Time Complexity  updation->O(n) QueryProcessing->O(1) ie {pref[r]-pre[l-1]} l and r are the range of the query
//
// Now if suppose there are large no of queries and Updation ,then also we can solve
// the question using Segment tree method in the Time Complexity of O(N(logN)) both the
// operations
// Concept used is divide and Conqueor 
//Time Complexity  updation->O(N(logN)) QueryProcessing->O(N(logN)) ie {range of the query}
//https://youtu.be/c6GDAgiX5Yw


#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int segment[4*N],arr[N];

void Segmentation(int node,int start,int end)
{
    if(start==end){
    segment[node]=arr[start];
    return;}
    else
    {
        int mid=(start+end)/2;
        Segmentation(2*node,start,mid);
        Segmentation(2*node+1,mid+1,end);
        segment[node]=segment[2*node]+segment[2*node+1];
    }

}
int solve(int node,int start,int end,int a,int b)
{
    if(a>end || b<start)
    return 0;
    if(a<=start && b>=end)
    return segment[node];
    else
    {
        int mid=(start+end)/2;
        int l=solve(2*node,start,mid,a,b);
        int r=solve(2*node+1,mid+1,end,a,b);
        return l+r;
    }
 
}


int main ()
{
    int i,q,j,k,n;
    cout<<"Enter the no of elements\n";
    cin>>n;
    cout<<"Enter the value of elements\n";
  
  for(i=0;i<n;i++)
  cin>>arr[i];
  Segmentation(1,0,n-1);
  cout<<"enter the no. of queries\n";
  cin>>q;
  while(q--)
  {
    int a,b;
    cout<<"enter the queries"<<": ";
    cin>>a>>b;
    cout<<"\n"; 
    a--,b--;
    cout<<solve(1,0,n-1,a,b)<<"\n";
  }

}

// Test Case:-
// Enter the no of elements
// 8
// Enter the value of elements
// 5 3 2 4 1 8 6 10
// enter the no. of queries
// 5
// enter the queries: 1 2

// 8
// enter the queries: 1 3

// 10
// enter the queries: 4 6

// 13
// enter the queries: 7 8

// 16
// enter the queries: 1 8

// 39