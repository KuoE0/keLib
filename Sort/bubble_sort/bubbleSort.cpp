#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int n;
	
	while ( ~scanf( "%d", &n ) ) {
		int x;
		vector< int > num;
		for ( int i = 0; i < n; ++i ) {
			scanf( "%d", &x );
			num.push_back( x );
		}

		for ( int i = 0; i < n - 1; ++i )
			for ( int j = 0; j < n - 1 - i; ++j )
				if ( num[ j ] > num[ j + 1 ] )
					swap( num[ j ], num[ j + 1 ] );
		for ( int i = 0; i < num.size(); ++i )
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}


