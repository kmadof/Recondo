#include "SuperMemo.h"

#ifndef SUPERMEMO_4
#define SUPERMEMO_4

namespace SuperMemoStrategy
{
	class SuperMemo4 : public SuperMemo
	{
		public:
			virtual int CountInterval(int numberOfRepetition, int previousInterval, double eFactor);
			virtual double CountEFactor(int qualityResponse, double previousEFactor);
			static double Fraction;
		private :
			virtual double CountOptimalInterval(int previousInterval, double eFactor);
	};
}
#endif