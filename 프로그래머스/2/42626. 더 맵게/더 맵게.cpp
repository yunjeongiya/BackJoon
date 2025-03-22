#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int s : scoville) {
        q.push(s);
    }
    while(true) {
        if(q.top() >= K) break;
        if(q.size() < 2) return -1;
        int news = q.top();
        q.pop();
        news += 2*q.top();
        q.pop();
        q.push(news);
        answer++;
    }
    return answer;
}