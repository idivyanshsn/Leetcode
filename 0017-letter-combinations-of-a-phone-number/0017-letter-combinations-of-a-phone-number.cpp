class Solution {
public:
    void function(int ind,string digits,string& ds,vector<string>& ans, vector<string> &mapping){
        if(ind==digits.size()){
            ans.push_back(ds);
            return;
        }
        int digit=digits[ind]-'0';
        string letter=mapping[digit];
        for(int i=0;i<letter.size();i++){
            ds.push_back(letter[i]);
            function(ind+1,digits,ds,ans,mapping);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string ds;
        vector<string> mapping={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        function(0,digits,ds,ans,mapping);
        return ans;
    }
};