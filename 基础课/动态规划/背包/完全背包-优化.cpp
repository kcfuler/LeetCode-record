#include <iostream>
using namespace std;

const int N = 1010;
int f[N]; // 方程的含义与01相同
int v[N], w[N];
int n, m;

int main()
{
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> v[i] >> w[i];

  for (int i = 1; i <= n; i++)
    // 优化的区别就在于完全背包不限制物品的数量，不用担心一个物品取到多次的问题
    for (int j = v[i]; j <= m; j++)
    {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }

  cout << f[m] << endl;

  return 0;
}