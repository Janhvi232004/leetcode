class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit : num){
            while(!st.empty() && k > 0 && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // Remove remaining k digits
        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }
        
        // Build result efficiently
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());  // reverse once instead of repeated prepends
        
        // Remove leading zeros
        int i = 0;
        while(i < res.size()-1 && res[i] == '0') i++;
        res = res.substr(i);
        
        return res.empty() ? "0" : res;
    }
};
