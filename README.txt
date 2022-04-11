Trying to solve a travelling salesman problem.
Homework project.

Class Path contains a vector of vertices in their order.
Before applying local search all vertices are being sorted by x, then by y (with preserving the initial order between equal elements).

Class method try_to_improve_2(v1,v2) takes two indexes of vertices in the path, such that |v2-v1|>=2. If the summary length of edges (v1,v1+1) and (v2,v2+1) is greater than of (v1,v2) and (v1+1,v2+1), the path is being changed accordingly (longer couple of edges gets replaces).

Another class method: try_to_improve_3(v1,v2,v3), does the similar thing, but it compares more options from replacing edges between 3 couples of adjacent vertices.

local_search_2 or local_search_3 call on of methods, described above, for all existing twos (or threes) of couples of adjacent vertices.
