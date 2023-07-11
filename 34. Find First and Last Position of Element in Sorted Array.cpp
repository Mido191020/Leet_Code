
class Solution {
public:
    int lowerBound(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// Upper Bound Algorithm
int upperBound(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}
vector<int> searchRange(vector<int>& nums, int target) {
vector<int>v;
    if (binary_search(nums.begin(),nums.end(),target)){
        if (nums.size()==1){
           v.push_back(0);
           v.push_back(0);
        } else
        {
           v.push_back(lowerBound(nums,target));
        v.push_back(upperBound(nums,target)-1);
        }
    } else
    {
        v.push_back(-1);
        v.push_back(-1);
    }
    return v;
}
};