#include <iostream>
using namespace std;

const int N = 1010;
int f[N]; // 表示到 i 结尾的最长上升子序列的长度
int a[N];
int n;

int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
  {
    f[i] = 1;
    for (int j = 1; j <= i; j++)
      if (a[i] > a[j])
        f[i] = max(f[i], f[j] + 1);
  }

  int res = 0;
  for (int i = 1; i <= n; i++)
    res = max(res, f[i]);

  cout << res << endl;
  return 0;
}