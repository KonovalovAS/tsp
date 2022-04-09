#include "head.h"

using namespace std;

int main(){
	int n;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	vector<vertex> data;
	cout<<"Enter n couples of coordinates:\n";
	for(int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		data.push_back({i,x,y});
	}
	
	/*
	for(auto p: data){
		cout<<p.x<<" "<<p.y<<"\n";
	}
	*/
	
	Path Path( data );
	Path.append( data[0] );
	
	cout<<"\nLength: "<<Path.cost();
	cout<<"\nThe path itself:";
	Path.show();

	// Path.try_to_improve_2(0,2);
	Path.local_search_2();
	Path.show();

	return 0;
}
