#include <iostream>
using namespace std;
#define DMAX 30
int fibo[DMAX+1] = { 0, 1, };
void fill_fibo_until(int n) {
    for (int i = 2; i <= n; i++) {
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }
}

void sol() {
    int D, K, A=1, B;
    cin >> D >> K;
    fill_fibo_until(D); //3<=D<=30
    //K=fibo[D-2]*A+fibo[D-1]*B
    while ((K - fibo[D - 2] * A) % fibo[D - 1] || 
        A > (B = (K - fibo[D - 2] * A) / fibo[D - 1])) A++;
    cout << A << '\n' << B;
}

int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}