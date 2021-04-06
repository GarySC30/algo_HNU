#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int m;
int a[MAXN], ans[MAXN];
bool flag[MAXN] = {false};

void dfs(int a[], int k, int m) {
    if (k == m) { // 到头了，swap(list[k],list[k])也没有意义
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < m; i++) { // 从已有序列中挑选没选过的元素
        if (!flag[i]) {
            flag[i] = true; // 添加到数组中，并记录已经出现过
            a[k] = a[i];
            dfs(a, k + 1, m);
            flag[i] = false; // 复原
        }
    }
}

int main() {
    freopen("perm_input.txt", "r", stdin);
    freopen("perm_dfs_output.txt", "w", stdout);
    cin >> m;
    int inputa;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    dfs(a, 0, m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}