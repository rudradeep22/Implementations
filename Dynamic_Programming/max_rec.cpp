#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<int>> &matrix);
};

int Solution::maximalRectangle(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    if (n == 0 || m == 0) 
        return 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + 1;
                int y = 0;
                int x = INT_MAX;
                while ((i - y >= 0) && (matrix[i - y][j] == 1)) {
                    x = min(x, dp[i - y][j]);
                    area = max(area, x * (y+1));
                    y++;
                }
            }
        }
    }
    return area;
}