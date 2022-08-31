/*
Gap Method: Shell Sort

Steps:
1. Find the gap = (m+n)/2
2. Take two pointers i=0,j=gap , and whenever arr[i]>arr[j], swap
3. Make gap=gap/2

Time Complexity : O(Logn*n)
*/

class Solution{
    public:
       
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
           int gap = ceil((float)(n + m) / 2);
           
           int i=0,j=gap;
           
           while(gap>0){
               i=0;
               j=gap;
              
               // Do the iteration over the arrays
               while(j<(m+n)){
               if(i>=n){
                   // when i and j both lies in arr2
                   if(arr2[i-n]>arr2[j-n]){
                       swap(arr2[i-n],arr2[j-n]);
                   }
               }else if(i<n and j<n){
                 // when i and j lies in arr1 
                   if(arr1[i]>arr1[j]){
                       swap(arr1[i],arr1[j]);
                   }
               }else if(i<n and j>=n){
                   // when i lies in arr1 and j lies in arr2
                   if(arr1[i]>arr2[j-n]){
                       swap(arr1[i],arr2[j-n]);
                   }
               }
                i++;
                j++;
           }
           
             // make gap half after every iteration
           if (gap == 1) gap = 0;
           else gap = ceil((float) gap / 2);
        }
           return;
        }
};
