/* Approach 

Negative marking Approach :
----------------------------------

1. Simliar to find the duplication number , once duplicat number has found
2. Now iterate again the array and check who is left without marking negative

*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;
	  int repeat,missing;

    for(int i=0;i<arr.size();i++){
        int val=abs(arr[i]);
        if(arr[val-1]<0){
            repeat=val;
        }else arr[val-1]*=-1;
    }

    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            missing=i+1;
            break;
        }
    }
 
    ans.first=missing;
    ans.second=repeat;
    return ans;
}
