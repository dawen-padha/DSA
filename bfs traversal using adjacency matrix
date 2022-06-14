#include < iostream >
#include<queue>
 using namespace std;
void print (int **edges, int v, int sv, bool * visited)
{
  if (v == 0)
    {
      return;
    }
  queue < int >vertices;
  vertices.push (sv);
  visited[sv] = true;
  while (vertices.size () != 0)
    {
      int temp = vertices.front ();
      cout << temp << " ";
      vertices.pop ();
      for (int i = 0; i < v; i++)
	{
	  if (i == temp)
	    {
	      continue;
	    }
	  if (edges[temp][i] == 1 && !visited[i])
	    {
	      vertices.push (i);
	      visited[i] = true;
	    }
	}
    }
}

int
main ()
{
  int v;
  int e;
  cin >> v >> e;
  int **edges = new int *[v];
  for (int i = 0; i < v; i++)
    {
      edges[i] = new int[v];
      for (int j = 0; j < v; j++)
	{
	  edges[i][j] = 0;
	}
    }
  for (int i = 0; i < e; i++)
    {
      int f, s;
      cin >> f >> s;
      edges[f][s] = 1;
      edges[s][f] = 1;
    }
// if(e==0){
// break;
// }
  bool *visited = new bool[v];
  for (int i = 0; i < v; i++)
    {
      visited[i] = false;
    }
  for (int i = 0; i < v; i++)
    {
      if (!visited[i])
	{
	  print (edges, v, i, visited);
	}
    }
}
