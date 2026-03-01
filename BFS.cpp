#include "bestfirst.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>


using namespace std;

// struct Node{
//     string name;
//     int h;

//     bool operator<(const Node& other) const{
//         return h > other.h;
//     }
// };

// unordered_map<string, vector<string>> doThi;
// unordered_map<string, int> h;


void inputFile(string &trangThaiDau, string &trangThaiKetThuc){
	ifstream fin("input2.txt");
	
	if(!fin){
		cout <<"Khong mo duoc file!\n";
		exit(0);
	}
	
	//So dinh
    int n;
    fin >> n;


    //nhap cap dinh - trong so
    for(int i = 0; i <n; i++){
        string v;
        int w;
        fin >> v >> w;
        h[v] = w;
    }
    

    //nhap do thi
    for(int i = 0; i<n; i++){
        string dong;
        getline(fin,dong);

        if(dong.empty()){
            i--;
            continue;
        }

        int vitri = dong.find(':');

        string u = dong.substr(0,vitri);
        string r = dong.substr(vitri+1);

        //bo khoang trang dau
        stringstream ss(r); //doc tung phan tu trong chuoi

        string x;
        while(ss>>x){
            if(x!="0")
                doThi[u].push_back(x);
        }
    }
	
	 //Nhap TTD, TTKT
    fin >> trangThaiDau >> trangThaiKetThuc;

	fin.close();
	
}

void Best_First_Search(string trangThaiDau, string trangThaiKetThuc){
	
	ofstream fout("output.txt");
	
	priority_queue<Node> L;
	
	L.push({trangThaiDau,h[trangThaiDau]});
	
	fout <<left<< setw(18)<< "Phat trien TT"
		<<setw(20) << "Trang thai ke" << setw(30) <<"Danh sach L" <<"\n";
		
	fout <<string(65,'-') <<"\n";
	
	unordered_set<string> dsTTDaDuyet;
	
	unordered_map<string, string> p;
	
	while(!L.empty()){
		Node u = L.top();
		L.pop();
		
		if(dsTTDaDuyet.count(u.name)) continue;
		
		dsTTDaDuyet.insert(u.name);
		
		string ttStr = u.name + to_string(u.h);
		string keStr = "";
		string Lstr = "";
		
		if(u.name == trangThaiKetThuc){
			keStr = "TTKT-DUNG";
			
			fout <<left<< setw(18)<< ttStr
		<<setw(20) << keStr << setw(30) <<" " <<"\n";
			break;
		}
		
		for(auto v:doThi[u.name]){
			keStr += v + to_string(h[v]) + ",";
			
			if(!dsTTDaDuyet.count(v)){
				p[v] = u.name;
				L.push({v,h[v]});
			}	
		}
		
		if(!keStr.empty()){
				keStr.pop_back();
		}
		
		priority_queue<Node> temp = L;
        while(!temp.empty()){
            Node t = temp.top();
            temp.pop();
            Lstr += t.name + to_string(t.h) + ",";
        }

        if(!Lstr.empty())
            Lstr.pop_back();
		
		fout <<left<< setw(18)<< ttStr
		<<setw(20) << keStr << setw(30) << Lstr <<"\n";
	}
	
	vector<string> kq;
	string x = trangThaiKetThuc;
	while(x != trangThaiDau){
		kq.push_back(x);
		x = p[x];
	}
	
	kq.push_back(trangThaiDau);
	reverse(kq.begin(),kq.end());
	
	fout << "\nKetQua: ";
	for(auto p:kq){
		fout << p <<" ";
	}
	
	fout.close();		
	
	
}

// int main(){
	
// 	string trangThaiDau, trangThaiKetThuc;
	
// 	inputFile(trangThaiDau, trangThaiKetThuc);
	
// 	Best_First_Search(trangThaiDau, trangThaiKetThuc);
  
   
// }




