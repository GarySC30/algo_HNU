#include <bits/stdc++.h>>
using namespace std;

int greedyEventSchedule(int n, int s[], int f[]) {
    int selected, ans = 0;
    sort(f, f+n);  // 对f进行排序
    selected = 0;  // 选取排序后的第一个
    ans = 1;
    for (int i = 1; i < n; i++) // 贪心，直到选完
        if (s[i] >= f[selected]) {
            selected = i; 
            ans++;
        }
    return ans;
}