#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 300001
using namespace std;
pair<int, int> jewels[MAX];
int bags[MAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;


    for (int i = 0; i < N; i++){
        int m, v;
        cin >> m >> v;
        jewels[i] = {m, v};
    }
    for (int i = 0; i < K; i++){
        cin >> bags[i];
    }

    sort(jewels, jewels+N); // 무게, 가격 순으로 정렬
    sort(bags, bags+K);

    long long answer = 0;
    int jewelIdx = 0;

    priority_queue<int> values;
    
    for (int i = 0; i < K; i++){
        while (jewelIdx < N && bags[i] >= jewels[jewelIdx].first){
            values.push(jewels[jewelIdx].second);
            jewelIdx++;
        }
        if (!values.empty()){
            answer += values.top();
            values.pop();
        }
    }
    
    cout << answer;
}