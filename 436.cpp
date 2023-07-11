436. Find Right Interval
class Solution {
public:
   vector<int> findRightInterval(vector<vector<int>>& intervals) {
vector<vector<int>>v;
int n=intervals.size();
    for (int i = 0; i <n ; ++i)
        v.push_back({intervals[i][0],i});
    sort(v.begin(),v.end());
    vector<int>ans(n,-1);
    for (int i = 0; i < n; ++i) {
        vector<int>val{intervals[i][1],0};
        auto it= lower_bound(v.begin(),v.end(),val);
        if (it!=v.end()){
            int idx=it-v.begin();
            ans[i]=v[idx][1];
        }
    }
    return ans;
}

};
//Approach:
// 1. Create a new vector of vectors, 'v', to store the start times of intervals along with their corresponding indices.
// 2. Iterate over the intervals vector and add each interval's start time and index to 'v'.
// 3. Sort 'v' in ascending order based on the start times.
// 4. Initialize a result vector, 'ans', with -1 for each interval in the intervals vector.
// 5. Iterate over the intervals vector again:
//    - Create a temporary vector, 'val', with the end time of the current interval and a placeholder value of 0.
//    - Use the lower_bound function to find the iterator pointing to the first element in 'v' that is not less than 'val'.
//    - If a valid iterator is found, calculate the index of the right interval by subtracting the iterator 'it' from the beginning iterator of 'v'.
//    - Assign the index to the corresponding position in 'ans'.
// 6. Return the result vector 'ans' containing the indices of the right intervals for each interval in the input vector.

// Complexity:
// Time complexity: O(n log n) - Sorting the 'v' vector takes O(n log n) time, and the binary search for each interval takes O(log n) time. Since both operations are performed once, the overall time complexity is O(n log n).
// Space complexity: O(n) - The 'v' vector and 'ans' vector each require O(n) space, where n is the number of intervals.