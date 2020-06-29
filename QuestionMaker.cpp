#include "pch.h"
#include "QuestionMaker.h"
#include <random>
using namespace Platform;

QuestionMaker::QuestionMaker()
{
	DL = ref new DataList();
}

int QuestionMaker::NumMaker(int input)
{
	int AA;
	int Aa;
	int Ha;
	int Hga;
	int Hkya;
	int Hla;

	AA = (input / 100000) % 10;//\–œ‚ÌˆÊ
	Aa = (input / 10000) % 10;//–œ‚ÌˆÊ
	Ha = (input / 1000) % 10;//ç‚ÌˆÊ
	Hga = (input / 100) % 10;//•S‚ÌˆÊ
	Hkya = (input / 10) % 10;//\‚ÌˆÊ
	Hla = input % 10;//1‚ÌˆÊ

	int QuestionNum;
	//volatile int A = 0;

	do {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, 190);
		int rnd_num = dist(gen);

		if (0 <= rnd_num && rnd_num < 26) {
			if (AA == 1) {
				QuestionNum = rnd_num;
				break;
			}
		}

		if (26 <= rnd_num && rnd_num < 52) {
			if (Aa == 1) {
				QuestionNum = rnd_num;
				break;
			}
		}

		if (52 <= rnd_num && rnd_num < 93) {
			if (Ha == 1) {
				QuestionNum = rnd_num;
				break;
			}
		}

		if (93 <= rnd_num && rnd_num < 123) {
			if (Hga == 1) {
				QuestionNum = rnd_num;
				break;
			}
		}

		if (123 <= rnd_num && rnd_num < 182) {
			if (Hkya == 1) {
				QuestionNum = rnd_num;
				break;
			}
		}

		if (182 <= rnd_num && rnd_num <= 190) {
			if (Hla == 1) {
				QuestionNum = rnd_num;
				break;
			}
		}

	} while (true/*A = 0*/);

	int res = QuestionNum;
	return res;
}

String^ QuestionMaker::QueMaker(int input)
{
	Platform::String^ res = DL->QueList(input);
	return res;
}

String^ QuestionMaker::AnsMaker(int input)
{
	Platform::String^ res = DL->AnsList(input);
	return res;
}