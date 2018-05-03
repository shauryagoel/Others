/*
 * Sparse Table to find sum of all elements in a given range in O(log(n))
 * Array should be static 
 */ 
#include <iostream>
#include <cmath>

using namespace std;
int table[1000][1000];        // Sparse table

/*
 * Build the sparse table in O(nlog(n))
 */
void build(int arr[],int n,int k) 
{
    for(int i=0;i<n;i++)
        table[i][0]=arr[i];
    for(int j=1;j<=k;j++)
        for(int i=0;i+(1<<j)<=n;i++)
            table[i][j]=table[i][j-1]+table[i+(1<<(j-1))][j-1];
}

/*
 * Output sum in range l...r in O(log(n))
 */ 
int query(int arr[],int n,int k,int l,int r)
{
    int ans=0;
    for(int j=k;j>=0;j--)
    {
        if(l+(1<<j)-1<=r)
        {
            ans+=table[l][j];
            l+=(1<<j);
        }
    }
    return ans;
}
int main()
{
    int arr[]={2,4,1,4,2,0,8,-1,-9,-3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=log2(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<k+1;j++)
            table[i][j]=0;
    build(arr,n,k);
    cout<<query(arr,n,k,0,n-4);
    cout<<endl;
    return 0;
}
