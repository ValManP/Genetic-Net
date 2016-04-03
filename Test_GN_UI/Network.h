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