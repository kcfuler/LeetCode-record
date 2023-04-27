#include <iostream>
using namespace std;

const int N = 1010;
int f[N]; // 表示在 j 容量时，能够得到的价值的最大值
int w[N], v[N];
int n, m;

int main()
{

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> v[i] >> w[i];

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= v[i]; j--)
    {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }

  cout << f[m] << endl;

  return 0;
}