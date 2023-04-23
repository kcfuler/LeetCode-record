// 这题的思路就是一个经典的 搜索 求最短距离

#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

typedef pair<int, int> PII;//定义一个pair来表示点

const int N = 110;
int g[N][N];
int d[N][N];
int n, m; // 定义终点

int dfs(){
    // 初始化队列
    deque<PII> q;
    q.emplace_back(0, 0);

    // 初始化距离数组
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    // 方向数组
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = { 0 , 1, 0, -1};

    while(q.size()){
        auto node = q.front();
        q.pop_front();

        for(int i = 0 ; i < 4 ; i++){
            int x = node.first + dx[i], y = node.second + dy[i];

            if( x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0) {
                d[x][y] = d[node.first][node.second] + 1;
                q.emplace_back(x, y);
            }
        }
    }

    return d[n - 1][m - 1];
}

int main(){
    cin>> n >> m ;
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < m; j++)
            cin>>g[i][j];

    cout<< dfs() << endl;

    return 0;
}