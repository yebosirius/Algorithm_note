//高精度加
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
vector<int> A, B;

vector<int> add(vector<int>& A, vector<int>& B)
{
	if (A.size() < B.size())return add(B, A);
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t += A[i];
		if (i < B.size())
			t += B[i];
		C.push_back(t % 10);
		t /= 10;
	}
	if (t)C.push_back(1);
	return C;
}

bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size())return A.size() > B.size();
	else
		for (int i = A.size() - 1; i >= 0; i--)
			return A[i] > B[i];
	return 1;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
	if (!cmp(A, B))return sub(B, A);
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size(); i++)
	{
		t = A[i] - t;
		if (i < B.size())t = t - B[i];
		C.push_back((t + 10) % 10);
		if (t < 0)t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

vector<int> mul(vector<int>& A, int &b)
{
	vector<int> C;
	int t = 0;
	for (int i = 0; i < A.size() || t; i++)
	{
		if (i < A.size())t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

vector<int> div(vector<int>& A, int &b,int &r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1; i >= 0; i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0)C.pop_back();
	return C;
}

int main()
{
	string x; cin >> x;
	if (x[0] ==  'a')
	{
	string a, b;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
	vector<int> C = add(A, B);
	for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	}
	else if (x[0] == 's')
	{

		string a, b;
		cin >> a >> b;
		vector<int> A, B;
		for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
		for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');
		vector<int> C = sub(A, B);
		if (!cmp(A, B))cout << "-";
		for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	}
	else if (x[0] == 'm')
	{
		string a; int b;
		cin >> a >> b;
		vector<int> A;
		for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
		vector<int> C = mul(A, b);
		for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	}
	else if (x[0] == 'd')
	{
		string a; int b;
		cin >> a >> b;
		vector<int> A;
		for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
		int r;
		vector<int> C = div(A, b,r);
		for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
		cout << endl << r;
	}
}