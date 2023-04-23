#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N ; // 存储无向图
int h[N], e[M], ne[M], idx;
int n, ans = N; // 这个 N 是边界值
bool st[N];

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dfs(int u) {
    st[u] = true;
    int res = 0;
    int sum = 1;

    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];

        if( !st[j] ) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }

    res = max(res, n - sum);
    ans = min(res, ans);

    return sum;
}


int main (){

    cin >> n;
    memset(h, -1, sizeof h);

    int a, b;
    for(int i = 0 ; i < n ;i ++) {
        cin>> a >> b;
        add(a, b), add(b , a);
    }

    dfs(1);

    cout<< ans << endl;

    return 0;
}