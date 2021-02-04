#include <bits/stdc++.h>

using namespace std;

void init(long& N, long& D, vector<long>& X) {
    scanf("%ld %ld", &N, &D);
    X.resize(N);
    for (long i = 0; i < N; ++i) {
        scanf("%ld", &X[i]);
    }
}

long solve(long N, long D, vector<long>& X) {
    long cur = D;
    for (long i = N - 1; i >= 0; --i) {
        cur -= (cur % X[i]);
    }

    return cur;
}

int main() {
    int t;
    scanf("%d", &t);
    
    for (int i = 1; i <= t; ++i) {
        long N, D;
        vector<long> X;
        init(N, D, X);
        long result = solve(N, D, X);
        printf("Case #%d: %ld\n", i, result);
    }
    return 0;
}