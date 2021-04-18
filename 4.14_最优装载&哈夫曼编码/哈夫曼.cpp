#include <bits/stdc++.h>
using namespace std;

struct cmp { //定义优先队列需要的比较函数
    bool operator()(const int &x, const int &y) { return x > y; }
}; 

double haffmanCoding(int n, int *freq) {
    int i, total = 0, sumFreq = 0, jointFreq;
    priority_queue<int, vector<int>, cmp> heap; //优先队列，最小值优先
    for (i = 0; i < n; i++) {
        total += freq[i]; //频次总和
        heap.push(freq[i]);
    }                         //形成优先队列
    while (heap.size() > 1) { //循环选择队列中频次最少的两个元素合并
        jointFreq = 0;        //合并后结点的频次
        for (i = 0; i < 2; i++) { //删除频次最少的两元素
            jointFreq += heap.top();
            heap.pop();
        }
        sumFreq += jointFreq;
        heap.push(jointFreq); //优先队列中插入合并结点
    }
    return sumFreq / (1.0 * total); //返回平均码长
}