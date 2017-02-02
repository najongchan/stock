#include<iostream>
#include<vector>

using namespace std;
long long start() {
	int day;
	int price;
	vector <int> stock;
	int max = 0;
	int max_point;
	int last_max_point = 0;
	long long profit = 0;

	cin >> day;
	for (int i = 0; i < day; i++) {
		cin >> price;
		stock.push_back(price);
	}
	while (day) {
		max = 0;
		for (int i = last_max_point; i < stock.size(); i++) {
			if (max <= stock[i]) {
				max = stock[i];
				max_point = i;
			}
		}
		if (last_max_point == max_point) {
			last_max_point++;
			day--;
		}
		else {
			for (int i = last_max_point; i < max_point; i++) {
				int temp = stock[max_point] - stock[i];
				profit += temp;
				day--;
			}
			last_max_point = max_point;
		}
	}
	return profit;
}


int main() {
	vector<long long> output;
	int testcase;

	cin >> testcase;
	for (int a = 0; a < testcase; a++) {
		output.push_back(start());
	}
	vector<long long>::iterator iter = output.begin();
	for (iter = output.begin(); iter != output.end(); ++iter) {
		cout << *iter << endl;
	}
}