#ifndef BESTFIRST_H
#define BESTFIRST_H

#include <iostream>
#include <vector>
// #include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// ===== NODE =====
struct Node_bfs
{
    string name;
    int h;

    bool operator<(const Node_bfs& other) const{
        return h > other.h;
    }
};

// ===== BIẾN TOÀN CỤC (định nghĩa trong bestfirst.cpp) =====
extern int n;
extern unordered_map<string, vector<string>> doThi;
extern unordered_map<string, int> h;



// string printL(vector<Node> L);

void inputFile(string &trangThaiDau, string &trangThaiKetThuc, const string& filename);
// void inputKeyboard(string &trangThaiDau, string &trangThaiKetThuc);

void Best_First_Search(string trangThaiDau , string trangThaiKetThuc);

void BestFirst_Run(int inputType , const string& filename);

#endif