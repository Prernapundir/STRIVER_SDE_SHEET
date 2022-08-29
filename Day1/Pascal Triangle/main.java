class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans=new ArrayList<>();
        List<Integer> prev=null;
        
         for(int i=0;i<numRows;i++){
            // by default keeping all values to be 1 , as first and last vaue will be 1 only
            List<Integer> temp=new ArrayList<>();
            
            for(int j=0;j<=i;j++){
                // for first an dlast index we have to append 1
                // In java list we cant get the element via index , rather we have to do list.get(i) to get particukar index value
                if(j==0 || j==i){
                    temp.add(1);
                    continue;
                }
                 // Take last row two values sum and update 
                temp.add(prev.get(j-1)+prev.get(j));
            }
             
            prev=temp;
            ans.add(temp);
        }
        
        return ans;
    }
}
