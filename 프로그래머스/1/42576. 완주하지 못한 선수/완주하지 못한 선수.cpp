#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(auto& p: participant){
        if(m.find(p) == m.end()) {
            m.insert({p, 0});
        }
        m[p]++;
    }
    for(auto& c: completion) {
        if(m.find(c)->second == 1) m.erase(c);
        else m[c]--;
    }
    return m.begin()->first;
}