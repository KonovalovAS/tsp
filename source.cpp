#include "head.h"
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

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

	cout<<"improving\n";

	if( abs(v1-v2)<2 || max(v1,v2)>path.size()-1 ){
		cout<<"failed to improve\n";
	}
	else{
		v1 %= path.size();
		v2 %= path.size();

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
