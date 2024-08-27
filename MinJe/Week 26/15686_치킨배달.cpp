#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int graph[51][51];
int answer = INT_MAX;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int solve(vector<int> selected);

void backtracking(int idx, vector<int> selected){
    // m개의 치킨집을 모두 선택하였다면 도시의 치킨 거리 구하기
    if (selected.size() == m){
        answer = min(answer, solve(selected));
    }
    // 백트래킹
    for (int i = idx; i < chickens.size(); i++){
        selected.push_back(i);
        backtracking(i+1, selected);
        selected.pop_back();
    }
}

int solve(vector<int> selected){
    int totalChickenDistance = 0;
    for (int i = 0; i < houses.size(); i++){
        // 치킨 거리는 100을 넘지 않음(도시의 최대 크기 50 * 50)
        int tmpChickenDistance = 100;
        for (int j = 0; j < selected.size(); j++){
            int chickenDistance = abs(chickens[selected[j]].first-houses[i].first) + abs(chickens[selected[j]].second-houses[i].second);
            tmpChickenDistance = min(tmpChickenDistance, chickenDistance);
        }
        totalChickenDistance += tmpChickenDistance;
    }
    return totalChickenDistance;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 1){
                houses.push_back({i, j});
            }
            else if (graph[i][j] == 2){
                chickens.push_back({i, j});
            }
        }
    }
    
    backtracking(0, {});
    cout << answer;
}