#include <iostream>
using namespace std;

const int N = 1e6 + 10; // 注意数据范围

// 标记一个数是质数之后，标记所有在范围之内的它的倍数
int is_Prime(int x)
{
  int primes[N];
  bool st[N];
  int cnt = 0; // 记录质数的数量

  for (int i = 2; i <= x; i++)
  {
    if (st[i])
      continue;
    primes[cnt++] = i;
    // 给所有的倍数打上标记
    for (int j = i; j <= x; j = j + i)
      st[j] = true;
  }

  return cnt;
}

int main()
{
  int n;
  cin >> n;
  cout << is_Prime(n) << endl;
  return 0;
}