#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

const int MAX = 1e9;

int main() {
    FAST;

    unordered_map<char, pair<long, long>> um;
    um['N'] = {-1 + MAX, 0};
    um['E'] = {0, 1};
    um['S'] = {1, 0};
    um['W'] = {0, -1 + MAX};

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        string str;
        cin >> str;
        
        long x = 0;
        long y = 0;
        stack<long> s;
        stack<pair<long, long>> s2;
        s2.push({0, 0});
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] >= '2' && str[i] <= '9') {
                s.push(str[i] - '0');
                s2.push({0, 0});
                ++i;
            }
            else if (str[i] == ')') {
                while (s2.size() > s.size() + 1) {
                    auto [addedX, addedY] = s2.top(); s2.pop();
                    auto& [curX, curY] = s2.top();
                    curX = (curX + addedX) % MAX;
                    curY = (curY + addedY) % MAX;
                }
                auto [addedX, addedY] = s2.top(); s2.pop();
                auto& [curX, curY] = s2.top();
                curX = (curX + addedX * s.top()) % MAX;
                curY = (curY + addedY * s.top()) % MAX;
                s.pop();
            }
            else {
                s2.top().first = (s2.top().first + um[str[i]].first) % MAX;
                s2.top().second = (s2.top().second + um[str[i]].second) % MAX;
            }
        }

        x = s2.top().first + 1;
        y = s2.top().second + 1;

        printf("Case #%d: %ld %ld\n", i, y, x);
    }

    return 0;
}