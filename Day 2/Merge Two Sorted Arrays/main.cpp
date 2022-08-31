/*
/*

Approach : Without using extra space

1. Iterate the array1 , and whenever we get any value greater than arr2[0] , swap them
2. Now rearramge the arr2 

Time Complexity : O(n*m)
Space Complexity : O(1)

*/


class Solution{
    public:
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i=0;
            
            while(i<n){
                if(arr1[i]>arr2[0]){
                    swap(arr1[i],arr2[0]);
                    
                    int val=arr2[0];
                  
                  // rearrange the array2
                  
                    for(int k=1;k<m;k++){
                        if(arr2[k]<val){
                            arr2[k-1]=arr2[k];
                        }else{
                            arr2[k-1]=val;
                            break;
                        }
                    }
                }
                
                i++;
            }
        } 
};
