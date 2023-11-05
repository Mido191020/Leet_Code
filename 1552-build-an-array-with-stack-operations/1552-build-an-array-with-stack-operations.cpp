class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        string x = "Push";
        string y = "Pop";
        vector<string> resulte;
        stack<int> st;
        int targetIndex = 0;

        for (int i = 1; i <= n && targetIndex < target.size(); i++) {
            resulte.push_back(x);
            st.push(i);

            if (st.top() == target[targetIndex]) {
                targetIndex++;
            } else {
                resulte.push_back(y);
                st.pop();
            }
        }

        return resulte;
    }
};
