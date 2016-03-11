#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <windows.h> 
#include "lp_lib.h"

using namespace std;

enum NEType { ROOT, SWITCH, USER };

class Network
{
private:
	// Presented network as a matrix where element (i, j) is a flow from device i to device j
	// i - number of row, j - number of column
	// the diagonal element is device's capacity
	vector<vector<int>> net;
	vector<int> roots;
	vector<int> switchs;
	vector<int> users;
	int countNE;
	int countPipe;
	int maxSize;

	void net_to_lp(string fileName, int dev, bool all);

public:
	Network(int _maxSize = 100)
	{
		maxSize = _maxSize;

		net.resize(maxSize);
		for (int i = 0; i < maxSize; i++) net[i].resize(maxSize);

		countNE = -1;
		countPipe = 0;
	}

	void addPlatform(int power, NEType t);
	void addLink(int ne_a, int ne_b, int power);
	void updatePlatform(int num, int power);
	void updateLink(int ne_a, int ne_b, int power);

	int getPlatformCount(){
		return switchs.size();
	}

	int getPipeCount(){
		return countPipe;
	}

	vector<vector<int>> getNetMatrix(){
		return net;
	}
	vector<int> getRoots(){
		return roots;
	}
	vector<int> getSwitchs(){
		return switchs;
	}
	vector<int> getUsers(){
		return users;
	}

	int solveLp(int dev, bool all);
	void loadFromFile(string file);
	int findNetworkCapacity();

};

void Network::addPlatform(int power, NEType t)
{
	
		countNE++;
		if (countNE > maxSize) {
			net.resize(countNE);
			for (int i = 0; i < countNE; i++) net[i].resize(countNE, 0);
		}

		net[countNE][countNE] = power;

		switch (t) {
			case ROOT:{
							roots.push_back(countNE);
							break;
			}
			case SWITCH:{
							switchs.push_back(countNE);
							break;
			}
			case USER:{
							users.push_back(countNE);
							break;
			}
		}

}

void Network::addLink(int ne_a, int ne_b, int power)
{
		net[ne_a][ne_b] = power;
		countPipe++;
}

void Network::updatePlatform(int num, int power)
{
	if (num < countNE)
	{
		net[num][num] = power;
	}

}

void Network::updateLink(int ne_a, int ne_b, int power)
{
	if (ne_a < countNE && ne_b < countNE)
		net[ne_a][ne_b] = power;
}

void Network::net_to_lp(string fileName, int dev, bool all)
{
	ofstream fout(fileName);

	int size = countNE + 1;

	char str[10];

	fout << "max: ";
	if (all) {
		for (int iter : users){
			for (int i = 0; i < size; i++)
			if (iter != i && net[i][iter] != 0) {
				//itoa(i, str, 10);
				fout << " + x";
				_itoa_s(i, str, 10); fout << str;
				_itoa_s(iter, str, 10); fout << str;
			}
		}
	}
	else {
		for (int i = 0; i < size; i++)
		if (dev != i && net[i][dev] != 0) {
			//itoa(i, str, 10);
			fout << " + x";
			_itoa_s(i, str, 10); fout << str;
			_itoa_s(dev, str, 10); fout << str;
		}
	}
	fout << ";\n";

	for (int iter : roots){
		for (int i = 0; i < size; i++)
		if (iter != i && net[iter][i] != 0) {
			fout << " + x";
			_itoa_s(iter, str, 10); fout << str;
			_itoa_s(i, str, 10); fout << str;
		}
		fout << " <= "; 
		_itoa_s(net[iter][iter], str, 10); fout << str;
		fout << ";\n";
	}

	for (int iter : switchs){
		for (int i = 0; i < size; i++)
		if (iter != i && net[iter][i] != 0){
			fout << " + x";
			_itoa_s(iter, str, 10); fout << str;
			_itoa_s(i, str, 10); fout << str;
		}
		
		for (int i = 0; i < size; i++)
		if (iter != i && net[i][iter] != 0){
			fout << " + x";
			_itoa_s(i, str, 10); fout << str;
			_itoa_s(iter, str, 10); fout << str;
		}

		fout << " <= ";
		_itoa_s(2 * net[iter][iter], str, 10); fout << str;
		fout << ";\n";
	}


	for (int iter : switchs){
		for (int i = 0; i < size; i++)
		if (iter != i && net[iter][i] != 0){
			fout << " + x";
			_itoa_s(iter, str, 10); fout << str;
			_itoa_s(i, str, 10); fout << str;
		}

		fout << " = ";

		for (int i = 0; i < size; i++)
		if (iter != i && net[i][iter] != 0){
			fout << " + x";
			_itoa_s(i, str, 10); fout << str;
			_itoa_s(iter, str, 10); fout << str;
		}

		fout << ";\n";
	}

	fout << "int";
	for (int i = 0; i < size; i++)
	for (int j = 0; j < size; j++)
		if (i !=j && net[i][j] != 0)
		{
			fout << " x";
			_itoa_s(i, str, 10); fout << str;
			_itoa_s(j, str, 10); fout << str;
			fout << ", ";
		}
	fout << "x;";

	fout.close();

}

int Network::solveLp(int dev, bool all)
{
	lprec *lp;

	net_to_lp("net.lp", dev, all);

	lp = read_LP("net.lp", NORMAL, "test model");

	if (lp == NULL) {
		fprintf(stderr, "Unable to read model\n");
	}

	solve(lp);

	return (int)get_objective(lp);
	
}

int Network::findNetworkCapacity()
{
	
	int netCap = INT_MAX;
	int tmp;

	for (int iter : users){
		tmp = solveLp(iter, false);
		if (tmp < netCap) netCap = tmp;
	}

	return netCap;

}

void Network::loadFromFile(string file)
{
	ifstream fin(file);

	//Проверка успешности открытия файла для чтения
	if (fin.fail()) {
		cout << " Ошибка открытия файла";
		exit(1);
	}

	fin >> countNE;

	roots.clear();
	switchs.clear();
	users.clear();

	net.clear();

	net.resize(maxSize);
	for (int i = 0; i < maxSize; i++) net[i].resize(maxSize);

	for (int i = 0; i < countNE; i++)
	{
		for (int j = 0; j < countNE; j++) {
			fin >> net[i][j];
			if (i != j && net[i][j] != 0) countPipe++;
		}
	}

	char t;
	int num = 0;

	for (int i = 0; i < countNE; i++)
	{
		fin >> num;
		fin >> t;
		
		switch (t) {
			case 'r':{
						 roots.push_back(num);
						break;
			}
			case 's':{
						 switchs.push_back(num);
						break;
			}
			case 'u':{
						 users.push_back(num);
						break;
			}
		}

	}

	//Закрытие файла
	fin.close();
}