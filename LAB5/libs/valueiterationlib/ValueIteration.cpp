//==============================================================================
// Name        : ValueIteration.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 11/09/2019
// Description : The Value Iteration algorithm (detailed in chapter 3
//				 [Sutton and Barto, 1998] and chapter 13 [Mitchell, 1997])
//				 - written in C++, Ansi-style
//==============================================================================

#include "ValueIteration.h"

void DPLKYL002::ValueIteration::valueIteration(ValueFunction valueFunct,
		RewardFunction rewardFunct, int stateInitial, int stateTerminal,
		float discountFact) {

	outputFile = ofstream("answers.txt");

	int countIteration = 1;

	while (true) {

		ValueFunction otherValueFunction(valueFunct);

		for (int k = 0; k < 6; ++k) {

			float limit = 0;

			int countState = k + 1;

			vector<Reward> vectStateTransitions = rewardFunct.getReward(
					countState);

			for (auto p = vectStateTransitions.begin();
					p != vectStateTransitions.end(); ++p) {

				float element = p->r
						+ discountFact * valueFunct.vectValues[p->s2 - 1];

				if (element > limit) {

					limit = element;

				}

			}

			otherValueFunction.vectValues[countState - 1] = limit;

		}

		outputFile << "ITERATION " << countIteration << ":" << endl << endl;

		outputFile << otherValueFunction.vectValues[0] << " "
				<< otherValueFunction.vectValues[1] << " "
				<< otherValueFunction.vectValues[2] << endl;
		outputFile << otherValueFunction.vectValues[3] << " "
				<< otherValueFunction.vectValues[4] << " "
				<< otherValueFunction.vectValues[5] << endl << endl;

		++countIteration;

		if (otherValueFunction.vectValues == valueFunct.vectValues) {

			valueFunct = ValueFunction(otherValueFunction);

			break;

		}

		valueFunct = ValueFunction(otherValueFunction);

	}

	Policy optimalPolicy;

	for (int k = 0; k < 6; ++k) {

		float limit = 0;

		int countState = k + 1;

		int stateLimit = countState;

		vector<Reward> vectStateTransitions = rewardFunct.getReward(countState);

		for (auto p = vectStateTransitions.begin();
				p != vectStateTransitions.end(); ++p) {

			float element = p->r
					+ discountFact * valueFunct.vectValues[p->s2 - 1];

			if (element > limit) {

				limit = element;

				stateLimit = p->s2;

			}

		}

		optimalPolicy.vectStates.push_back(stateLimit);

	}

	outputFile << "OPTIMAL POLICY:" << endl << endl;

	for (int k = 0; k < 6; ++k) {

		outputFile << "s" << k + 1 << " -> " << "s" << optimalPolicy.vectStates[k] << endl;

	}

	outputFile << endl;

	outputFile << "OPTIMAL ROUTE STARTING FROM INITIAL STATE " << stateInitial << ":" << endl << endl;

	int state = stateInitial;

	while (state != stateTerminal) {

		outputFile << "s" << state << " -> ";

		state = optimalPolicy.getState(state);

	}

	outputFile << "s" << stateTerminal << endl << endl;

	outputFile << "Question 1:\n5 iterations (see above)" << endl<< endl;

	outputFile << "Question 2:\ns1 -> s2 -> s5 -> s6 -> s3 (see above)" << endl<< endl;

	outputFile << "Question 3:\nYes - will need to scale up the rewards by a constant factor (for example doubling). \nThe values in V* will be changed but the optimal policy remains unchanged." << endl;

	outputFile.close();

	cout << "answers.txt written successfully" << endl;

}

