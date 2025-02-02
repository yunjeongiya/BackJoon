#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "RCJA";
    //survey의 원소는 "RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA"
    //RT -> 비동의면 R 동의면 T
    int points[4] = {0, 0, 0, 0};
    for(int i = 0; i < survey.size(); i++) {
        int point = choices[i] - 4;
        string s = survey[i];
        
        switch (s[1]) { //동의면 늘어나는 요소가
            case 'R':
                points[0] += point;
                break;
            case 'T':
                points[0] -= point;
                break;
            case 'C':
                points[1] += point;
                break;
            case 'F':
                points[1] -= point;
                break;
            case 'J':
                points[2] += point;
                break;
            case 'M':
                points[2] -= point;
                break;
            case 'A':
                points[3] += point;
                break;
            case 'N':
                points[3] -= point;
                break;
        }
    }
    
        if (points[0] < 0) {
            answer[0] = 'T';
        }
        if (points[1] < 0) {
            answer[1] = 'F';
        }
        if (points[2] < 0) {
            answer[2] = 'M';
        }
        if (points[3] < 0) {
            answer[3] = 'N';
        }
    return answer;
    //return to_string(points[3]) + answer[3];
    //return to_string(points[0]) + to_string(points[1]) + to_string(points[2]) + to_string(points[3]);
}