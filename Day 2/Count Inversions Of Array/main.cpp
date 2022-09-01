/*

Approach
1. Use merge Sort to count the inversions 
2. While merging he sorted arrays , count the inversions

Time Complexity : O(nlogn) 

*/

int merge(long long *arr,int low,int mid,int high){
    int temp[high-low+1];
    int i=low,j=mid+1,k=0;
    int inv_count=0;
    
    while(i<=mid and j<=high){
        if(arr[i]>arr[j]){
            // count inversions
            inv_count+=mid-i+1;
            temp[k]=arr[j];
            j++;
        }else{
            temp[k]=arr[i];
            i++;
        }
        k++;
    }
    
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    
    while(j<=high){
        temp[k]=arr[j];
        k++;
        j++;
    }
    
    for(int p=low;p<=high;p++){
        arr[p]=temp[p-low];
    }
    return inv_count;
}

int mergeSort(long long *arr,int low,int high){
    if(low>=high) return 0;
    
    int inv_count=0;
    int mid=low+(high-low)/2;
    inv_count+=mergeSort(arr,low,mid);
    inv_count+=mergeSort(arr,mid+1,high);
    inv_count+=merge(arr,low,mid,high);
    
    return inv_count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}
