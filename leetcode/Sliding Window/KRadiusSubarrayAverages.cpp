class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result(n,-1);
        int i=0,j=0;
        long long window_sum=0;
        int index=k;
        
        if(2*k+1>n){
            return result;
        }
        
        while(j<=2*k){
            window_sum=window_sum+nums[j];
            j++;
        }
        
        result[index]=window_sum/((2*k)+1);
        index++;
        
        while(j<=n-1){
            window_sum=window_sum-nums[i]+nums[j];
            result[index]=window_sum/(2*k+1);
            i++;
            j++;
            index++;
        }
        
        return result;
    }
};