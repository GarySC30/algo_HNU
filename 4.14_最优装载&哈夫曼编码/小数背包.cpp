#include <algorithm>
#include <stdio.h>
using namespace std;
#define MaxItems 1000
struct item {
    int weight;
    int value;
    bool operator<(const item &bb) const { //定义比较函数（小于号）
        return value / (1.0 * weight) > (1.0 * bb.value) / bb.weight; //为什么乘以1.0？
    }
}; //定义物品的结构体
double greedyKnapsack(int n, int capacity, item *itemSet) {
    double ans = 0;
    sort(itemSet, itemSet + n); // STL中的快速排序算法
    for (int i = 0; i < n; i++)
        if (capacity >= itemSet[i].weight) {
            ans += itemSet[i].value; //选择单价最大的物品
            capacity -= itemSet[i].weight;
        } else {
            ans += capacity * (itemSet[i].value * 1.0) / itemSet[i].weight; //最后一个物品只能装部分
            break;
        }
    return ans;
}