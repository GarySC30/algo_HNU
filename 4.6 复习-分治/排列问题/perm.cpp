#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int a[MAXN], k, m;

void perm(int list[], int k, int m) {
    if(k == m) {  // 到头了，swap(list[k],list[k])也没有意义
        for(int i=0;i<k;i++) {
            cout << list[i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i=k;i<m;i++) {
            swap(list[i], list[k]);  // 循环，每重循环控制住一位数，放在当前长度序列的开头
            perm(list, k+1, m);  // 进入下一位，进行相同操作
            swap(list[i], list[k]); // 这一位所有情况都考虑完了，还原以便下一种情况
        }
    }
}

int main() {
    freopen("perm_input.txt", "r", stdin);
    freopen("perm_output.txt", "w", stdout);
    cin >> m;
    for(int i=0;i<m;i++)
        cin >> a[i];
    perm(a, 0, m);
    fclose(stdin); fclose(stdout);
    return 0;
}