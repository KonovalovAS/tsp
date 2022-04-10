#include "head.h"

using namespace std;

int main(){
	int n;
	//cout<<"Enter the number of vertices: ";
	cin>>n;
	vector<vertex> data;
	//cout<<"Enter "<<n<<" couples of coordinates:\n";
	for(int i=0; i<n; i++){
		double x,y;
		cin>>x>>y;
		data.push_back({i,x,y});
	}
	
	Path Path( data );
	Path.append( data[0] );
	
	// Commented piece of code
	// will find a truly optimal solution (naively)
	/*
	 *
	double cost0 = Path.cost();
	Path.local_search_3();
	Path.local_search_2();
	double cost = Path.cost();

	int i=1;
	while( cost < cost0 ){
		cout<<"iter "<<i<<"\n";
		i++;
		cost0 = cost;
		Path.local_search_3();
		Path.local_search_2();
		cost = Path.cost();
	}

	*/

	( n > 6 ) ? Path.local_search_3() : Path.local_search_2();
	cout<<Path.cost()<<" 0\n";
	Path.show_order();
	cout<<endl;

	return 0;
}
