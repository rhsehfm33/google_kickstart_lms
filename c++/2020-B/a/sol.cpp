#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        int N;
        scanf("%d", &N);
        vector<int> H(N);

        for (int i = 0; i < N; ++i) {
            scanf("%d", &H[i]);
        }

        int ans = 0;
        for (int i = 1; i < N - 1; ++i) {
            if (H[i-1] < H[i] && H[i+1] < H[i]) {
                ans += 1;
                i += 1;
            }
        }

        printf("Case #%d: %d\n", i , ans);
    }
    return 0;
}