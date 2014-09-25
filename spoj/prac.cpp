#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#define f( i , a , b ) for(int i = a ; i < b ; i++)
#define clr( x , y ) memset( x , y , sizeof x )
#define all( x ) x.begin() , x.end()
#define mp make_pair
#define debug( x ) cout << #x << " = " << x << endl
#define TAM 1000010
 
using namespace std ;
 
typedef pair<int,int> ii ;
typedef pair<ii,ii> pii ; // { { idx , dir } , { x , y } }
 
int dx[] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 } ;
int dy[] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 } ;
 
int fail[ TAM ] ;
int sig[ TAM ][ 30 ] ;
vector<int> final[ TAM ] ;
int end ;
char words[ 1010 ][ 1010 ] ;
char tab[ 1010 ][ 1010 ] ;
int L , C , W ;
 
void init(){
end = 1 ;
clr( sig[ 0 ] , 0 ) ;
final[ 0 ].clear() ;
}
 
 
void add( string s , int idx ){
int len = s.size() ;
int nodo = 0 ;
f( i , 0 , len ){
int c = s[ i ] - 'A' ;
if( !sig[ nodo ][ c ] ){
final[ end ].clear() ;
clr( sig[ end ] , 0 ) ;
sig[ nodo ][ c ] = end++ ;
}
nodo = sig[ nodo ][ c ] ;
}
final[ nodo ].push_back( idx ) ;
}
 
void build(){
queue<int> q ;
f( i , 0 , 30 ){
int next = sig[ 0 ][ i ] ;
if( next ){
fail[ next ] = 0 ;
q.push( next ) ;
}
}
while( !q.empty() ){
int nodo = q.front() ; q.pop() ;
f( i , 0 , 30 ){
int next = sig[ nodo ][ i ] ;
int rev = sig[ fail[ nodo ] ][ i ] ;
if( !next ) sig[ nodo ][ i ] = rev ;
else{
q.push( next ) ;
fail[ next ] = rev ;
f( i , 0 , final[ rev ].size() ) final[ next ].push_back( final[ rev ][ i ] ) ;
}
}
}
}
 
bool valid( int val , int mx ){
return val >= 0 && val < mx ;
}
 
vector<pii> search( int x , int y , int dir ){
vector<pii> v ;
int nodo = 0 , nx = x , ny = y ;
// printf("/* ======== DIR %d ======== */\n" , dir ) ;
while( valid( nx , L ) && valid( ny , C ) ){
int car = tab[ nx ][ ny ] - 'A' ;
while( nodo != 0 && !sig[ nodo ][ car ] ) nodo = fail[ nodo ] ;
nodo = sig[ nodo ][ car ] ;
f( i , 0 , final[ nodo ].size() ){
int len = strlen( words[ final[ nodo ][ i ] ] ) - 1 ;
v.push_back( mp( mp( final[ nodo ][ i ] , dir ) , mp( nx - len * dx[ dir ] , ny - len * dy[ dir ] ) ) ) ;
}
nx += dx[ dir ] ;
ny += dy[ dir ] ;
}
return v ;
}
 
int main(){
 
int test ;
scanf("%d" , &test ) ;
f( k , 0 , test ){
scanf("%d%d%d" , &L , &C , &W ) ;
// debug( L ) ; debug( C ) ; debug( W ) ;
f( i , 0 , L ) scanf( "%s" , tab[ i ] ) ;
init() ;
f( i , 0 , W ){
scanf( "%s" , words[ i ] ) ;
add( words[ i ] , i ) ;
}
build() ;
vector<pii> aux ;
vector<pii> resp[ W + 1 ] ;
f( i , 0 , L ){
aux = search( i , 0 , 2 ) ; // right
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( i , 0 , 1 ) ; // right up
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( i , 0 , 3 ) ; // right down
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
 
aux = search( i , C - 1 , 6 ) ; // left
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( i , C - 1 , 7 ) ; // left up
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( i , C - 1 , 5 ) ; // left down
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
}
f( i , 0 , C ){
aux = search( 0 , i , 4 ) ; // down
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( 0 , i , 3 ) ; // down right
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( 0 , i , 5 ) ; // down left
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
 
aux = search( L - 1 , i , 0 ) ; // up
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( L - 1 , i , 1 ) ; // up right
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
aux = search( L - 1 , i , 7 ) ; // up left
f( j , 0 , aux.size() ) resp[ aux[ j ].first.first ].push_back( aux[ j ] ) ;
}
if( k ) printf("\n" ) ;
// sort( all( resp ) ) ;
f( i , 0 , W ) printf("%d %d %c\n" , resp[ i ][ 0 ].second.first , resp[ i ][ 0 ].second.second , resp[ i ][ 0 ].first.second + 'A' ) ;
}
 
return 0 ;
}
