#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

int dp[51][1502];

void init(int& N, int& K, int& P, vector<vector<int>>& plates) {
    memset(dp, 0, sizeof(dp));
    cin >> N >> K >> P;
    plates = vector<vector<int>>(N, vector<int>(K));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> plates[i][j];
        }
    }
}

int solve(int N, int K, int P, vector<vector<int>>& plates) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= P; ++j) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            for (int k = 1, sum = 0; j + k <= P && k <= K; ++k) {
                sum += plates[i][k-1];
                dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j] + sum);
            }
        }
    }

    return dp[N][P];
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int N, K, P;
        vector<vector<int>> plates;
        init(N, K, P, plates);
        int result = solve(N, K, P, plates);
        printf("Case #%d: %d\n", i, result);
    }
    
    return 0;
}