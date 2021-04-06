#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
// 双递归函数
int ackerman(int n, int m) {
    if(n == 1 && m == 0) 
        return 2;
    else if(n == 0 && m >= 0) 
        return 1;
    else if(n >= 2 && m == 0)
        return n + 2;
    else if(n >= 1 && m >= 1)
        return ackerman(ackerman(n-1,m),m-1);
}

int main() {
    freopen("ackerman_output.txt", "w", stdout);
    int n; cin >> n;
    for(int i=1;i<=n;i++) {
        cout << ackerman(i, 3) << endl;
    }
    fclose(stdout);
    return 0;
}