class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0,maxLen=0;
        unordered_map<int,int> hash;
        for(int right=0;right<s.size();right++){
            hash[s[right]]++;
            while(hash[s[right]]>2){
                hash[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};