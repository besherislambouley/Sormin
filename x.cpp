/*
 * https://github.com/zoooma13/Competitive-Programming/blob/master/sormin.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 400
#define mp make_pair
#define mid (l+r)/2
#define Le Node * 2 
#define Ri Node * 2 + 1 
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef pair<double,ll>pdi;
const ll inf=1e18;
const ll Mod=1e9+7;
const ld pai=acos(-1);
int N , Mx , n , Sum ;
pi a [100009] , P [50009] ;
int Num [5009] ;
int Check ( int Out ) {
	bitset <50009> Dp ;
	Dp |= 1 ;
	for ( int i = 0 ; i < N ; i ++ ) {
		if ( ( Out & a [i] .se ) ) C ;
		Dp |= ( Dp << a [i] .fi ) ;
	}
	return Dp [Sum] ; 
}
int main () {
	freopen("sormin.in" ,"r" ,stdin);
    	freopen("sormin.out" ,"w" ,stdout);
	scanf("%d%d",&n,&Sum) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		int x ;
		scanf("%d",&x) ;
		Num [x] ++ ;
		Mx = max ( Mx , x ) ;
	}
	for ( int i = 1 ; i <= Mx ; i ++ ) {
		Num [i] = min ( Num [i] , Sum / i ) ;
		int Pow = 1 ;
		while ( Num [i] >= Pow ) {
			a [N++] = { i * Pow , i } ;
			Num [i] -= Pow ;
			Pow *= 2 ;
		}
		if ( Num [i] > 0 ) a [N++] = { Num [i] * i , i } ;
	}
	int Out = 0 ;
	for ( int Bit = 13 ; Bit >= 0 ; Bit -- ) {
		if ( Check ( ( Out | ( 1 << Bit ) ) ) ) 
			Out |= ( 1 << Bit ) ;
	}
	bitset <50009> Dp ; 
	Dp |= 1 ;
	for ( int i = 0 ; i < N ; i ++ ) {
		if ( ( Out & a [i] .se ) ) C ;
		for ( int j = Sum ; j >= a [i] .fi ; j -- ) {
			if ( !Dp [j] && Dp [j-a[i].fi] ) {
				Dp [j] = 1 ;
				P  [j] = a [i] ; 
			}
		}
	}
	vi Ans ;
	while ( Sum > 0 ) {
		int Num = P [Sum] .fi / P [Sum] .se ;
		int Val = P [Sum] .se ;
		for ( int i = 0 ; i < Num ; i ++ ) 
			Ans .pb ( Val ) ;
		Sum -= P [Sum] .fi ;
	}
	cout << ( ( ( 1 << 14 ) - 1 ) ^ Out ) << " " << Ans .size () << endl ;
	for ( auto u : Ans ) printf("%d ",u) ;
	cout << endl ;
}
