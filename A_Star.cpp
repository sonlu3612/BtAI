#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
#include <fstream>
#include <iomanip>  
#include <string>

#define endl '\n'

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

bool cmp(Node a, Node b)
{
    return a.f() < b.f();
}

int n;

vector<Edge> adj[100];

map<char, int> m;


string printL(vector<Node> L)
{
    sort(L.begin(),L.end(),cmp);

    string s = "";

    for(int i = 0;i<L.size();i++)
    {
        s += L[i].id;
        s += "(" + to_string(L[i].f()) + ")";

        if(i != L.size() - 1)
            s += ", ";
    }

    return s;
}

void inputFile(char &start,char &end)
{
    ifstream fin("input.txt");

    if(!fin)
    {
        cout<<"Khong mo duoc file\n";
        exit(0);
    }

    fin >> n;

    for(int i = 0; i<n; i++)
    {
        char name;
        int h;

        fin >> name >> h;

        m[name] = h;
    }

    for(int i = 0; i<n; i++)
    {
        char u;
        int k;

        fin >> u >> k;

        for(int j = 0; j < k; j++)
        {
            Edge e;

            fin >> e.v >> e.cost;

            adj[u - 'A'].push_back(e);
        }
    }

    fin >> start >> end;

    fin.close();
}

void A_Star(char start,char end)
{
    vector<Node> L;

    map<char,int> g;

    map<char,char> parent;

    for(auto x : m)
        g[x.first] = INT_MAX;

    g[start] = 0;

    L.push_back({start, 0, m[start]});

    cout << left << setw(6) << "TT" << setw(6) << "TTK" << setw(8) << "k(u,v)" << setw(8) << "h(v)" << setw(8) << "g(v)" << setw(8) << "f(v)" << setw(30) << "Danh sach L" << endl;

    cout << string(90, '-') << endl;


    while(true)
    {
        if(L.empty())
        {
            cout << "Khong ton tai duong di\n";
            return;
        }

        sort(L.begin(), L.end(), cmp);

        Node u = L.front();

        L.erase(L.begin());

        if(u.id == end)
        {
            cout << string(90, '-') << endl;
            cout << "\nThanh cong!\n";

            cout << "Duong di : ";

            vector<char> path;

            char cur = end;

            while(true)
            {
                path.push_back(cur);

                if(cur == start) break;

                cur = parent[cur];
            }

            reverse(path.begin(), path.end());

            for(int i = 0; i < path.size(); i++)
            {
                cout << path[i];

                if(i != path.size() - 1)
                    cout << " -> ";
            }

            cout << "\nDo dai = " << u.g << endl;

            return;
        }

        for(Edge e : adj[u.id - 'A'])
        {
            char v = e.v;

            int gv = u.g + e.cost;

            int hv = m[v];

            int fv = gv + hv;

            if(gv < g[v])
            {
                g[v] = gv;

                parent[v] = u.id;

                L.push_back({v, gv, hv});
            }

            cout << left << setw(6) << u.id << setw(6) << v << setw(8) << e.cost << setw(8) << hv << setw(8) << gv << setw(8) << fv << setw(30) << printL(L) << endl;
        }
    }
    
}

int main()
{
    char start,end;

    inputFile(start,end);

    A_Star(start,end);

    return 0;
}