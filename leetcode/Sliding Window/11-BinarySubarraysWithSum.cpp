class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>umap;
        
        // Initially prefix sum is 0 once
        umap[0]++;
        
        // sum stores current index sum and result is total no of subarray
        int sum=0,result=0;
        
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            umap[sum]++;
            
            // check if (sum-goal) is found in hashmap or not
            if(umap.find(sum-goal)!=umap.end()){
                result=result+umap[sum-goal];
            }
        }
        
        // special case for handling goal if the value is 0
        if(goal==0){
            return result-nums.size();
        }
        
        return result;
    }
};