class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count=0;
        for(auto &it:items){
            if(ruleKey=="type"&&ruleValue==it[0]){
                count++;
            }
            else if(ruleKey=="color"&&ruleValue==it[1]){
                count++;
            }
            else if(ruleKey=="name"&&ruleValue==it[2])count++;
        }
        return count;
    }
};