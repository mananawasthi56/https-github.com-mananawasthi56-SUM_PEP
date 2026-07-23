class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        while(n < 3){
            return n;
        }
        int ans = 1;
        while(ans <= n){
            ans <<=1;
        }
        return ans;
        
    }
};