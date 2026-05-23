class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int i=-1,j=-1,window_sum=0;
        int n=code.size();
        vector<int>result(n,0);
        
        if(k==0){
            return result;
        }
        
        if(k>0){
            i=1;
            j=k;
        }else{
            i=n-abs(k);
            j=n-1;
        }
        
        // find the sum of sliding window 
        for(int index=i;index<=j;index++){
            window_sum=window_sum+code[index];
        }
        
        // we are thinking to move them in one direction only
        for(int index=0;index<n;index++){
            result[index]=window_sum;
            window_sum=window_sum-code[i%n]+code[(j+1)%n];
            i++;
            j++;
        }
        return result;
    }
};