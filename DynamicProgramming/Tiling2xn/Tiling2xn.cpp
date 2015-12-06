﻿#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cassert>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static const int DEN = 1000000007;

static const int MAXN = 10000;

// t(0) = 1, t(1) = 1, t(n) = t(n-1) + t(n-2)
// 시간복잡도 O(N)
// 공간복잡도 O(N). 반복적 DP에서는 O(1)으로 줄일 수 있음.
// Fibonacci 참조

// 1. memoization -> recursion overhead. stack overflow.
static int cache1[MAXN + 1];

void init_cache1()
{
	for (int i = 0; i <= MAXN; ++i)
		cache1[i] = -1;
}

int tiling1(int n)
{
	if (cache1[n] >= 0)
		return cache1[n];
	if (n == 0 || n == 1)
		return cache1[n] = 1;
	int v = tiling1(n - 1) + tiling1(n - 2);
	return cache1[n] = v > DEN ? v - DEN : v;
}

int main(int argc, char* argv[])
{
	init_cache1();

	int ns[] = { 4, 0, 10, 1, 2, 5, 3, 60, 80, 100, 1000 };
	for (int n : ns) {
		printf("%d : %d\n", n, tiling1(n));
	}
	return 0;
}
