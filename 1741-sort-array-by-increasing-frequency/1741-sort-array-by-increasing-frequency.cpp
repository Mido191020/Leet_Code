class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
    // Count the frequency of each number using an unordered_map
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Custom sorting comparator: Sort by frequency in ascending order, and if frequencies are equal, sort by value in descending order
    auto comparator = [&freq](int a, int b) {
        if (freq[a] == freq[b]) {
            return a > b;
        }
        return freq[a] < freq[b];
    };

    // Sort the nums vector using the custom comparator
    std::sort(nums.begin(), nums.end(), comparator);

    return nums;
    }
};