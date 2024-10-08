#include <iostream>
#include <stack>
using namespace std;

#define MAX 100001
int t, n;
int s[MAX];
bool visited[MAX];
int answer = 0;
stack<int> students;

void reset(){
    answer = 0;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
    }
}

void solve(int student){
    visited[student] = true;
    students.push(student);
    int next = s[student];

    // 선택한 학생이 본인과 같다면 리턴
    if (next == student){
        answer++;
        return;
    }
    // 선택한 학생이 이미 선택된 학생이라면
    if (visited[next]){
        int studentsSize = students.size();
        // 이미 선택된 학생을 찾기 위해 pop을 반복
        while (!students.empty() && students.top() != next){
            students.pop();
        }
        // 만약 스택에 원소가 존재한다면 사이클이 존재함
        if (!students.empty()){
            answer += (studentsSize-students.size()+1);
        }
        // 만약 스택이 비어있다면 사이클이 없는 것임
        return;
    }
    else{
        solve(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--){
        cin >> n;
        
        for (int i = 1; i <= n; i++){
            cin >> s[i];
        }
        
        reset();
        
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                while (!students.empty()){
                    students.pop();
                }
                solve(i);
            }
        }

        cout << n-answer << "\n";
    }
}