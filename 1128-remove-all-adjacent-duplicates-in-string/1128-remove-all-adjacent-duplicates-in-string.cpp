class Solution {
public:
    string removeDuplicates(string s) {
        int size=s.size();    
        stack<char>st;
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