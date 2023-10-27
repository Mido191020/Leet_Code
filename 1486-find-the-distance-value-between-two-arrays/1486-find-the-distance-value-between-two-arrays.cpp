class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ct=0,size1=arr1.size(),size2=arr2.size();
        for(int i=0;i<size1;i++){
             bool valid=true;
            for(int j=0;j<size2;j++){
               if(abs(arr1[i]-arr2[j])<=d){
                   valid=false;
                   break;
               }
            }
            if(valid)ct++;
        }
        return ct;
    }
};