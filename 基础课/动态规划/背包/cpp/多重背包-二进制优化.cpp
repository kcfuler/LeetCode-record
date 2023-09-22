#include <iostream>
#include <vector>
using namespace std;

const int N = 2010;
int f[N]; // 转化为01背包之后就可以优化空间了
int n, m;

struct Good
{
  int v, w;
};

int main()
{
  cin >> n >> m;
  vector<Good> goods;

  for (int i = 0; i < n; i++)
  {
    int v, w, s;
    cin >> v >> w >> s;

    // 开始拆包
    for (int k = 1; k <= s; k *= 2)
    {
      s -= k;
      goods.push_back({v * k, w * k});
    }
    if (s > 0)
      goods.push_back({v * s, w * s});
  }

  // 01 背包的空间优化
  for (Good good : goods)
    for (int j = m; j >= good.v; j--)
      f[j] = max(f[j], f[j - good.v] + good.w);

  cout << f[m] << endl;

  return 0;
}