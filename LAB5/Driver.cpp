//==============================================================================
// Name        : Driver.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 11/09/2019
// Description : The Value Iteration algorithm (detailed in chapter 3
//				 [Sutton and Barto, 1998] and chapter 13 [Mitchell, 1997])
//				 - written in C++, Ansi-style
//==============================================================================

#include "ValueIteration.h"

// main function
int main(int argc, char * argv[]) { // argc and argv values passed into main

	DPLKYL002::ValueIteration vi;

	// initialisation

	int stateInitial, stateTerminal;

	stateInitial = 1;

	stateTerminal = 3;

	float discountFact;

	discountFact = 0.8f;

	DPLKYL002::RewardFunction rewardFunct( { DPLKYL002::Reward(1, 2, 0),

			DPLKYL002::Reward(1, 4, 0), DPLKYL002::Reward(2, 1, 0),

			DPLKYL002::Reward(2, 5, 0), DPLKYL002::Reward(2, 3, 50),

			DPLKYL002::Reward(4, 1, 0), DPLKYL002::Reward(4, 5, 0),

			DPLKYL002::Reward(5, 4, 0), DPLKYL002::Reward(5, 2, 0),

			DPLKYL002::Reward(5, 6, 0), DPLKYL002::Reward(6, 5, 0),

			DPLKYL002::Reward(6, 3, 100)});

	DPLKYL002::ValueFunction valueFunct(6, 0);

	vi.valueIteration(valueFunct, rewardFunct, stateInitial, stateTerminal,
			discountFact);

	return 0;

}
