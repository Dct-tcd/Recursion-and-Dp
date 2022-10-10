class Solution {
public:
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    int solve(vector<vector<int>>& grid, int i, int j, int cnt)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
        {
            return 0;
        }
        if (grid[i][j] == 2)
        {
            if (cnt == 0)
            {
                return 1;
            }
            return 0;
        }
        if (cnt == 0 && grid[i][j] != 1)
        {
            return 0;
        }
        int ans = 0;
        if (grid[i][j] == 0)
        {
            grid[i][j] = -1;
            for (int k = 0; k < 4; k++)
            {
                ans = ans + solve(grid, i + dir[k], j + dir[k + 1], cnt - 1);
            }
            grid[i][j] = 0;
        }
        else
        {
            grid[i][j] = -1;
            for (int k = 0; k < 4; k++)
            {
                ans = ans + solve(grid, i + dir[k], j + dir[k + 1], cnt);
            }
            grid[i][j] = 1;
        }
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int cnt = 0, m = grid.size(), n = grid[0].size();
                
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    cnt++;
                }
            }
        }        
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return solve(grid, i, j, cnt);
                }
            }
        }
        return 0;
    }
};
