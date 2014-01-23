/*=============================================================================
#     FileName: selectionSort.cpp
#         Desc: Selecetion Sort
#				1. find minimum element in unsorted part
#				2. put minimum element at end of sorted part
#				3. repeat above steps until unsorted part is empty
#       Author: KuoE0
#        Email: kuoe0.tw@gmail.com
#     HomePage: http://kuoe0.ch/
#      Version: 0.0.1
#   LastChange: 2013-03-04 14:31:13
#      History:
=============================================================================*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void selectionSort( vector< int > &num ) {

	for ( int i = 0; i < num.size(); ++i ) {
		// find the minimum element in unsorted part
		int MIN = num[ i ], pos = i;
		for ( int j = i + 1; j < num.size(); ++j ) {
			if ( MIN > num[ j ] )
				MIN = num[ j ], pos = j;
		}
		// put the minimum element at end of sorted part
		swap( num[ i ], num[ pos ] );
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

		selectionSort( num );
		for ( int i = 0; i < num.size(); ++i )
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}


