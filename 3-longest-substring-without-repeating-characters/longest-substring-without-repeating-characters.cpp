class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hasharr[256];
        for(int i =0;i<256;i++){
            hasharr[i]=-1;
        }
        int right=0;
        int left=0;
        int maxlen=0;
        int n = s.size();
        while(right<n){
            if(hasharr[s[right]]!=-1){
                left=max(hasharr[s[right]]+1,left);
            }
            int len=right-left+1;
            maxlen=max(maxlen,len);
            hasharr[s[right]]=right;
            right++;
        }
        return maxlen;
    }
};