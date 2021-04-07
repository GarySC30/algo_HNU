#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int w[MAXN], v[MAXN];
int c, maxvalue, maxweight, n;

void dfs(int step, int w_now, int v_now) {
    if(step == n)
        return;
    if(w_now + w[step] <= maxweight) { // 剪枝
        if(v_now + v[step] > maxvalue) {
            maxvalue = v_now + v[step];
        }
        dfs(step+1, w_now+w[step], v_now+v[step]); // 选
    }
    dfs(step+1, w_now, v_now); // 不选
}

int main() {
    freopen("01_dfs_input.txt", "r", stdin);
    freopen("01_dfs_output.txt", "w", stdout);
    cin >> n >> maxweight;
    for(int i=0;i<n;i++)
        cin >> v[i] >> w[i];
    dfs(0, 0, 0);
    cout << maxvalue;
    return 0;
}

// 不太对