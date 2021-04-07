#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, maxvalue;

double binaryKnapsack(int numItems, int *w, double *v, int capacity) {
    int i, p;   // 从1-i个物品，背包可用容量为p
    double Val[n][maxvalue]; // 存储不同情况下的最大容纳容量
    memset(Val, 0, sizeof(Val)); // 初始化
    for (i = 0; i < numItems; i++)  
        for (p = 0; p <= capacity; p++) {  // 根据递推方程进行穷举
            if(p < w[i])
                Val[i][p] = Val[i - 1][p];   // 放不下的情况
            else if (p >= w[i] && Val[i - 1][p] < Val[i - 1][p - w[i]] + v[i])
                Val[i][p] = Val[i][p - w[i]] + v[i]; // 放得下，总容量挖掉w[i]
        }
    return Val[numItems - 1][capacity]; // 得到结果
}