class Solution {
public:
int dp[501][501];
int solve(int left , int right , vector<int>& piles){
    if(left > right){
        return 0;
    }
     if(dp[left][right] != -1)
            return dp[left][right];

    int picleft = piles[left] - solve(left +1 , right , piles);
    int picright = piles[right] - solve(left , right - 1 , piles);
    return dp[left][right] = max(picleft , picright);
}
    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));

        return solve(0 , piles.size() - 1 , piles) > 0;
    }
};