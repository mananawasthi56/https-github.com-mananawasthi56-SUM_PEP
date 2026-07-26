class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans =nums[n - 3] * nums[n - 2] * nums[n - 1];
        int ans2 = nums[0] * nums[1] * nums[n-1];
        return max(ans , ans2);
        
    }
};