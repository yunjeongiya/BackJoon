#include <iostream>
using namespace std;
#define endl '\n'
void sol() {
	int X;
	cin >> X;

	int i = 1;
	while (X > i) { //i번째 대각선에는 총 i개가 존재함을 이용
		X -= i; 
		i++; 
	} //반복 끝나면 i번째 대각선 X번째 칸에 존재

	if (i % 2 == 1)
		cout << i + 1 - X << '/' << X << endl;
	else
		cout << X << '/' << i + 1 - X << endl;
}
int32_t main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sol();
}