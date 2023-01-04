#include <bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("sample.txt");
	for (int i=0; i<2; i++)
	{
		string name, salary;
		cout << "Name: "; cin >> name;
		cout << "Salary: "; cin >>salary;
		fout << "Name: " << name << endl;
		fout << "Salary: " << salary << endl;
	}
	fout.close();
	

	ifstream fin;
	fin.open("sample.txt");
	string line;
	while (getline(fin,line))
	{
		cout << line << endl;

	}
	fin.close();
}
