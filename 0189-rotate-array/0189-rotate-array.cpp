class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0) return;
        k=k%n;
        //whole
        reverse(nums.begin(),nums.end());
        //upto k element
        reverse(nums.begin(),nums.begin()+k);
        //remaining element
        reverse(nums.begin()+k,nums.end());
        
    }
};