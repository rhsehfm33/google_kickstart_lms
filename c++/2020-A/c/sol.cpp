#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void init(int& N, int& K, vector<int>& M) {
    cin >> N >> K;
    M.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> M[i];
    }
}

int solve(int N, int K, vector<int>& M) {
    int minx = 1;
    int maxx = -1;
    for (int i = 0; i < M.size() - 1; ++i) {
        maxx = max(maxx, M[i+1] - M[i]);
    }

    while (minx <= maxx) {
        int midx = (minx + maxx) / 2;

        bool isSuccess = true;
        for (int i = 0, used = 0; i < M.size() - 1; ++i) {
            int diff = M[i+1] - M[i];
            used += (diff / midx) + (diff % midx ? 0 : -1);
            if (used > K) {
                isSuccess = false;
                break;
            }
        }

        if (isSuccess) {
            maxx = midx - 1;
        }
        else {
            minx = midx + 1;
        }
    }
    
    return maxx + 1;
}

int main() {
    FAST;

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i ){
        int N, K;
        vector<int> M;
        init(N, K, M);
        int result = solve(N, K, M);
        printf("Case #%d: %d\n", i, result);
    }
    
    return 0;
}