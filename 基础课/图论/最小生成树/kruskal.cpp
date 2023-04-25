/*
基本思路：
1. 表示边， 按边权排序
2. 如果不成环，就加入集合(使用并查集判断)
3. 记录集合中点的数量，如果少于总数，说明无法生成
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int p[N];
int n, m;

// 定义结构体
struct Edge
{
  int a, b, w;
  // 第一个 const 表示常量引用，不允许修改传入的变量
  // 第二个 const 表示常量成员函数，不允许修改结构体内的内容
  bool operator<(const Edge &W) const
  {
    return w < W.w;
  }
} edges[M];

int find(int x)
{
  if (x == p[x])
    return x;
  else
    return p[x] = find(p[x]);
}

int kruskal()
{
  sort(edges, edges + m);

  for (int i = 1; i <= n; i++)
    p[i] = i;

  int res = 0, cnt = 1; // 这里cnt从1开始方便后面判断
  for (int i = 0; i < m; i++)
  {
    int a = edges[i].a, b = edges[i].b, w = edges[i].w;
    a = find(a), b = find(b);

    // 没有成环且没有加入过集合,就加入集合
    if (a != b)
    {
      p[a] = b;
      res += w;
      cnt++;
    }
  }

  if (cnt < n)
    return INF;
  else
    return res;
}

int main()
{
  cin >> n >> m;

  // 结构体初始化的语法
  for (int i = 0; i < m; i++)
  {
    int a, b, w;
    cin >> a >> b >> w;
    edges[i] = {a, b, w};
  }

  int t = kruskal();

  if (t == INF)
    cout << "impossible" << endl;
  else
    cout << t << endl;

  return 0;
}