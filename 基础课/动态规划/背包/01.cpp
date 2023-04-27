#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N]; // 表示在 j 容量的前提下， 前 i 个物品中得到的价值的最大值
int w[N], v[N];
int n, m;

int main()
{

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> v[i] >> w[i];

  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++)
    {
      f[i][j] = f[i - 1][j];
      if (j >= v[i])
        f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    }

  cout << f[n][m] << endl;

  return 0;
}