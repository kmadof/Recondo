#include <string>
#include <iostream>
#include <fstream>
#include "TxtLoader.h"
#include "Item.h"

using namespace SuperMemoStrategy;

Items TxtLoader::Load(std::string fileName)
{
	Items items;
	ItemPtr item = ItemPtr();					//empty ptr
	std::string text, tempQuestion, tempAnswer;
	std::ifstream infile;

	infile.open(fileName, ifstream::in);
	while(!infile.eof())
	{
		std::getline(infile, text);
		tempQuestion = GetSimpleString(text);
		if(!tempQuestion.empty())
		{
			std::getline(infile, text);
			tempAnswer = GetSimpleString(text);
			if(!tempAnswer.empty())
			{
				item = ItemPtr(new Item(tempQuestion, tempAnswer));
				items.push_back(item);
			}
		}
	}
	infile.close();

	return items;
}

std::string TxtLoader::GetSimpleString(std::string text)
{
	
	if(!text.empty() && (text[0] == 'Q' || text[0] == 'A'))
		return text.substr(3, text.length() + 1);
	else
		return "";
}