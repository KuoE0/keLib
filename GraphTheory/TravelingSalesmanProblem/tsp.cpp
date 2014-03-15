/*
 * tsp.cpp
 * Copyright (C) 2014 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 16

int N, E;
vector< vector< int > > graph;
int dp[1 << MAXN][MAXN];

int DP(int visited, int now)
{
	// already calculated
	if (dp[visited][now] != -1) {
		return dp[visited][now];
	}
	dp[visited][now] = (int)1e9;
	// iteratively visit unvisited cities
	for (int i = 0; i < N; ++i) {
		int mask = 1 << i;
		if (!(visited & mask)) {
			dp[visited][now] = min(dp[visited][now], DP(visited | mask, i) + graph[now][i]);
		}
	}
	return dp[visited][now];
}

int TSP(int src)
{
	// init
	memset(dp, -1, sizeof(dp)); 
	// init the path from source to each city
	for (int i = 0; i < N; ++i) {
		dp[(1 << N) - 1][i] = graph[0][i];
	}
	return DP(1 << src, src);
}

int main()
{
	while (~scanf("%d %d", &N, &E)) {
		int a, b, w;
		graph = vector< vector< int > >(N, vector< int >(N, (int)1e9));
		for (int i = 0; i < E; ++i) {
			scanf("%d %d %d", &a, &b, &w);
			graph[a][b] = graph[b][a] = w;
		}
		printf("%d\n", TSP(0));
	}
	return 0;
}

