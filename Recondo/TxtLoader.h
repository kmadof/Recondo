#ifndef TXT_LOADER
#define TXT_LOADER

#include <string>
#include "FileLoader.h"
#include "Item.h"

namespace SuperMemoStrategy
{
	class TxtLoader : FileLoader
	{
		public:
			TxtLoader() {}
			virtual ~TxtLoader() {}

			virtual Items Load(std::string file);
		private:
			std::string GetSimpleString(std::string text);
	};
}

#endif