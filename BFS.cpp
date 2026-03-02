#include "BFS.h"

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, vector<string>> doThi1;


void inputFile_BFS(string &start, string &goal, const string& filename){
    ifstream fin(filename);

    if(!fin){
        cout << "Khong mo duoc file!\n";
        exit(0);
    }

    int n;
    fin >> n;
    fin.ignore();

    // Nhập đồ thị (không trọng số, không dấu :)
    for(int i = 0; i < n; i++){
        string dong;
        getline(fin, dong);

        if(dong.empty()){
            i--;
            continue;
        }

        stringstream ss(dong);
        string u;
        ss >> u;   // đỉnh nguồn

        string v;
        while(ss >> v){
            if(v != "0")
                doThi1[u].push_back(v);
        }
    }

    fin >> start >> goal;
    fin.close();
}

void BFS_Search(string start, string goal){
    ofstream fout("output.txt");

    queue<string> Q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;

    Q.push(start);
    visited.insert(start);

    fout << left << setw(18) << "Phat trien TT"
         << setw(20) << "Trang thai ke"
         << setw(30) << "Danh sach Q" << "\n";
    fout << string(65, '-') << "\n";

    while(!Q.empty()){
        string u = Q.front();
        Q.pop();

        string keStr = "";
        string Qstr = "";

        if(u == goal){
            fout << left << setw(18) << u
                 << setw(20) << "TTKT-DUNG"
                 << setw(30) << " " << "\n";
            break;
        }

        for(auto v : doThi1[u]){
            keStr += v + ",";

            if(!visited.count(v)){
                visited.insert(v);
                parent[v] = u;
                Q.push(v);
            }
        }

        if(!keStr.empty()) keStr.pop_back();

        queue<string> temp = Q;
        while(!temp.empty()){
            Qstr += temp.front() + ",";
            temp.pop();
        }
        if(!Qstr.empty()) Qstr.pop_back();

        fout << left << setw(18) << u
             << setw(20) << keStr
             << setw(30) << Qstr << "\n";
    }

    
    vector<string> path;
    string x = goal;

    while(x != start){
        path.push_back(x);
        x = parent[x];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    fout << "\nKet qua: ";
    for(auto &p : path)
        fout << p << " ";

    fout.close();
    cout << "Da xuat ket qua ra file output.txt\n";
}

void BFS_Run(const string& filename){
    doThi1.clear();
    string start, goal;

    inputFile_BFS(start, goal, filename);
    BFS_Search(start, goal);
}