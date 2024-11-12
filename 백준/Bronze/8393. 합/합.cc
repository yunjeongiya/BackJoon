//첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.
//1부터 n까지 합을 출력한다.  
#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int sum = n;
    while(n--){
        sum+=n;
    }
    cout << sum;
}