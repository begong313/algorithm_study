#include <iostream>
#include <queue>
using namespace std;

int trucks[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, l;
    cin >> n >> w >> l;

    for (int i = 0; i < n; i++){
        cin >> trucks[i];
    }

    queue<int> bridge;
    for (int i = 0; i < w; i++){
        bridge.push(0);
    }

    int bridgeWeight = 0;
    int answer = 0;
    for (int i = 0; i < n; i++){
        while (true){
            bridgeWeight -= bridge.front();
            bridge.pop();
            if (l >= bridgeWeight + trucks[i]){
                break;
            }
            else{
                bridge.push(0);
                answer++;
            }
        }
        bridgeWeight += trucks[i];
        bridge.push(trucks[i]);
        answer++;
    }
    cout << answer + w;
}