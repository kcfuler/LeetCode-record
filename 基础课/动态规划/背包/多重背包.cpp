#include <iostream>
using namespace std;

const int N = 110;
int f[N][N]; // 状态方程的含义是一致
int v[N], w[N], s[N];
int n, m;

int main()
{
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> v[i] >> w[i] >> s[i];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      f[i][j] = f[i - 1][j];
      for (int k = 1; k <= s[i]; k++) // 枚举所有的个数的可能
      {
        if (j >= v[i] * k)
          f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
      }
    }

  cout << f[n][m] << endl;

  return 0;
}