#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int get_primes(int x)
{
  int primes[N];
  bool st[N];
  int cnt = 0;

  for (int i = 2; i <= x; i++)
  {
    if (!st[i])
      primes[cnt++] = i;

    // 这个循环在每个 i 都会执行，所以不会有漏的
    for (int j = 0; primes[j] <= x / i; j++)
    {
      st[primes[j] * i] = true;
      // 每个数只会被其最小的质因子筛掉一次，所以如果 i 可以整除 primes[j]，
      // 那么 i*primes[j+1], i*primes[j+2] ... i*(x/i)*primes[j] 这些数都不需要再进行筛选
      if (i % primes[j] == 0)
        break;
    }
  }

  return cnt;
}

int main()
{
  int n;
  cin >> n;

  cout << get_primes(n) << endl;

  return 0;
}