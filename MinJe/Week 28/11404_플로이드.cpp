#include <iostream>
#include <algorithm>
// 도시의 개수는 최대 100, 비용은 최대 100,000
#define INF 10000001
using namespace std;

int cost[101][101];

void init(int n){
    // 모든 정점을 무한대로 초기화
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cost[i][j] = INF;
        }
        // 단, 시작과 도착이 같은 경우는 0으로 초기화
        cost[i][i] = 0;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    init(n);

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있음
        cost[a][b] = min(cost[a][b], c);
    }

    for (int middle = 1; middle <= n; middle++){
        for (int start = 1; start <= n; start++){
            for (int end = 1; end <= n; end++){
                if (cost[start][end] > cost[start][middle] + cost[middle][end]){
                    cost[start][end] = cost[start][middle] + cost[middle][end];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (cost[i][j] == INF){
                cout << 0 << " ";
            }
            else{
                cout << cost[i][j] << " ";
            }
        }
        cout << endl;
    }
}