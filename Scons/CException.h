#include <string>

#ifndef CEXCEPTION
#define CEXCEPTION
namespace SuperMemoStrategy
{

	class CException
	{
		private:
			std::string _nameOfFile;
			unsigned _numberOfLine;
			std::string _description;
		public:
			CException(const std::string& nameOfFile, unsigned numberOfLine, const std::string description)
				: _nameOfFile(nameOfFile), _numberOfLine(numberOfLine), _description(description) {}

			std::string GetNameOfFile() const		{ return _nameOfFile; }
			unsigned	GetNumberOfLine() const		{ return _numberOfLine; }
			std::string GetDescription() const		{ return _description; }
	};
	
}
#endif
