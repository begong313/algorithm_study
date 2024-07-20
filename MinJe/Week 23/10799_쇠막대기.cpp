#include <iostream>
#include <stack>
using namespace std;

int main(){
    string input;
    cin >> input;

    int answer = 0;
    int sticks = 0;

    // 처음은 무조건 '('로 시작
    for (int i = 0; i < input.length(); i++){
        // '('인 경우
        if (input[i] == '('){
            // 쇠막대기인지 레이저인지 모르는 상태.
            // 일단 쇠막대기라 생각하고 sticks++
            sticks++;
            answer++;
        }
        // ')'인 경우
        else{
            // 쇠막대기인 경우 - 이전 값이 ')'
            if (input[i-1] == ')'){
                sticks--;
            }
            // 레이저인 경우 - 이전 값이 '('
            // 레이저인 경우에서 stick을 추가해주었으므로 sticks--;
            else{
                sticks--;
                answer--;
                answer += sticks;
            }
        }   
    }

    cout << answer;
}