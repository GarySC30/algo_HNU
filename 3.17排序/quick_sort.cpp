#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int a[MAXN];

template <class Type>
int Partition(Type a[], int p, int r) {
    int i = p, j = r + 1;
    Type x = a[p];
    // 小于x放左边，大于x放右边
    while(true) {
        while(a[++i] < x && i < r) ;
        while(a[--j] > x) ;
        if(i >= j) break;
        swap(a[i], a[j]);
        // int ss = a[i]; a[i] = a[j]; a[j] = ss;
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}
template <class Type>
void QuickSort(Type a[], int p, int r) {
    if(p < r) {
        int q = Partition(a, p, r);
        QuickSort(a, p, q-1);
        QuickSort(a, q+1, r);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    for(int i=0;i<15;i++)
        cin >> a[i];
    QuickSort(a, 0, 14);
    for(int i=0;i<15;i++) {
        cout << a[i] << endl;
    }
    return 0;
}