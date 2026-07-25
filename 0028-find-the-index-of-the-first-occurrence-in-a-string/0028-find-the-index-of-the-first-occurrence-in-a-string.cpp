class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        for(int i=0;i<haystack.size();i++){
            if(needle==haystack.substr(i,n))
                return i;
        }
        return -1;
    }
};