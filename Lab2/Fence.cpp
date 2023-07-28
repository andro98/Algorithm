#include<iostream>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int* heights = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> heights[i];
	}

	int* dp = new int[n];
	for (int i = 0; i < n; i++) {
		dp[i] = 0;
	}

	dp[0] = heights[0];
	for (int i = 1; i < n; i++) {
		dp[i] = heights[i] + dp[i-1];
		if (i - k >= 0) {
			dp[i] -= heights[i - k];
		}
	}

	int min = INT_MAX;
	int index = 0;
	for (int i = k - 1; i < n; i++) {
		int res = dp[i];
		if (res < min) {
			min = res;
			index = i - k;
		}
	}

	std::cout << index + 2 << std::endl;

	delete[] heights;
	delete[] dp;
	return 0;
}