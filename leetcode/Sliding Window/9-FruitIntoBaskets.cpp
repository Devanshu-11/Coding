class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>umap;
        int i=0,j=0,result=0;
        
        //define the window
        while(j<fruits.size()){
            if(umap.find(fruits[j])==umap.end()&&umap.size()==2){
                break;
            }
            
            umap[fruits[j]]++;
            j++;
        }
        result=max(result,j-i);
        
        // Now we will collapse the ith index and expand the jth index
        while(j<fruits.size()){
            
            // collapse the ith index
            while(umap.size()!=1){
                umap[fruits[i]]--;
                
                if(umap[fruits[i]]==0){
                    umap.erase(fruits[i]);
                }
                i++;
            }
            
            // expand the jth index
            while(j<fruits.size()){
                if(umap.find(fruits[j])==umap.end()&&umap.size()==2){
                    break;
                }
                
                umap[fruits[j]]++;
                j++;
            }
            
            result=max(result,j-i);
        }
        return result;
    }
};