/*
 * Use square root decomposition for addition in array.
 * Given array should have static length(length should not change).
*/
#include <iostream>
#include <cmath>

using namespace std;

/*
 * Initializes the Decomposed arrray
 */
void preprocess(int arr[],int n,int block[],int block_size)
{
    int initial_index=-1;
    for(int i=0;i<n;i++)
    {
        if(i%block_size==0)                 // next block reached 
            initial_index++;
        block[initial_index]+=arr[i];
    }
}

/*
 * Updates index "idx" of array "arr" to value "val".
 * We have to make changes in "block" also.
 * Done in O(1) time.
*/ 
void update(int arr[],int block[],int idx,int val,int block_size)
{
    int block_number=idx/block_size;
    block[block_number]+=val-arr[idx];
    arr[idx]=val;
}

/*
 * Returns sum from range l...r of "arr" in O(sqrt(n)) time. 
 */
int query(int arr[],int block[],int block_size,int l,int r)
{
    int sum=0;
    while(l<r && l%block_size!=0)    // Case 1: l...r does not fit leftmost block completely
    {                                // So sum from "arr" individually till we reach next block
        sum+=arr[l];
        l++;
    }
    while(l+block_size<=r)           // Case 2: Now, check if next block exists and completely falls in given range 
    {
        sum+=block[l/block_size];
        l+=block_size;
    }
    while(l<=r)                      // Case 3: Similar to Case 1, but in right side  
    {
        sum+=arr[l];
        l++;
    }
    return sum;
} 

int main()
{
    int n=10;                       // Size of given array
    int block_size=sqrt(n);         // Size of each block
    int no_of_blocks=ceil(sqrt(n)); // No. of blocks                     
    int block[no_of_blocks];        // Decomposed array
    
    for(int i=0;i<no_of_blocks;i++)
        block[i]=0;
    int arr[]={2,3,5,6,4,0,-2,1,9,-1};      // Original array
    preprocess(arr,n,block,block_size);
    cout<<query(arr,block,block_size,0,9);
    cout<<endl;
    cout<<query(arr,block,block_size,5,9);
    cout<<endl;
    update(arr,block,9,6,block_size);
    cout<<query(arr,block,block_size,0,9)<<endl;
    return 0;
}
