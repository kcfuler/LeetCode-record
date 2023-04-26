#include <iostream>
using namespace std;

// 思路就是每找到一个质因子，就把它从数中除干净，记录下它有多少个
// 输出每一对质因子
// 如果最后 n != 1 ， 说明它本身也是质因子
void divide(int n)
{
  for (int i = 2; i <= n / i; i++)
  {
    if (n % i == 0)
    {
      int s = 0;
      while (n % i == 0)
      {
        n /= i;
        s++;
      }
      cout << i << " " << s << endl;
    }
  }

  if (n > 1)
    cout << n << " " << 1 << endl;
}

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    int a;
    cin >> a;
    divide(a);
    cout << endl;
  }

  return 0;
}