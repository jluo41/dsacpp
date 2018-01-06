#include<time.h>
#include<iostream>
using namespace std;

#include "Fib.h"

__int64  fibI( int n ); 
__int64  fib ( int n ); 
__int64  fib ( int n, __int64& f ); 

int main ( int argc, char* argv[] ) { 
   if ( 2 > argc ) { 
	   fprintf ( stderr, "Usage: %s <rank>\n", argv[0] );
	   return 1;
   }
   int n = atoi ( argv[1] );

   printf ( "\n------------- class Fib -------------\n" );
   Fib f ( 0 );
  
   for ( int i = 0; i < n; i++, f.next() )
	   printf ( "fib(%2d) = %d\n", i, f.get() );
   
   for ( int i = 0; i <= n; i++, f.prev() )
		printf ( "fib(%2d) = %d\n", n - i, f.get() );
  
   printf ( "\n------------- Iteration -------------\n" );
   for ( int i = 0; i < n; i++ )
		printf ( "fib(%2d) = %22I64d\n", i, fibI ( i ) );
   
   printf ( "\n------------- Linear Recursion -------------\n" );
   for ( int i = 0; i < n; i++ ) {
		__int64 f;
		printf ( "fib(%2d) = %22I64d\n", i, fib ( i, f ) );
   }

   printf ( "\n------------- Binary Recursion -------------\n" );
   for ( int i = 0; i < n; i++ )
		printf ( "fib(%2d) = %22I64d\n", i, fib ( i ) );
   return 0;
}
