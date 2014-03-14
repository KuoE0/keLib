/*
 * knapsack.cpp
 * Copyright (C) 2014 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100
#define MAXW 1000

int num_item, cap_knasack;
int val[MAXN], weight[MAXN];
int dp[MAXN][MAXW];

int DP(int x, int w) {
	// invalid weight
	if (w < 0) {
		return -1e9;
	}
	// calculated value
	if (dp[x][w] != -1) {
		return dp[x][w];
	}
	// put item x or not
	dp[x][w] = max(DP(x - 1, w), DP(x - 1, w - weight[x]) + val[x]);
	return dp[x][w];
}

int TSPTopDown() {
	// init
	memset_s(dp, sizeof(dp), -1, sizeof(dp));
	// empty knapsack init
	for (int i = 0; i <= cap_knasack; ++i) {
		dp[0][i] = 0;
	}
	return DP(num_item, cap_knasack);
}

int TSPBottomUp() {
	// init
	memset_s(dp, sizeof(dp), 0, sizeof(dp));
	for (int i = 1; i <= num_item; ++i) {
		// copy previous result
		memcpy(dp[i], dp[i - 1], sizeof(dp[i]));
		for (int j = weight[i]; j <= cap_knasack; ++j) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i]] + val[i]);
		}
	}
	return dp[num_item][cap_knasack];
}

int main() {

	while (~scanf("%d %d", &num_item, &cap_knasack)) {

		int w, v;
		for (int i = 1; i <= num_item; ++i) {
			scanf("%d %d", &w, &v);
			weight[i] = w;
			val[i] = v;
		}

#ifdef TOPDOWN
		printf("%d\n", TSPTopDown());
#endif
#ifdef BOTTOMUP
		printf("%d\n", TSPBottomUp());
#endif
	}
	return 0;
}

