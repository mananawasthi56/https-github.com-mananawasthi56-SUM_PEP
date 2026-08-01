class Solution {
public:
int solve(int left ,int right , vector<int>& nums){
    if(left == right){
        return nums[left];
    }
    int pickleft = nums[left] - solve(left + 1 ,right , nums);
    int pickright = nums[right] - solve(left , right - 1 , nums);
    return max(pickleft , pickright);
}
    bool predictTheWinner(vector<int>& nums) {
        return  solve( 0 , nums.size() - 1 , nums)>= 0;
    }
};