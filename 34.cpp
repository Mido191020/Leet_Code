34. Find First and Last Position of Element in Sorted Array
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
// It uses the lowerBound and upperBound functions to find the lower and upper bounds of the target element in the sorted array.
// Implement the lowerBound function using a binary search algorithm to find the lower bound of the target element in the sorted array.
// Implement the upperBound function using a binary search algorithm to find the upper bound of the target element in the sorted array.
// In the searchRange function, check if the target element exists in the array using the binary_search function.
// If the target element is found:
// If the array has only one element, push back 0 as the lower and upper bounds into the result vector.
// Otherwise, call the lowerBound and upperBound functions to find the lower and upper bounds of the target element in the array. Push the results into the result vector after adjusting the upper bound by -1.
// If the target element is not found, push back -1 as the lower and upper bounds into the result vector.
// Return the result vector.
