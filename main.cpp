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
	
	// cout<<"\nInitial length: "<<Path.cost();

	// cout<<"\nImproved:\n";
	(n>6) ? Path.local_search_3() : Path.local_search_2();
	cout<<Path.cost()<<" 0\n";
	Path.show_order();
	cout<<endl;

	return 0;
}
