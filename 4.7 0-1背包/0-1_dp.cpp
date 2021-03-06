#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int w[MAXN], v[MAXN], val[MAXN];
int maxweight, n;

int binaryPack(int n, int maxweight) {  // 从1-i个物品，背包可用容量为p
    for(int i=0;i<n;i++) {  
        for(int p=maxweight;p>=0;p--) { // 根据递推方程进行穷举
            if(p >= w[i] && val[p] < val[p-w[i]]+v[i]) { 
                val[p] = val[p-w[i]]+v[i]; // 放得下，总容量挖掉w[i]
            }
        }
    }
    return val[maxweight];
}

int main() {
    freopen("01_dp_input.txt", "r", stdin);
    freopen("01_dp_output.txt", "w", stdout);
    cin >> n >> maxweight;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    cout << binaryPack(n, maxweight);
    return 0;
}
