#ifndef SUPERMEMO
#define SUPERMEMO

namespace SuperMemoStrategy
{
	class SuperMemo
	{
	public:
		virtual int CountInterval(int numberOfRepetition, int previousInterval, double eFactor) = 0;
		virtual double CountEFactor(int qualityResponse, double previousEFactor) = 0;
	};
}
#endif