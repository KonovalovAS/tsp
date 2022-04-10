#include "head.h"
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void vertex::show(){
	cout<<x<<" "<<y<<"\n";
}

double distance( vertex v1, vertex v2 ){
	return sqrt( pow( v1.x-v2.x , 2 ) + pow( v1.y-v2.y , 2 ) );
}

Path::Path( vector<vertex> &path_init ){
	path = path_init;
}

int Path::size(){
	return path.size();
}

vertex Path::operator[](int i){
	if( i < path.size() )
		return path[i];
	else
		return {-1,0,0};
}

double Path::cost(){
	double s(0);
	for(int i=1; i<path.size(); i++){
		s += distance( path[i-1], path[i]  );
	}
	return s;
}

void Path::try_to_improve_2(int v1, int v2){

	// cout<<"improving for "<<v1<<", "<<v2<<"\n";

	if(v1>v2) swap(v1,v2);
	double init_dist = distance( path[v1], path[v1+1] )
			 + distance( path[v2], path[v2+1] );

	// improval attempt
	double new_dist = distance( path[v1], path[v2] ) + distance( path[v1+1], path[v2+1] );
	if( init_dist > new_dist ){
		cout<<"New dist: "<<new_dist<<"\n";
		vector<vertex>::iterator it1 = next( path.begin(), v1+1 );
		vector<vertex>::iterator it2 = next( it1, v2-v1 );
		cout<<(*it1).x<<" "<<(*it1).y<<" "<<(*it2).x<<" "<<(*it2).y<<"\n";
		reverse( it1, it2 );
	}
}

void Path::local_search_2(){
	int n = path.size();
	for(int i=0; i<n-3; i++)
		for(int j=i+2; j<n-1; j++)
			this->try_to_improve_2(i,j);
}

void Path::try_to_improve_3(int v1, int v2, int v3){
	// cout<<"improving for "<<v1<<", "<<v2<<" "<<v3<<"\n";

	vector<vertex> tmp = { path[v1], path[v1+1],
				path[v2], path[v2+1],
				path[v3], path[v3+1] };
	vector<vector<double>> d(6,vector<double> (6,0));

	for(int i=1; i<6; i++)
		for(int j=i; j<6; j++)
			d[i][j] = distance( tmp[i], tmp[j] );

	vector<double> options = {
		d[0][1] + d[2][3] + d[4][5],
		d[0][4] + d[1][4] + d[2][5],
		d[0][4] + d[2][4] + d[1][5],
		d[0][2] + d[1][4] + d[3][5],
		d[0][4] + d[1][3] + d[4][5] };

	vector<double>::iterator min = min_element( options.begin(), options.end() );
	int det = distance( options.begin(), min );

	vector<vertex>::iterator it1 = next( path.begin(), v1+1 ),
				 it2 = next( it1, v2-v1 ),
				 it3 = next( it2, v3-v2 );

	switch( det ){
		case 1:
			reverse( it1, it2 );
			reverse( it2, it3 );
			reverse( it1, it3 );
			break;
		case 2: 
			reverse( it2, it3 );
			reverse( it1, it3 );
			break;
		case 3: 
			reverse( it2, it3 );
			reverse( it1, it2 );
			break;
		case 4:
			reverse( it1, it2 );
			reverse( it1, it3 );
			break;
	}

}

void Path::local_search_3(){
	int n = path.size();
	for(int i=0; i<n-5; i++)
		for(int j=i+2; j<n-3; j++)
			for(int k=j+2; k<n-1; k++)
				this->try_to_improve_3(i,j,k);
}

void Path::append( vertex &v ){
	path.push_back(v);
}

void Path::show(){
	cout<<"\n\n";
	for(auto v: path)
		cout<<v.x<<" "<<v.y<<"\n";
	cout<<"\n\n";
}
