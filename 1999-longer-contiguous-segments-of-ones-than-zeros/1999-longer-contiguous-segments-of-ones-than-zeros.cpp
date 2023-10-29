class Solution {
public:
    bool checkZeroOnes(string s) {
    int ct1 = 0, ct0 = 0;
    int max0 = 0, max1 = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            ct0++;
            ct1 = 0;
            max0 = max(max0, ct0);
        } else {
            ct1++;
            ct0 = 0;
            max1 = max(max1, ct1);
        }
    }

    return max1 > max0;
}

};