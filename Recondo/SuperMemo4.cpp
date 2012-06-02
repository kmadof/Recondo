#include "SuperMemo4.h"
#include <cmath>

using namespace SuperMemoStrategy;

double SuperMemo4::Fraction = 1.0;

int SuperMemo4::CountInterval(int numberOfRepetition, int previousInterval, double eFactor)
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

double SuperMemo4::CountEFactor(int qualityResponse, double previousEFactor)
{
	double newEfactor = previousEFactor + (0.1 - (5-qualityResponse) * (0.08 + (5-qualityResponse) * 0.02));
	return newEfactor < 1.3 ? 1.3 : newEfactor;
}

double SuperMemo4::CountOptimalInterval(int previousInterval, double eFactor)
{
	//double oiPrim = previousInterval + previousInterval*(1-1/eFactor)/2*(025*qualityResponse-1);
	//double oiBis  = (1-SuperMemo4::Fraction)*previousOi + SuperMemo4::Fraction*oiPrim;
	/*return oiBis;*/
	return 0.0;
}