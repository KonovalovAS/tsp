using namespace std;
#include <iostream>
#include <vector>

struct vertex{
	int id;
	int x,y;

	void show();
};

double distance( vertex v1, vertex v2 );

class Path{
private:
	vector<vertex> path;	
public:
	Path( vector<vertex> &path_init );

	int size();
	vertex operator[](int i);
	double cost();

	void try_to_improve_3(int v1, int v2, int v3);
	void try_to_improve_2(int v1, int v2);

	void local_search_2();

	void append( vertex &v );
	void show();
};
