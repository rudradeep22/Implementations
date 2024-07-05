#include <bits/stdc++.h>
using namespace std;

// Bottom up approach
int knapSack(int W, int wt[], int v[], int n){
    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    for(int i =0; i<=n; i++){
        for(int w = 0; w <= W; w++){
            if( i==0 || w==0){
                dp[i][w] = 0;
            }
            else if(w >= wt[i-1]){
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + v[i]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

// Space optimized approach
int knapsack2(int W, int wt[], int v[], int n){
    vector<int> dp(W+1, 0);
    for(int i=1; i<=n; i++){
        for(int w = W; w>=0; w--){
            if(w >= wt[i-1]){
                dp[w] = max(dp[w], dp[w - wt[i-1]] + v[i]);
            }
        }
    }
    return dp[W];
}

int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSack(W, weight, profit, n) << endl;
    cout << knapsack2(W, weight, profit, n) << endl;
    return 0;
}