#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int cnt = 0, confirmed = 0, sum = 0;

void func(bool plus, vector<int> numbers, int target) {
    if(confirmed == numbers.size()) {
        if(sum == target) cnt++;
        return;
    }
    sum += numbers[confirmed];
    confirmed++;
    func(true, numbers, target);
    confirmed--;
    sum -= 2 * numbers[confirmed];
    confirmed++;
    func(false, numbers, target);
    confirmed--;
    sum += numbers[confirmed];
}

int solution(vector<int> numbers, int target) {
    sum += numbers[confirmed];
    confirmed++;
    func(true, numbers, target);
    confirmed--;
    sum -= 2 * numbers[confirmed];
    confirmed++;
    func(false, numbers, target);
    confirmed--;
    sum += numbers[confirmed];
    return cnt;
}