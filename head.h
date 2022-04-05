using namespace std;

struct vertex{
	int id;
	int x,y;
};

double distance( vertex v1, vertex v2 );

class Path{
private:
	vector<vertex> path;	
public:
	int size();
	vertex operator[](int i);
	double cost();
}
