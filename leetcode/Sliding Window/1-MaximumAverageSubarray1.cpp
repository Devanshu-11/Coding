class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double count=0;
        double result=INT_MIN;
        
        while(j<k){
            count=count+nums[j];
            j++;
        }
        
        result=max(result,count/k);
        while(j<=nums.size()-1){
            count=count-nums[i]+nums[j];
            i++;
            j++;
            result=max(result,count/k);
        }
        
        return result;
    }
};