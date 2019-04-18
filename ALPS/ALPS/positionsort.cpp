#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
int x[100001], y[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cin >> y[i];
	}

	vector< pair<int, int> >v;
	for (int i = 0; i < n; i++) {
		v.push_back(pair<int, int>(x[i], y[i]));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << '\n';

}