using namespace std;
#include <iostream>
#include <vector>

struct vertex{
	int id;
	double x,y;

	void show();
};

double distance( vertex v1, vertex v2 );

class Path{
private:
	vector<vertex> path;
	void try_to_improve_3(int v1, int v2, int v32);
	void try_to_improve_2(int v1, int v2);

public:
	Path( vector<vertex> &path_init );

	int size();
	vertex operator[](int i);
	double cost();

	void local_search_2();
	void local_search_3();

	void append( vertex &v );
	void show_order();
};
