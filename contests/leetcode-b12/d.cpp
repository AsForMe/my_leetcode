#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;
typedef long long ll;
int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -f; c = getchar();}
    while(c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
    return f * x; 
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(TreeNode* root) {
    return root->left == NULL && root->right == NULL;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




int f[102][102][2], tot[102][102];
int dfs(int x, int y, int z){
    if (y < x) return 0;
    if (f[x][y][z] < 0x3f3f3f3f) return f[x][y][z];
    if (!z){
        f[x][y][z] = dfs(x, y, 1) + 1;
    }else {
        for (int i = tot[x][z], j = z; i <= y && j <= tot[x][0]; ++j, i = tot[x][j])
            f[x][y][z] = min(f[x][y][z], dfs(x + 1, i - 1, 1) + dfs(i + 1, y, 0));
    }
    return f[x][y][z];
}
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        memset(f, 0x3f, sizeof(f));
        memset(tot, 0, sizeof(tot));
        for (int i = 1; i <= n; ++i)
            f[i][i][1] = 0, f[i][i][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j)
                if (arr[i - 1] == arr[j - 1])
                    tot[i][++tot[i][0]] = j;
        return dfs(1, n, 0);
    }
};
Solution sol;
void init(){
    vector<int> vec{1, 1, 1,1, 1};
    cout << sol.minimumMoves(vec);
}
void solve(){
    // sol.convert();
}
int main(){
    init();
    solve();
    return 0;
}
