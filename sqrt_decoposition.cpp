// This algorithm is used basically for calculating the sum the array elements 
// present bw the given 2 indices more effeciently than any other method.
// The kick here is that we have to calculate the sum of elements bw the indices
// many a times ie of order 1e5 ,which would cause time complexity if done by the 
//naive approach ie{by for loop} time complexity would be O(n*m) , n queries and m
//elements in the given range {worst case m==total no of elements}
// Using this algo we can reduce the time complexity to O(n*sqrt(m));
//https://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
// https://www.youtube.com/watch?v=tuxMRkKuP8Y&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=217
// time complexity would be O(n*m)
// Space complexity O(n) 
//{Online query processing is used in this method}
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
void sqrt_decomposition(vector<int>&v1,int arr[],int n,int len)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        v1[i/len]+=arr[i]; /// This is the most important part of the algorithm   
    }                      /// Here we make a single block which consist sum of the
                           /// next len numbers present in the array7
  }

int main ()
{
   int n,q,i,j,k,len;
   cout<<"Enter the no of elements\n";
   cin>>n;
   int arr[n];
   len=(int)sqrt(n);
   cout<<len<<" ";
   if(len*len!=n)
   len=len+1;
   vector<int>v1(len);
   cout<<"Enter the value of elements\n";
   for(i=0;i<n;i++)
   cin>>arr[i];
   sqrt_decomposition(v1,arr,n,len);
   cout<<"Enter the number of queries\n";
   cin>>q;
   while(q--)
   {
    int a,b,sum=0;
    cout<<"Enter the range of the query\n";
    cin>>a>>b;
    a--,b--;
    for(i=a;i<=b;)
    {
        if(i%len==0 && i+len-1<=b)
        {
           sum+=v1[i/len];
           i+=len;
        }
        else
        {
            sum+=arr[i];
            i++;

        }
    }
  cout<<sum<<"\n";
   }

return 0;
}

// // test case :-
// Enter the no of elements
// 7
// 2 Enter the value of elements
// 1 3 -2 5 1 3 -7
// Enter the number of queries
// 4
// Enter the range of the query
// 1 7
// 4
// Enter the range of the query
// 4 5
// 6
// Enter the range of the query
// 3 6
// 7
// Enter the range of the query
// 1 4
// 7