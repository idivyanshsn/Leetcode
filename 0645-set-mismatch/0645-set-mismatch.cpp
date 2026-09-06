class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> arr;
        for(int i =0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int dup=-1;
        int miss=-1;
        for(int i=0;i<=nums.size();i++){
            if(hash[i]==0){
                miss=i;
            }
            if(hash[i]==2){
                dup=i;
            }
        }
        return {dup,miss};
    }
};