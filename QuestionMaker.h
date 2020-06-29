#pragma once
#include "DataList.h"
using namespace Platform;
ref class QuestionMaker
{
private:
	DataList^ DL;
internal:
	//QuestionMaker() {};
	QuestionMaker();
public:
	int NumMaker(int input);
	//戻り値の型　名前（入力型）
	String^ QueMaker(int input);
	String^ AnsMaker(int input);
};
