#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100001];
bool visited[100001];
int parents[100001];


void dfs(int node){
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if (!visited[next]){
            parents[next] = node;
            dfs(next);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; i++){
        cout << parents[i] << "\n";
    }
}