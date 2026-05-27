class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,maxFreq=0,maxWindow=0;
        vector<int>freq(26,0);
        
        for(j=0;j<s.length();j++){
            // update frequency of current char 
            freq[s[j]-'A']++;
            
            // update max Frequency 
            maxFreq=max(maxFreq,freq[s[j]-'A']);
            
            while((j-i+1)-maxFreq>k){
                freq[s[i]-'A']--;
                i++;
                
                // now recompute frequency
                maxFreq=0;
                for(auto it:freq){
                    maxFreq=max(maxFreq,it);
                }
            }
            
            maxWindow=max(maxWindow,(j-i+1));
        }
        
        return maxWindow;
    }
};