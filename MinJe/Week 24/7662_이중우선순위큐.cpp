#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        priority_queue<int> upperQue;
        priority_queue<int, vector<int>, greater<int>> lowerQue;
        map<int, int> cntNums;

        int k;
        cin >> k;

        while (k--){
            char letter;
            int n;
            cin >> letter >> n;

            if (letter == 'I'){
                lowerQue.push(n);
                upperQue.push(n);
                cntNums[n]++;
            }
            else{
                if (n == 1){
                    while (!upperQue.empty() && cntNums[upperQue.top()] == 0){
                        upperQue.pop();
                    }
                    if (!upperQue.empty()){
                        cntNums[upperQue.top()]--;
                        upperQue.pop();
                    }
                }
                else{
                    while (!lowerQue.empty() && cntNums[lowerQue.top()] == 0){
                        lowerQue.pop();
                    }
                    if (!lowerQue.empty()){
                        cntNums[lowerQue.top()]--;
                        lowerQue.pop();
                    }
                }
            }
        }

        while (!upperQue.empty() && cntNums[upperQue.top()] == 0){
            upperQue.pop();
        }
        while (!lowerQue.empty() && cntNums[lowerQue.top()] == 0){
            lowerQue.pop();
        }

        if (lowerQue.empty() || upperQue.empty()){
            cout << "EMPTY" << "\n";
        }
        else{
            cout << upperQue.top() << " " << lowerQue.top() << "\n";
        }
        
    }
}