#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

void init(int& N, int& B, vector<int>& A) {
    cin >> N >> B;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
}

int solve(vector<int>& A, int B) {
    sort(begin(A), end(A));

    int ans = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (B - A[i] < 0) {
            break;
        }
        ans += 1;
        B -= A[i];
    }

    return ans;
}

int main() {
    FAST;

    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int N, B;
        vector<int> A;
        init(N, B, A);
        int result = solve(A, B);
        cout << "Case #" << i << ": " << result << endl;
    }

    return 0;
}