class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        string str="aeiouAEIOU";
        while (left < right) {
            while(str.find(s[left])==string::npos && left<right) left++;
            while(str.find(s[right])==string::npos&& left<right) right--;
            if(left<right){
                swap(s[left],s[right]);
                left++,right--;
            }
        }
        return s;
    }
};