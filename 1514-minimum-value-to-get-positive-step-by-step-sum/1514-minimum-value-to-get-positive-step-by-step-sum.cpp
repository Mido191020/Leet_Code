class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_sum=INT_MAX;
        int current_sum=0;
        for(auto it: nums){
            current_sum+=it;
            min_sum=min(min_sum,current_sum);
        }
        return max(1,1-min_sum);
    }
};