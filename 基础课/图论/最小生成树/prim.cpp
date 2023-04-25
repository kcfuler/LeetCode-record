/*
算法主要分为以下四个步骤
1. 初始化距离数组
2. 从距离数组中找到距离当前点最近的点
3. 将找到的点加入集合
4. 继续重复2，3步骤，直到所有点都加入集合
*/
#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N]; // 稠密图使用邻接表
int d[N];    // 标志到每一个点的最短距离
bool st[N];  // 表示是否加入过集合
int n, m;

int prim()
{
  memset(d, 0x3f, sizeof d);
  int res = 0;

  for (int i = 0; i < n; i++)
  {
    // 得到最小值
    int t = -1;
    for (int j = 1; j <= n; j++)
      if (!st[j] && (t == -1 || d[t] > d[j]))
        t = j;

    // 判断是否能够构成最小生成树
    if (!i && d[t] == INF)
      return INF;

    if (i)
      res += d[t];
    st[t] = true;
    for (int j = 1; j <= n; j++)
      d[j] = min(d[j], g[j][t]); // 更新每个点到集合的最短距离
  }

  return res;
}

int main()
{
  cin >> n >> m;

  memset(g, 0x3f, sizeof g); // 初始化

  int a, b, c;
  while (m--)
  {
    cin >> a >> b >> c;
    g[a][b] = g[b][a] = min(g[a][b], c);
  }

  int ans = prim();
  if (ans == INF)
    cout << "impossible" << endl;
  else
    cout << ans << endl;

  return 0;
}