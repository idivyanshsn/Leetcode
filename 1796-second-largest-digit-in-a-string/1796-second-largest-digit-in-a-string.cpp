class Solution {
public:
    int secondHighest(string s) {
        vector<int> nums;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<=57){
                nums.push_back(s[i]-'0');
            }
        }
        int largest=-1;
        int second=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>largest){
                second=largest;
                largest=nums[i];
            }
            else if(nums[i]>second && nums[i]!=largest){
                second=nums[i];
            }
        }
        return second;
    }
};