#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

extern int n;
extern map<string, vector<string>> doThi1;

void inputFile_BFS(string &trangThaiDau, string &trangThaiKetThuc, const string& filename);

void BFS_Search(string trangThaiDau, string trangThaiKetThuc);

void BFS_Run(const string& filename);

#endif