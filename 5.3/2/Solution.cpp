#include <iostream>
#include <stack>

using namespace std;

struct Edge {
  int from;
  int to;
  Edge *next;

  Edge(int f, int t, Edge *n): from(f), to(t), next(n) {}
};

struct Vertex {
  int value;
  Edge *firstEdge;

  // Vertex(int val, Edge *f) : value(val), firstEdge(f) {}
};

struct Graph {
  Vertex *vertexes;
  int numVertex;

  Graph(Vertex *v, int n): vertexes(v), numVertex(n) {}
};

class Solution {
 public:
  bool isTree(Graph *graph) {
    stack<int> st;
    bool *isVisited = new bool[graph->numVertex];
    st.push(0);
    int numVertex = 0;
    int numEdge = 0;
    while (!st.empty()) {
      int vi = st.top();
      st.pop();
      if (!isVisited[vi]) {
        isVisited[vi] = true;
        ++numVertex;
        Edge *e = graph->vertexes[vi].firstEdge;
        while (e != NULL) {
          ++numEdge;
          if (!isVisited[e->to]) {
            st.push(e->to);
            // break;
          }
          e = e->next;
        }
      }
    }
    cout << numVertex << " " << numEdge << endl;
    return numVertex == graph->numVertex && numEdge == 2 * (numVertex - 1);
  }
};

int main() {
  Solution sln;
  Vertex *vertexes = new Vertex[3];
  vertexes[0].value = 1;
  vertexes[0].firstEdge = new Edge(0, 1, 
    new Edge(0, 2, NULL));
  vertexes[1].value = 2;
  vertexes[1].firstEdge = new Edge(1, 0, NULL);
  vertexes[2].value = 3;
  vertexes[2].firstEdge = new Edge(2, 0, NULL);

  Graph *g = new Graph(vertexes, 3);
  cout << sln.isTree(g) << endl;
  vertexes[1].firstEdge->next = new Edge(1, 2, NULL);
  vertexes[2].firstEdge->next = new Edge(2, 1, NULL);
  cout << sln.isTree(g) << endl;

  return 0;
}