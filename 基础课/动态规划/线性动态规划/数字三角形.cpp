#include <iostream>
using namespace std;

const int N = 510;
int f[N][N]; // 表示走到 [i, j] 这个点上路径的最大值
int n;

// 思路是从底往上走，直到顶点
int main()
{
  // 读入数据，因为每一层的数据只依赖上一层的数据，我们可以直接将数据读入到f[i][j]中
  // 通过状态的改变来得到答案
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      cin >> f[i][j];

  // 从下往上
  for (int i = n; i >= 0; i--)
    for (int j = 1; j <= i; j++)
      f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + f[i][j];

  cout << f[1][1] << endl;

  return 0;
}