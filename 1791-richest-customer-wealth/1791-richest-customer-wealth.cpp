class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_=0,sum=0;
        int size=accounts.size();
        for(int i=0;i<accounts.size();i++){
            for(int j=0;j<accounts[i].size();j++){
                sum+=accounts[i][j];
            }
            if(max_<=sum)max_=sum;
            sum=0;
        }
        return max_;
    }
};