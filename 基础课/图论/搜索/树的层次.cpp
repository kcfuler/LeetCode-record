#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[N], ne[N], idx;
int n, m;

void add(int a, int b)
{
  e[idx] = b;
  ne[idx] = h[a];
  h[a] = idx++;
}

int main()
{
  cin >> n >> m;

  return 0;
}