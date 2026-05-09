class Solution {
    bool isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
            return true;
        }
        
        return false;
    }
    
public:
    int maxVowels(string s, int k) {
        int window_count=0,i=0,j=0,result=0;
        for(i=0;i<k;i++){
            if(isVowel(s[i])){
                window_count++;
            }
        }
        result=max(result,window_count);
        
        while(i<s.length()){
            // collase left side
            if(isVowel(s[j])){
                window_count--;
            }
            
            // expland right side
            if(isVowel(s[i])){
                window_count++;
            }
            
            j++;
            i++;
            result=max(result,window_count);
        }
        
        return result;
    }
};