/*=============================================================================
#     FileName: quickSort.cpp
#         Desc: Quick Sort
#       Author: KuoE0
#        Email: kuoe0.tw@gmail.com
#     HomePage: http://kuoe0.ch/
#      Version: 0.0.1
#   LastChange: 2013-03-05 03:17:47
#      History:
=============================================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void quickSort( vector< int > &num, int L, int R ) {
	// if seqence is empty, return
	if ( L == R )
		return;
	// put all elements less than pivot to left, and others to right
	int pivot = num[ R - 1 ], pos = L;
	for ( int i = L; i < R - 1; ++i )
		if ( num[ i ] < pivot )
			swap( num[ i ], num[ pos++ ] );
	// put pivot between left part and right part
	swap( num[ R - 1 ], num[ pos ] );
	// sort sub-seqence
	quickSort( num, L, pos );
	quickSort( num, pos + 1, R );
}

int main() {
	int n;
	while ( ~scanf( "%d", &n ) ) {
		int x;
		vector< int > num;
		for ( int i = 0; i < n; ++i ) {
			scanf( "%d", &x );
			num.push_back( x );
		}

		quickSort( num, 0, num.size() );
		for ( int i = 0; i < num.size(); ++i )
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}


