class Solution {
public:
   vector<int> decompressRLElist(std::vector<int>& nums) {
    vector<std::pair<int, int>> pairs;
    for (int i = 0; i < nums.size(); i += 2) {
        pairs.emplace_back(nums[i], nums[i + 1]);
    }

    std::vector<int> result;
    for (const auto& pair : pairs) {
        int freq = pair.first;
        int val = pair.second;
        // Append 'freq' number of 'val' to the result vector.
        for (int j = 0; j < freq; ++j) {
            result.push_back(val);
        }
    }
    return result;
}
};