#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100
#define MAXW 1000
int knapsack(int n, int W, int wt[], int val[]) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i-1] <= w) {
                dp[i][w] = max(
                    val[i-1] + dp[i-1][w - wt[i-1]],
                    dp[i-1][w]
                );
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int n, W;
    int wt[MAXN], val[MAXN];
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Maximum value in Knapsack = "
         << knapsack(n, W, wt, val) << endl;
    return 0;
}
