#include<bits/stdc++.h>
/*
	sprendimas eina iš kairės ir bando pakeisti dabartinį skaitmenį į kuo didesnį
*/
using namespace std;
using ll = long long;

vector<ll> powsOfTen;
string num;
vector<int> sk;
ll M;

void init(int N) {
	powsOfTen.resize(N);
	powsOfTen[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		powsOfTen[i] = (10LL * powsOfTen[i - 1]) % M;
	}
	reverse(powsOfTen.begin(), powsOfTen.end());
}

int main() {
	cin >> num >> M;
	for (char u : num) sk.emplace_back(u - '0');
	int N = (int)num.size();
	init(N);

	ll remainder = 0;
	for (int i = 0; i < N; ++i)
	{
		remainder = (remainder + powsOfTen[i] * sk[i]) % M;
	}

	for (int i = 0; i < N; ++i)
	{
		int newDigit = 9;
		while (newDigit > sk[i]) {
			ll newRemainder = (remainder + powsOfTen[i] * (newDigit - sk[i])) % M;
			if (newRemainder > remainder) {
				sk[i] = newDigit;
				remainder = newRemainder;
				break;
			}
			newDigit--;
		}
	}

	for (int i : sk) cout << i;
	cout << '\n';
}