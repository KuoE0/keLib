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

		bool flag = true;
		for ( int i = 0; flag && i < n - 1; ++i ) {
			flag = false;
			for ( int j = 0; j < n - 1 - i; ++j )
				if ( num[ j ] > num[ j + 1 ] ) {
					swap( num[ j ], num[ j + 1 ] );
					flag = true;
				}
		}
		for ( int i = 0; i < num.size(); ++i )
			printf( "%d ", num[ i ] );
		puts( "" );
	}
	return 0;
}


