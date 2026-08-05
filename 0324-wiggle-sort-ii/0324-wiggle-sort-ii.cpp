class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec = nums;

        // sort ascending
        sort(vec.begin(), vec.end());

        // reverse to descending
        reverse(vec.begin(), vec.end());

        int j = 0;

        // fill odd indices first
        for (int i = 1; i < n; i += 2) {
            nums[i] = vec[j++];
        }

        // fill even indices next
        for (int i = 0; i < n; i += 2) {
            nums[i] = vec[j++];
        }
    }
};
