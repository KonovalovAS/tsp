using namespace std;

struct vertex{
	int id;
	int x,y;
};

class Path{
private:
	int length;
	vector<vertex> path;	
public:
	int length();
	vertex operator[](int i);

}
