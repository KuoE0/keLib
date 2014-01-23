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
#include <ctime>
using namespace std;

void quickSort( vector< int > &num ) {
	// if sequence is empty, return
	if ( num.empty() )
		return;
	// set pivot
	int pivot_idx= rand() % num.size();
	int pivot = num[ pivot_idx ];
	// divide sequence by pivot
	vector< int > lt, gt;
	// put element less than pivot to lt, and others to gt
	for ( int i = 0; i < num.size(); ++i )
		if ( i != pivot_idx )
			num[ i ] < pivot ? lt.push_back( num[ i ] ) : gt.push_back( num[ i ] );
	// sort sub-sequence
	quickSort( lt );
	quickSort( gt );
	// clear original sequence
	num = vector< int >();
	// merge: less than pivot -> pivot -> greater than pivot
	num.insert( num.end(), lt.begin(), lt.end() );
	num.insert( num.end(), pivot );
	num.insert( num.end(), gt.begin(), gt.end() );
}

int main() {
	int n;
	srand( time( NULL ) );
	while ( ~scanf( "%d", &n ) ) {
		int x;
		vector< int > num;
		for ( int i = 0; i < n; ++i ) {
			scanf( "%d", &x );
			num.push_back( x );
		}

		quickSort( num );
		for ( int i = 0; i < num.size(); ++i )
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}


