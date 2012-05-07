#include "SuperMemo2.h"

using namespace SuperMemoStrategy;

int SuperMemo2::CountInterval(int numberOfRepetition, double previousInterval)
{
	int temp = 0;
	if(numberOfRepetition == 1)
		temp = 1;
	else if(numberOfRepetition == 2)
		temp = 6;
	else if(numberOfRepetition > 2)
		temp = static_cast<int>(previousInterval * 2.5);
	return temp;
}

double SuperMemo2::CountEFactor(int qualityResponse, double previousEFactor)
{
	return 0.0;
}