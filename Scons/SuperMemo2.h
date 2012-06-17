#include "SuperMemo.h"

#ifndef SUPERMEMO_2
#define SUPERMEMO_2

namespace SuperMemoStrategy
{
	class SuperMemo2 : public SuperMemo
	{
		public:
			virtual int CountInterval(int numberOfRepetition, int previousInterval, double eFactor);
			virtual double CountEFactor(int qualityResponse, double previousEFactor);
	};
}
#endif