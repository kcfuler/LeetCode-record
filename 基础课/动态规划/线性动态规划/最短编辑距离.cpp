#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N]; // f[i][j] 表示从 a[i] 到 b[j] 的最小编辑距离, 主要有 增、删、改三种情况
char a[N], b[N];
int n, m;

int main()
{
  cin >> n >> a + 1 >> m >> b + 1;

  // 需要初始化边界
  for (int i = 0; i <= n; i++)
    f[i][0] = i;
  for (int j = 0; j <= m; j++)
    f[0][j] = j;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1); // 增和删的情况
      if (a[i] == b[j])
        f[i][j] = min(f[i][j], f[i - 1][j - 1]); // 不变
      else
        f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1); // 改
    }

  cout << f[n][m] << endl;

  return 0;
}