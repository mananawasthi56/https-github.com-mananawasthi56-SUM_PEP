class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dist = grid[x][y];
            if(x == n-1 && y == n -1 ){
                return dist;
            }
            for(int dr = -1 ; dr<=1 ; dr++){
                for(int  dc = -1 ; dc <=1 ; dc++){
                    int newx = x + dr;
                    int newy = y + dc;
                    if(newx >= 0 && newx < n&& newy >= 0 && newy < n && grid[newx][newy] == 0){
                        grid[newx][newy] = dist + 1;
                        q.push({newx,newy});
                    }
                }
            }
        }
        return -1;
        
    }
};