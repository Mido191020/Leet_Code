class Solution {
public:
   vector<int> decompressRLElist(std::vector<int>& nums) {
       int size=nums.size();
   vector<std::pair<int,int>>v;
   for(int i=0;i<size;i+=2){
       v.emplace_back(nums[i],nums[i+1]);
   }
    std::vector<int> res;
   for(const auto& it:v){
        int fre = it.first;
       int val=it.second;
       for(int j=0;j<fre;++j){
           res.emplace_back(val);
       }
   }
   return res;
}
};