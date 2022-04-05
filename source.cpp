#include "head.h"
#include <cmath>

double distance( vertex v1, vertex v2 ){
	return sqrt( pow( v1.x-v2.x , 2 ) + pow( v1.y-v2.y , 2 ) );
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
