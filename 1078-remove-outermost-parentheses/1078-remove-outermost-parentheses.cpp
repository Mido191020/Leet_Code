class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count=0;
        for(auto it:s){
            if(it=='('&&count++>0) res+=it;
            if(it==')'&&count-->1) res+=it;
        }
        return res;
    }
};