/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"
#include <iostream>
using namespace std;
/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */
   setUnvisited(graph);
   Vertex start = graph.getStartingVertex();
   queue<Vertex> q;
   q.push(start);
   graph.setVertexLabel(start, "VISITED");
   
   int min = 99999999;
   Vertex min_f;
   Vertex min_s;

   while(!q.empty()){

   		Vertex curr = q.front();
   		vector<Vertex> adjacent = graph.getAdjacent(curr);
   		for(unsigned long i=0; i< adjacent.size(); i++){
   			if(graph.getVertexLabel(adjacent[i]).compare("UNEXPLORED") ==0){
   				graph.setEdgeLabel(curr, adjacent[i], "DISCOVERY");
   				graph.setVertexLabel(adjacent[i], "VISITED");
   				q.push(adjacent[i]);
   			}
   			else if(graph.getEdgeLabel(curr, adjacent[i]).compare("UNEXPLORED") == 0){
   				graph.setEdgeLabel(curr, adjacent[i], "CROSS");
   			}
   			if(graph.getEdgeWeight(curr, adjacent[i]) < min){
   				min = graph.getEdgeWeight(curr, adjacent[i]);
   				min_f = curr;
   				min_s = adjacent[i];
   			}
   		}
   		q.pop();
   }
   graph.setEdgeLabel(min_f, min_s, "MIN");
   return min;
    //return -1;
}

void GraphTools::setUnvisited(Graph& graph)
{
	vector<Edge> edges = graph.getEdges();
   	vector<Vertex> vertex = graph.getVertices();
   	for(unsigned long i=0; i< edges.size(); i++){
   		Vertex first = edges[i].source;
   		Vertex second = edges[i].dest;
   		if(graph.getVertexLabel(first).compare("UNEXPLORED") != 0){
   			graph.setVertexLabel(first, "UNEXPLORED");
   		}
   		if(graph.getVertexLabel(second).compare("UNEXPLORED") != 0){
   			graph.setVertexLabel(second, "UNEXPLORED");
   		}

   		if(graph.getEdgeLabel(first, second).compare("UNEXPLORED") != 0){
   			graph.setEdgeLabel(first, second, "UNEXPLORED");
   		}

   	}
   	// Vertex start = graph.getStartingVertex();
   	// graph.setVertexLabel(start, "UNEXPLORED");
   	// queue<Vertex> q;
   	// q.push(start);

   	// while(!q.empty()){
   	// 	Vertex curr = q.front();
   	// 	vector<Vertex> adjacent = graph.getAdjacent(curr);
   	// 	for(int i=0; i< adjacent.size(); i++){
   	// 		graph.getEdgeLabel(curr, adjacent[i])
   	// 	}

   	// 	q.pop();
   	// }

}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    /* Your code here! */
   setUnvisited(graph);
   queue<Vertex> q;
   q.push(start);
   graph.setVertexLabel(start, "VISITED");
   unordered_map<Vertex, Vertex> parent;

   while(!q.empty()){
      Vertex curr = q.front();
      vector<Vertex> adjacent = graph.getAdjacent(curr);
      for(unsigned long i=0; i< adjacent.size(); i++){
         if(graph.getVertexLabel(adjacent[i]).compare("UNEXPLORED") ==0){
            parent[adjacent[i]] = curr;
            graph.setEdgeLabel(curr, adjacent[i], "DISCOVERY");
            graph.setVertexLabel(adjacent[i], "VISITED");
            q.push(adjacent[i]);
         }
         else if(graph.getEdgeLabel(curr, adjacent[i]).compare("UNEXPLORED") == 0){
            graph.setEdgeLabel(curr, adjacent[i], "CROSS");
         }
      }
      q.pop();
   }
   int count = 0;
   Vertex trace = end;
   while(trace != start){
      graph.setEdgeLabel(trace, parent[trace], "MINPATH");
      trace = parent[trace];
      count ++;
   }
   return count;
   // return -1;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    /* Your code here! */
   vector<Edge> edges = graph.getEdges();
   sort(edges.begin(), edges.end(), myCompare);
   DisjointSets Vertices;
   vector<Vertex> vertex = graph.getVertices();
   Vertices.addelements(vertex.size());
   int count = 0;

   for(auto& it : edges){
      Vertex first = it.source;
      Vertex second = it.dest;
      if(count == vertex.size() -1)
         break;
      if(Vertices.find(first) != Vertices.find(second)){
         Vertices.setunion(first, second);
         graph.setEdgeLabel(first, second, "MST");
         count++;
      }
   }
}

bool GraphTools::myCompare(Edge first, Edge second)
{
   return first < second;
}