#include<bits/stdc++.h>
using namespace std;

int balance( string x )
{
	stack<char> s;
	int ret = 0;
	for ( int i = 0; i < x.size(); ++i )
	{
		char c = x[ i ];
		if ( c == '{' )
			s.push( c );
		else if ( !s.empty() && s.top() == '{' )
			s.pop();
		else {
			ret++;
			s.push( '{' );
		}
	}
	ret += s.size() / 2;
	return ret;
}

int main()
{
	int i = 1;
	while ( true )
	{
		string x;
		cin >> x;
		if ( x.find( '-' ) != string::npos )
			return 0;
		cout << "\n" << i++ << ". " << balance( x );

	}
	return 0;
}
