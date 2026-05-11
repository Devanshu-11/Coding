class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>umap;
        int i=0,j=0;
        int window_sum=0;
        int result=0;
        
        while(j<nums.size()){
            if(umap.find(nums[j])==umap.end()){
                umap[nums[j]]++;
                window_sum=window_sum+nums[j];
                j++;
            }else{
                window_sum=window_sum-nums[i];
                umap.erase(nums[i]);
                i++;
            }
            
            result=max(result,window_sum);
        }
        
        return result;
    }
};