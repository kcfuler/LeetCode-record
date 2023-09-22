#include <iostream>
using namespace std;

const int N = 110;

int f[N], v[N], w[N];
int n, m;

// 一个物品组内只能选一个物品
int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++) // 每一组进行一次遍历，在所有的情况中选出最优的
  {
    int s;
    cin >> s;
    for (int j = 0; j < s; j++)
      cin >> v[j] >> w[j];

    // 使用倒序循环的方式来选择,因为每种物品只能选择一个
    // 将体积放到外层循环是为了保证对于每个容量，能够得到从前面一组物品中所得到的最大价值
    for (int j = m; j >= 0; j--)
      for (int k = 0; k < s; k++)
        if (j >= v[k])
          f[j] = max(f[j], f[j - v[k]] + w[k]);
  }

  cout << f[m] << endl;

  return 0;
}