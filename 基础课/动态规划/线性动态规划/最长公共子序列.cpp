#include <iostream>
using namespace std;

const int N = 1010;
int f[N][N]; // 所有在第一个序列的前 i 个字符中出现，且在第二个序列的前 j 个中出现的序列
char a[N], b[N];
int n, m;

int main()
{
  cin >> n >> m;

  cin >> a + 1 >> b + 1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (a[i] == b[j])
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
    }

  cout << f[n][m] << endl;

  return 0;
}