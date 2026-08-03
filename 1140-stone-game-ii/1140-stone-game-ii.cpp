class Solution {
public:
    int dp[101][101];
    vector<int> suffix;

    int solve(int i, int M, vector<int>& piles) {

        int n = piles.size();
       if (i + 2 * M >= n) {
            return suffix[i];
        }

        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;

        
        for (int X = 1; X <= 2 * M; X++) {

            ans = max(ans,
                      suffix[i] - solve(i + X, max(M, X), piles));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        memset(dp, -1, sizeof(dp));

        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1, piles);
    }
};