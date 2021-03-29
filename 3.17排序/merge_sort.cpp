#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int a[MAXN], b[MAXN];

template<class Type>
void MergeSort(Type a[], Type b[], int left, int right) {
    if(left < right) {
        int i = (left + right) / 2;
        MergeSort(a, left, i);
        MergeSort(a, i+1, right);
        Merge(a, b, left, i, right);
        // Copy(a, b, left, right);
    }
}

template<class Type>
void Merge(Type c[], Type d[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while((i <= m) && (j <= r)) {
        if(c[i] <= c[j])
            d[k++] = c[i++];
        else
            d[k++] = c[j++];
        if(i > m) {
            for(int q=j; q<=r; q++)
                d[k++] = c[q];
        }
        else {
            for(int q=i; q<=m; q++)
                d[k++] = c[q];
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for(int i=0;i<15;i++)
        cin >> a[i];
    MergeSort(a, b, 0, 14);
    for(int i=0;i<14;i++) {
        cout << b[i] << " ";
    }
    return 0;
}