class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied_customers=0;
        for(int ind=0;ind<customers.size();ind++){
            if(grumpy[ind]==0){
                satisfied_customers=satisfied_customers+customers[ind];
            }
        }
        
        int i=0;
        int j=0;
        
        // initially defined window_count as total satisfied customers
        int window_count=satisfied_customers;
        int result=0;
        
        // creating window
        for(j=0;j<minutes;j++){
            if(grumpy[j]==1){
                window_count=window_count+customers[j];
            }
        }
        
        // now we will expand jth index and collapse ith index
        while(j<customers.size()){
            result=max(result,window_count);
            if(grumpy[i]==1){
                window_count=window_count-customers[i];
            }
            
            if(grumpy[j]==1){
                window_count=window_count+customers[j];
            }
            
            i++;
            j++;
        }
        
        result=max(result,window_count);
        return result;
    }
};