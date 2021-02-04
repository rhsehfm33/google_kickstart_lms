#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;


struct TreeNode {
    vector<TreeNode*> kids;
    int maxDepth;
    int count;

    TreeNode() {
        kids = vector<TreeNode*>(26, nullptr);
        maxDepth = 0;
        count = 0;
    }

    ~TreeNode() {
        for (int i = 0; i < 26; ++i) {
            if (kids[i] != nullptr) {
                delete(kids[i]);
            }
        }
    }
};


class Trie {
public:
    TreeNode* root;

    Trie() {
        root = new TreeNode();
    }

    ~Trie() {
        delete root;
    }

    int insertAndUpdateMax(string& str, int i, const int K, TreeNode* cur) {
        cur->count += 1;
        if (cur->count >= K) {
            cur->maxDepth = max(cur->maxDepth, i);
        }
        if (i == str.size()) {
            return cur->maxDepth;
        }

        int index = str[i] - 'A';
        if (cur->kids[index] == nullptr) {
            cur->kids[index] = new TreeNode();
        }
        int result = insertAndUpdateMax(str, i + 1, K, cur->kids[index]);

        if (cur->maxDepth < result) {
            cur->maxDepth = result;
        }

        

        return cur->maxDepth;
    }

    string findMaxString(TreeNode* cur) {
        if (cur == nullptr) {
            return ""; 
        }

        int maxDepth = 0;
        TreeNode* nextNode = nullptr;
        char ch = 'x';
        for (int i = 0; i < 26; ++i) {
            if (cur->kids[i] != nullptr) {
                if (maxDepth < cur->kids[i]->maxDepth) {
                    maxDepth = cur->kids[i]->maxDepth;
                    ch = 'A' + i;
                    nextNode = cur->kids[i];
                }
                if (ch == 'x') {
                    nextNode = cur->kids[i];
                    ch = 'A' + i;
                }
            }
        }

        if (nextNode == nullptr) {
            return "";
        }
        else {
            return ch + findMaxString(nextNode);
        }
    }

    void deleteAndUpdateMax(string& str, int i, const int K, TreeNode* cur) {
        cur->count -= 1;
        cur->maxDepth = cur->count >= K ? i : 0;
        // if (i) {
        //     cout << str << " " << i << " " << cur->count << " " << cur->maxDepth << endl;
        // }
        if (i == str.size()) {
            return;
        }

        int nextIndex = str[i] - 'A';
        deleteAndUpdateMax(str, i + 1, K, cur->kids[nextIndex]);
        if (cur->kids[nextIndex]->count == 0) {
            delete cur->kids[nextIndex];
            cur->kids[nextIndex] = nullptr;
        }

        for (int i = 0; i < 26; ++i) {
            if (cur->kids[i] != nullptr) {
                cur->maxDepth = max(cur->maxDepth, cur->kids[i]->maxDepth);
            }
        }
    }

};

void init(int& N, int& K, Trie* trie, multiset<string>& ms) {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        ms.insert(str);
        trie->insertAndUpdateMax(str, 0, K, trie->root);
    }
}

int solve(int N, int K, Trie* trie, multiset<string>& ms) {
    int ans = 0;
    for (int i = 0; i < N / K; ++i) {
        int maxDepth = 0;
        for (int i = 0; i < 26; ++i) {
            if (trie->root->kids[i] != nullptr) {
                maxDepth = max(maxDepth, trie->root->kids[i]->maxDepth);
            }
        }
        ans += maxDepth;
        
        string maxString = trie->findMaxString(trie->root);
        auto it = ms.find(maxString);
        // cout << maxString << endl;
        for (int i = 0; i < K; ++i) {
            auto deletionIt = it;
            string deletionStr = *it;
            ++it;
            trie->deleteAndUpdateMax(deletionStr, 0, K, trie->root);
            ms.erase(deletionIt);
        }
        // cout << endl;
    }

    return ans;
}

int main() {
    FAST;
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int N, K;
        Trie* trie = new Trie();
        multiset<string> ms;
        init(N, K, trie, ms);
        int result = solve(N, K, trie, ms);
        printf("Case #%d: %d\n", i, result);
        delete trie;
    }

    return 0;
}