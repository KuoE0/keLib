/*=============================================================================
#     FileName: mergeSort.cpp
#         Desc: Natural Merge Sort
#       Author: KuoE0
#        Email: kuoe0.tw@gmail.com
#     HomePage: http://kuoe0.ch/
#      Version: 0.0.1
#   LastChange: 2013-03-05 02:55:56
#      History:
=============================================================================*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void mergeSort( vector< int > &num ) {
	// divide sequence
	vector< int > left, right;
	for ( int i = 0, cur = num[ 0 ], p = 0; i < num.size(); ++i ) {
		// if next element is decreasing, put to another part.
		if ( num[ i ] < cur )
			p = ++p % 2;
		p ? left.push_back( num[ i ] ) : right.push_back( num[ i ] );
		cur = num[ i ];
	}
	if ( left.empty() || right.empty() )
		return;
	// sort sub-sequence
	mergeSort( left );
	mergeSort( right );
	// merge
	// i point to origin, j point to left, k point to right
	for ( int i = 0, j = 0, k = 0; i < num.size(); ++i ) {
		// if left is less than right or right part is end.
		if ( ( j != left.size() && left[ j ] < right[ k ] ) || k == right.size() )
			num[ i ] = left[ j++ ];
		// if right is less than or equal to left or left part is end.
		else
			num[ i ] = right[ k++ ];
	}
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

		mergeSort( num );
		for ( int i = 0; i < num.size(); ++i ) 
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}

