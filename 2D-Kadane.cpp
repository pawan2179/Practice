#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int arr[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)    cin >> arr[i][j];
	}

	int maxSum = INT_MIN;
	int i = 0;
	int j = 0;
	int temp[m] = {0};
	int start_row = -1;
	int end_row = -1;
	int start_col = 0;
	int end_col = 0;

	for (int i = 0; i < n; i++) {
		memset(temp, 0, sizeof(temp));
		for (int j = i; j < n; j++) {
			int sum = 0;
			start_col = 0;

			for (int k = 0; k < m; k++) {
				temp[k] += arr[j][k];
			}
			for (int k = 0; k < m; k++) {
				sum += temp[k];

				if (sum > maxSum) {
					maxSum = sum;
					end_col = k;
					start_row = i;
					end_row = j;
				}
				if (sum < 0) {
					sum = 0;
					start_col = i + 1;
					end_col = i + 1;
				}
			}
		}
	}
	//cout << "start_row = " << start_row << " end_row = " << end_row << endl;
	//cout << "start_col = " << start_col << " end_col = " << end_col << endl;
	cout << maxSum << endl;

	return 0;
}