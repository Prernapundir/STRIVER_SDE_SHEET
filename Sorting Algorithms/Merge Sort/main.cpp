/* 

Algorithm
1. Merge Sort is a divide n Conquere technique
2. Here we keep on dividing the array in two equal halves and then combine them in a sorted manner

Time Complexity : O(nlogn)
Space Complexity :O(n)

Applications:
1. Used in linked list sort in nlogn time
2. External Sorting
3. Inversion Count Problem

*/



// Merge function
void merge(vector<int>&arr,int low,int mid,int high){
    vector<int> temp;
    int i=low,j=mid+1;
    
    while(i<=mid and j<=high){
        if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }else{
            temp.push_back(arr[i]);
            i++;
        }
    }
    
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    
    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int k=low;k<=high;k++){
        arr[k]=temp[k-low];
    }
    return;
}


void mergesort(vector<int>&arr,int low,int high){
    if(low>=high) return;
  
    int mid=low+(high-low)/2;
    
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
    
    return;
}

void mergeSort(vector < int > & arr, int n) {
    mergesort(arr,0,n-1);
    return;
}
