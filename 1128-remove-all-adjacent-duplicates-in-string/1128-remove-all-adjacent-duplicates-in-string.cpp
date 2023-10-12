class Solution {
public:
    string removeDuplicates(string s) {
      stack<char>st;
      int size=s.size();
      for(int i=0;i<size;i++){
          if(st.empty()){
              st.push(s[i]);
          }
          else{
              if(st.top()==s[i]){
                  st.pop();
              }
              else{
                  st.push(s[i]);
              }
          }
      }
      string res="";
      while(!st.empty()){
          res+=st.top();
          st.pop();
      }
      reverse(res.begin(),res.end());
      return res;
    }
};