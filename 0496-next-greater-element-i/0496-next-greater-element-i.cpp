class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nge;
        stack<int> st;
        for(int num : nums2){
            while(!st.empty() and st.top()<num){
                nge[st.top()]=num;
                st.pop();

            }
            st.push(num);
        }
        vector<int> result;
        for(int num: nums1){
            if(nge.find(num)!=nge.end()){
                result.push_back(nge[num]);
            }
            else result.push_back(-1);
        }
        return result;
    }
};