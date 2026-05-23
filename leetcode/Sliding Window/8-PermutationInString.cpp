class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // base case
        if(s1.length()>s2.length()){
            return false;
        }
        
        vector<int>s1_string(26,0);
        vector<int>s2_string(26,0);
        
        for(int ind=0;ind<s1.length();ind++){
            int index=s1[ind]-'a';
            s1_string[index]++;
        }
        
        int i=0,j=0;
        // creating the window of size-s1
        for(j=0;j<s1.length();j++){
            int index=s2[j]-'a';
            s2_string[index]++;
        }
        
        // Now expanding the jth index and collapsing the ith index
        while(j<s2.length()){
            if(s1_string==s2_string){
                return true;
            }
            
            // getting the index
            int i_index=s2[i]-'a';
            int j_index=s2[j]-'a';
            
            // updating ith index
            s2_string[i_index]--;
            i++;
            
            s2_string[j_index]++;
            j++;
        }
        
        if(s1_string==s2_string){
            return true;
        }
        
        return false;
    }
};