#include "head.h"

using namespace std;

int main(){
	int n;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	vector<vertex> data;
	cout<<"Enter "<<n<<" couples of coordinates:\n";
	for(int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		data.push_back({i,x,y});
	}
	
	Path Path( data );
	Path.append( data[0] );
	
	cout<<"\nLength: "<<Path.cost();
	cout<<"\nThe path itself:";
	Path.show();

	cout<<"Improved:";
	(n>6) ? Path.local_search_3() : Path.local_search_2();
	Path.show();
	cout<<"New length is "<<Path.cost()<<"\n";

	return 0;
}
