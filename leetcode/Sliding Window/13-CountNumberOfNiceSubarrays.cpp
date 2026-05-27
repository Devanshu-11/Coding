class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int result=0;
        int oddSum=0;
        umap[oddSum]++;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                oddSum++;
            }
            
            umap[oddSum]++;
            if(umap.find(oddSum-k)!=umap.end()){
                result=result+umap[oddSum-k];
            }
        }
        
        return result;
    }
};