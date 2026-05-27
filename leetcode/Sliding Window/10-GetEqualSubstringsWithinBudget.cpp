class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0,result=0;
        while(j<s.length()){
            if(maxCost-(abs((s[j]-'a')-(t[j]-'a')))>=0){
                maxCost=maxCost-(abs((s[j]-'a')-(t[j]-'a')));
                j++;
                result=max(result,j-i);
            }else{
                maxCost=maxCost+(abs((s[i]-'a')-(t[i]-'a')));
                i++;
            }
        }
        result=max(result,j-i);
        return result;
    }
};