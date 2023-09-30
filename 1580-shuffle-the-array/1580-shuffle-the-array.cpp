class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> x(nums.begin(), nums.begin() + n);
        vector<int> y(nums.begin() + n, nums.end());
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            res.push_back(x[i]);
            res.push_back(y[i]);
        }
        
        return res;
    }
};