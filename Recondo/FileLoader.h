#ifndef FILE_LOADER
#define FILE_LOADER

#include "Item.h"

namespace SuperMemoStrategy
{
	class FileLoader
	{
		public:
			virtual ~FileLoader() {}
			virtual Items Load(string file) = 0;
	};
}

#endif