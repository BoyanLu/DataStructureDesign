#ifndef _EDGE_WEIGHTED_GRAPH_H_
#define _EDGE_WEIGHTED_GRAPH_H_

#include <vector>
#include "Edge.h"
#include "Queue.h"

using namespace std;

class EdgeWeightedGraph
{
public:
	EdgeWeightedGraph(int v) : V(v), E(0)
	{
		vector<vector<Edge>> temp(V);
		adj = temp;
	}


	void addEdge(Edge e)
	{
		int v = e.either();
		int w = e.other(v);
		adj[v].push_back(e);//���ڽӱ������
		adj[w].push_back(e);
		++E;
	}

	Queue<Edge> edges()//�������б�
	{
		Queue<Edge> queue;
		for (int v = 0; v < V; ++v)
		{
			for (Edge e : adj[v])
			{
				if (e.other(v) > v)
				{
					queue.enqueue(e);
				}
			}
		}
		return queue;
	}

	int getV()
	{
		return V;
	}

	int getE()
	{
		return E;
	}

private:
	int V;
	int E;
	vector<vector<Edge>> adj;//�ڽӱ�

};

#endif //_EDGE_WEIGHTED_GRAPH_H_
