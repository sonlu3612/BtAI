#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct Edge
{
    char v;
    int cost;
};

struct Node
{
    char id;
    int g;
    int h;

    int f() const
    {
        return g + h;
    }
};

extern int n;

extern vector<Edge> adj[100];

extern map<char,int> m;

bool cmp(Node a, Node b);

string printL(vector<Node> L);

void inputFile(char &start , char &end);

void A_Star(char start , char end);

void AStar_Run(const string& filename);

#endif