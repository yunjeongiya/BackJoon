#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
#define MAX 100
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solution(vector<vector<int> > maps)
{

    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX < 0 || n <= nextX || nextY < 0 || m <= nextY) continue;
            if(maps[nextX][nextY] == 0 || visited[nextX][nextY]) continue;
            maps[nextX][nextY] += maps[x][y];
            if(nextX == n-1 && nextY == m-1) return maps[nextX][nextY];
        	q.push({nextX, nextY});
            visited[nextX][nextY] = true;
        }
    }
    return -1;
}