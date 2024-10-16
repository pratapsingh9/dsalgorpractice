#include <bits/stdc++.h>
using namespace std;

int minCost(int i ,vector<int> &cost) {
	if(i>cost.size()) {
		return 0;
	}
	int oneStep = minCost(i+1,cost);
	int secondSetp = minCost(i+2,cost);

	return cost[i] + std::min(oneStep,secondSetp);
}

int main() {

}