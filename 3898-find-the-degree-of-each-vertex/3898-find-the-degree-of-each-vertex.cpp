class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n);
        for( int i = 0;i<n;i++){
            int sum = 0;
            for( int j = 0 ; j<n;j++){
                sum += matrix[i][j];
            }
            ans[i] = sum;
        }
        return ans;
        
    }
};