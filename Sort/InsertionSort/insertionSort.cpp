/*=============================================================================
#     FileName: insertionSort.cpp
#         Desc: Insertion Sort
#       Author: KuoE0
#        Email: kuoe0.tw@gmail.com
#     HomePage: http://kuoe0.ch/
#      Version: 0.0.1
#   LastChange: 2013-03-04 00:42:04
#      History:
=============================================================================*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void insertionSort( vector< int > &num ) {
	for ( int i = 1; i < num.size(); ++i ) {
		int temp = num[ i ], pos = i; // record current value
		// find the insertion position
		for ( int j = pos - 1; j >= 0 && num[ j ] > temp; --j )
			num[ j + 1 ] = num[ pos = j ];
		num[ pos ] = temp;
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

		insertionSort( num );

		for ( int i = 0; i < num.size(); ++i )
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}
