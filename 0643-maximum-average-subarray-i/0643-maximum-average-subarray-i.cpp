class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int n = nums.size();
      int l= 0;
      int r = k - 1;
      int sum = 0;
      for(int i = 0;i<k;i++){
        sum += nums[i];
      }
      int ans = sum;

      while( r < n - 1){
        sum -= nums[l];
        l++;
        r++;
        sum += nums[r];
        ans = max(ans , sum);

      }
      return (double)ans / k;
    }

      
};