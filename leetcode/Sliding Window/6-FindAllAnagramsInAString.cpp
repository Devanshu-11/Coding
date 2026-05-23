class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>p_string(26,0);
        vector<int>s_string(26,0);
        vector<int>ans;

        // edge case
        if(p.length()>s.length()){
            return ans;
        }
        
        for(int ind=0;ind<p.length();ind++){
            int index=p[ind]-'a';
            p_string[index]++;
        }
        
        // create window
        int i=0,j=0;
        for(j=0;j<p.length();j++){
            int index=s[j]-'a';
            s_string[index]++;
        }
        
        while(j<s.length()){
            if(p_string==s_string){
                ans.push_back(i);
            }
            
            // getting the index
            int i_index=s[i]-'a';
            int j_index=s[j]-'a';
            
            // updating ith index
            s_string[i_index]--;
            i++;
            
            s_string[j_index]++;
            j++;
        }
        
        if(p_string==s_string){
            ans.push_back(i);
        }
        
        return ans;
    }
};