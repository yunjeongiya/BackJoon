#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'

template <typename T>
struct MaxHeap {
	vector<T> data;
	bool empty() {
		return data.empty();
	}
	T top() {
		return data[0];
	}
	void pop() {
		data[0] = data[data.size() - 1];
		data.pop_back();
		heapify(0);
	}
	void push(T t) {
		data.push_back(t);
		int i = data.size() - 1;
		int parent;
		while (0 <= (parent = get_parent(i))) {
			if (parent == choose_parent(i, parent)) {
				break;
			}
			swap(data[i], data[parent]);
			i = parent;
		}
	}
private:
	int get_parent(int i) {
		return (i - 1) / 2;
	}
	int get_left_child(int i) {
		return (i + 1) * 2 - 1;
	}
	int get_right_child(int i) {
		return (i + 1) * 2;
	}
	void heapify(int i) {
		int max = i;
		int left = get_left_child(i);
		int right = get_right_child(i);
		if (left < data.size()) {
			max = choose_parent(max, left);
		}
		if (right < data.size()) {
			max = choose_parent(max, right);
		}
		if (max != i) {
			swap(data[i], data[max]);
			heapify(max);
		}
	}
	int choose_parent(int a, int b) { //TS: data[a], data[b]를 비교해야 하는데 그냥 max(a,b)를 반환함
		if (data[a] > data[b]) return a;
		return b;
	}
};

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	int N;
	cin >> N;
	MaxHeap<unsigned int> pq;
	while(N--) {
		unsigned int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << endl;
				continue;
			}
			cout << pq.top() << endl;
			pq.pop();
			continue;
		}
		pq.push(x);
	}
}