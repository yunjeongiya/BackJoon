#include <iostream>
using namespace std;
int main(void){
    int maxV = 0, maxI, v;
    for(int i = 1; i <= 9; i++) {
        cin >> v;
        if(v > maxV) {
            maxV = v;
            maxI = i;
        }
    }
    cout << maxV << endl << maxI;
}