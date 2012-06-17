#include "SuperMemo2.h"
#include <cmath>

using namespace SuperMemoStrategy;

int SuperMemo2::CountInterval(int numberOfRepetition, int previousInterval, double eFactor)
{
	int temp = 0;
	if(numberOfRepetition == 1)
		temp = 1;
	else if(numberOfRepetition == 2)
		temp = 6;
	else if(numberOfRepetition > 2)
		temp = static_cast<int>(previousInterval * eFactor);
	return temp;
}

double SuperMemo2::CountEFactor(int qualityResponse, double previousEFactor)
{
	double newEfactor = previousEFactor + (0.1 - (5-qualityResponse) * (0.08 + (5-qualityResponse) * 0.02));
	return newEfactor < 1.3 ? 1.3 : newEfactor;
}