class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int n = A.size();
        int a = min_element(A.begin(), A.end()) - A.begin();
        int b = max_element(A.begin(), A.end()) - A.begin();
        int front = max(a, b)+1;
        int back = n-min(a,b);
        int none = min(a, b) + 1 + n - max(a, b);
        return min(front,min(back,none));
    }
};