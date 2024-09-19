#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int nums[1000];
int dp[1000];
int parents[1000];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }

    // base case
    for (int i = 0; i < n; i++){
        dp[i] = 1;
        parents[i] = i;
    }

    int answer = 1;
    int answerIdx = 0;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (nums[i] > nums[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                parents[i] = j;
                if (answer < dp[i]){
                    answer = dp[i];
                    answerIdx = i;
                }
            }
        }
    }

    // print
    stack<int> s;
    while (answerIdx != parents[answerIdx]){
        s.push(nums[answerIdx]);
        answerIdx = parents[answerIdx];
    }
    s.push(nums[answerIdx]);

    cout << s.size() << "\n";
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}