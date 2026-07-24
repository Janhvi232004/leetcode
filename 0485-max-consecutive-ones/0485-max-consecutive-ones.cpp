class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxc=0,currcount=0;
        for(int val : nums){
            if(val==1){
                currcount++;
                maxc=max(maxc,currcount);
            }
            else{
                currcount=0;
            }
        }
        return maxc;
    }
};