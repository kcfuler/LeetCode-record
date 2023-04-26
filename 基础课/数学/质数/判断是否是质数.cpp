#include <iostream>
using namespace std;

// 质数不能被1以外的数整除
bool is_prime(int x)
{
  if (x < 2) // 如果小于2，一定不成立
    return false;

  for (int i = 2; i <= x / i; i++)
  {
    if (x % i == 0)
      return false;
  }

  return true;
}

int main()
{
  int n;

  cin >> n;

  while (n--)
  {
    int a;
    cin >> a;

    if (is_prime(a))
      puts("Yes");
    else
      puts("No");
  }

  return 0;
}