#include "stdafx.h"
#include <set>
#include <vector>;

using namespace std;
bool ContainKey(set<int> sets, int key) {
	for (int pKey : sets) {
		if (pKey == key) {
			return true;
		}
	}
	return false;
}

// scheduled to interview with FV Technologies: Monday, January 13?12:00 – 12 : 30pm
// the aiports connected by flights in array, as [2, 0], [3, 0], [4,1] = true.
// what mininm connections need to be connect all airport

// put ture airpot pair to the set. check all pairs has overlap connect as one group. 
// the reuslt is gourp number -1. Group [2, 0], [3, 0] and group  [4,1]. //resutl 1.


void FVTechInterView() {

	// https://stackoverflow.com/questions/71359065/group-pairs-of-elements-based-on-connecting-element-in-c
		
	vector<vector<bool>> portsMix = {
		{false, false, false, false, false},
		{false, false, false, false, false},
		{true, false, false, false, false},
		{true, false, false, false, false},
		{false, true, false, false, false} };


	pair <int, int> connectedPair;
	vector <pair <int, int>> airportConnection;

	int ports = portsMix.size();
	for (int i = 0; i < ports; i++)
		for (int j = 0; j < ports; j++)
			if (portsMix[i][j] == true) {
				connectedPair = pair<int, int>(i, j);
				airportConnection.push_back(connectedPair);
			}

	int countGroup = 0;
	set<int> seen = {};

	for (int i = 0; i < airportConnection.size(); i++) {
		if (ContainKey(seen, i))
			continue;
		connectedPair = airportConnection.at(i);
		set<int> aGroup = {};
		aGroup.insert(connectedPair.first);
		aGroup.insert(connectedPair.second);
		countGroup++;
		seen.insert(i);

		for (int j = i + 1; j < airportConnection.size(); j++) {
			connectedPair = airportConnection.at(j);
			if (!ContainKey(seen, j) && (ContainKey(aGroup, connectedPair.first) || ContainKey(aGroup, connectedPair.second))) {
				seen.insert(j);
				aGroup.insert(connectedPair.first);
				aGroup.insert(connectedPair.second);
				j = i + 1;
			}
			else {
				j++;
			}
		}
	}
	if (countGroup > 0)
		countGroup--;

}


void mainOther()
{
	FVTechInterView();
}