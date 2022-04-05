#include <iostream>
#include <vector>
#include "head.h"

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<point> data;
	for(int i=0; i<n; i++){
		int x,y;
		cin>>x>>y;
		data.push_back({x,y});
	}
	
	for(auto p: data){
		cout<<p.x<<" "<<p.y<<"\n";
	}
	return 0;
}
