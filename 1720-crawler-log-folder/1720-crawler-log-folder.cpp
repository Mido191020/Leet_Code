class Solution {
public:
         int minOperations(vector<string>& logs) {
        int ct=0;
        int size=logs.size();
        for (const auto& str : logs) {
             if (str == "../")ct = std::max(0, ct - 1);
             else if(str!="./")ct++;
        }
       
      
        return ct;
    }
};