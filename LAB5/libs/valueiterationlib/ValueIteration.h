//==============================================================================
// Name        : ValueIteration.h
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 11/09/2019
// Description : The Value Iteration algorithm (detailed in chapter 3
//				 [Sutton and Barto, 1998] and chapter 13 [Mitchell, 1997])
//				 - written in C++, Ansi-style
//==============================================================================

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <memory>
#include <limits>
#include <vector>
#include <cmath>

#ifndef LIBS_VALUEITERATION_H
#define LIBS_VALUEITERATION_H

using namespace std;

namespace DPLKYL002 {

class Policy {

public:

	// public members
	vector<int> vectStates;

	int getState(int s) {

		return vectStates[s - 1];

	}

};

class Reward {

public:

	// public members
	float r;

	int s1, s2;

	Reward(int s1, int s2, float r) :

			s1(s1), s2(s2), r(r) {

	}

};

class ValueFunction {

public:

	// public members
	vector<float> vectValues;

	ValueFunction(int total, int startingValue) {

			for (int k = 0; k < total; ++k) {

				vectValues.push_back(startingValue);

			}

	}

	ValueFunction(ValueFunction& valueFunction) {

		vectValues = valueFunction.vectValues;

	}

};

class RewardFunction {

public:

	// public members
	vector<Reward> vectRewards;

	RewardFunction(vector<Reward> vectRewards) :
			vectRewards(vectRewards) {

	}

	vector<Reward> getReward(int s) {

		vector<Reward> vectReward;

		for (auto p = vectRewards.begin(); p != vectRewards.end(); ++p) {

			if (p->s1 == s){

				vectReward.push_back(*p);
			}

		}

		return vectReward;

	}

};

class ValueIteration {

private:

	// private members
	ofstream outputFile;

public:

	// public members
	void valueIteration(ValueFunction valueFunct, RewardFunction rewardFunct,
			int stateInitial, int stateTerminal, float discountFact);

};

}

#endif
