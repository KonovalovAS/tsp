Trying to solve a travelling salesman problem.
Homework project.

Class Path contains a vector (in fact: a deque) of vertices in their order.
First of all, the path is being initialized. Every new point gets emplaced between existing two neighbours, in such way that its' summary distance to them is the smallest.
Then local search is applied.

Class method try_to_improve_2(v1,v2) takes two indexes of vertices in the path, such that |v2-v1|>=2. If the summary length of edges (v1,v1+1) and (v2,v2+1) is greater than of (v1,v2) and (v1+1,v2+1), the path is being changed accordingly (longer couple of edges gets replaces).

local_search_2 calls a method, described above, for all existing couples of couples of adjacent vertices.

---

The program was applied to all tests on my laptop (it takes the remote machine too much time  to complete calculations).
