//
// MainPage.xaml.cpp
// MainPage クラスの実装。
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "QuestionMaker.h"
#include "DataList.h"

using namespace MoshaTypingApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// 空白ページの項目テンプレートについては、https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x411 を参照してください

MainPage::MainPage()
{
	InitializeComponent();
	QM = ref new QuestionMaker();
}

void MoshaTypingApp::MainPage::button1_1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	DisplayChangeDeleteA();
	DisplayChangeIndicationB();
	Configuration = 9000000 + AA * 100000 + Aa * 10000 + Ha * 1000 + Hga * 100 + Hkya * 10 + Hla;
	int QuestionListNum;
	String^ QuestionText = L"";
	String^ AnswerText = L"";

	int QuestionNum = 10000000;

	for (int i = 0; i < 30; i++) {
		//この下の一文に問題あり：QuestionListNumに正常に値が格納されていない。
		//QM->QueMaker(1);にした場合正常に動作
		QuestionListNum = QM->NumMaker(Configuration);
		QuestionText += QM->QueMaker(QuestionListNum);
		AnswerText += QM->AnsMaker(QuestionListNum);
	}
	textblock2_1->Text = AnswerText;
	textblock2_2->Text = QuestionText;
	KaitouList[MondaiBangouListNum][1] = AnswerText;
	KaitouList[MondaiBangouListNum][0] = QuestionText;

	char16 w[12];
	_itow_s(MondaiBangou, w, 10);
	Platform::String^ settext = ref new Platform::String(w);
	textblock2_3->Text = settext + L"問目";
	int MondaiBangouSub = MondaiBangou + 1;

	char16 wsub[12];
	_itow_s(MondaiBangouSub, wsub, 10);
	Platform::String^ settextsub = ref new Platform::String(wsub);
	button2_2->Content = settextsub + L"問目へ";

	textblock2_8->Text = L"入力中です。";
	textblock2_9->Text = L"回答待ちです。";
	textblock2_10->Text = L"回答待ちです。";
	textblock2_11->Text = L"回答待ちです。";

}

void MoshaTypingApp::MainPage::button2_1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	textblock2_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_13->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void MoshaTypingApp::MainPage::button2_2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	Platform::String^ input = textbox2_1->Text;

	if (input == L"") 
	{
		KaitouList[MondaiBangouListNum][2] = L"無回答でした。";

	}
	else
	{
		KaitouList[MondaiBangouListNum][2] = input;
	}
	textblock3_1->Text = KaitouList[MondaiBangouListNum][2];

	if (input == KaitouList[MondaiBangouListNum][0]) 
	{
		KaitouList[MondaiBangouListNum][3] = L"模写できてます。";
	}
	else
	{ 
		KaitouList[MondaiBangouListNum][3] = L"模写できていません。";
	}


	textbox2_1->Text= L"";

	if (MondaiBangou == 4) 
	{ 
		MondaiBangou = 1; 
		MondaiBangouListNum = MondaiBangou - 1;
		DisplayChangeDeleteB();
		DisplayChangeIndicationC();
		textblock3_25->Text = KaitouList[0][0];
		textblock3_26->Text = KaitouList[0][1];
		textblock3_27->Text = KaitouList[0][2];
		textblock3_32->Text = KaitouList[0][3];
		textblock3_17->Text = KaitouList[1][0];
		textblock3_18->Text = KaitouList[1][1];
		textblock3_19->Text = KaitouList[1][2];
		textblock3_24->Text = KaitouList[1][3];
		textblock3_9->Text = KaitouList[2][0];
		textblock3_10->Text = KaitouList[2][1];
		textblock3_11->Text = KaitouList[2][2];
		textblock3_16->Text = KaitouList[2][3];
		textblock3_1->Text = KaitouList[3][0];
		textblock3_2->Text = KaitouList[3][1];
		textblock3_3->Text = KaitouList[3][2];
		textblock3_8->Text = KaitouList[3][3];
		if (KaitouList[0][0] == KaitouList[0][2] && KaitouList[1][0] == KaitouList[1][2] && KaitouList[2][0] == KaitouList[2][2] && KaitouList[3][0] == KaitouList[3][2])
		{
			textblock3_33->Text = L"全ての問題を模写できてます。";
		}
		else 
		{
			textblock3_33->Text = L"きちんと模写できていない問題があります。";
		}
	}
	else 
	{ 
		textblock2_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
		textblock2_13->Visibility = Windows::UI::Xaml::Visibility::Collapsed;

		MondaiBangou += 1; 
		MondaiBangouListNum += 1;
		Configuration = 9000000 + AA * 100000 + Aa * 10000 + Ha * 1000 + Hga * 100 + Hkya * 10 + Hla;
		int QuestionListNum;
		String^ QuestionText = L"";
		String^ AnswerText = L"";

		int QuestionNum = 10000000;

		for (int i = 0; i < 30; i++) {
			//この下の一文に問題あり：QuestionListNumに正常に値が格納されていない。
			//QM->QueMaker(1);にした場合正常に動作
			QuestionListNum = QM->NumMaker(Configuration);
			QuestionText += QM->QueMaker(QuestionListNum);
			AnswerText += QM->AnsMaker(QuestionListNum);
		}
		textblock2_1->Text = AnswerText;
		textblock2_2->Text = QuestionText;
		KaitouList[MondaiBangouListNum][1] = AnswerText;
		KaitouList[MondaiBangouListNum][0] = QuestionText;

		char16 w[12];
		_itow_s(MondaiBangou, w, 10);
		Platform::String^ settext = ref new Platform::String(w);
		textblock2_3->Text = settext + L"問目";
		if (MondaiBangou == 4) 
		{ 
			button2_2->Content = L"答え合わせ"; 
		}
		else
		{
			int MondaiBangouSub = MondaiBangou + 1;
			char16 wsub[12];
			_itow_s(MondaiBangouSub, wsub, 10);
			Platform::String^ settextsub = ref new Platform::String(wsub);
			button2_2->Content = settextsub + L"問目へ";
		}

		int MondaiBangouListNumSub = MondaiBangouListNum - 1;
		switch (MondaiBangou)
		{
		case 2:
			textblock2_8->Text = KaitouList[MondaiBangouListNumSub][3];
			textblock2_9->Text = L"入力中です。";
			break;
		case 3:
			textblock2_9->Text = KaitouList[MondaiBangouListNumSub][3];
			textblock2_10->Text = L"入力中です。";
			break;
		case 4:
			textblock2_10->Text = KaitouList[MondaiBangouListNumSub][3];
			textblock2_11->Text = L"入力中です。";
			break;
		default:
			break;
		}
	}

}

void MoshaTypingApp::MainPage::button3_1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	DisplayChangeDeleteC();
	DisplayChangeIndicationB();
	Configuration = 9000000 + AA * 100000 + Aa * 10000 + Ha * 1000 + Hga * 100 + Hkya * 10 + Hla;
	int QuestionListNum;
	String^ QuestionText = L"";
	String^ AnswerText = L"";

	int QuestionNum = 10000000;

	for (int i = 0; i < 30; i++) {
		//この下の一文に問題あり：QuestionListNumに正常に値が格納されていない。
		//QM->QueMaker(1);にした場合正常に動作
		QuestionListNum = QM->NumMaker(Configuration);
		QuestionText += QM->QueMaker(QuestionListNum);
		AnswerText += QM->AnsMaker(QuestionListNum);
	}
	textblock2_1->Text = AnswerText;
	textblock2_2->Text = QuestionText;
	KaitouList[MondaiBangouListNum][1] = AnswerText;
	KaitouList[MondaiBangouListNum][0] = QuestionText;

	char16 w[12];
	_itow_s(MondaiBangou, w, 10);
	Platform::String^ settext = ref new Platform::String(w);
	textblock2_3->Text = settext + L"問目";
	int MondaiBangouSub = MondaiBangou + 1;

	char16 wsub[12];
	_itow_s(MondaiBangouSub, wsub, 10);
	Platform::String^ settextsub = ref new Platform::String(wsub);
	button2_2->Content = settextsub + L"問目へ";

	textblock2_8->Text = L"入力中です。";
	textblock2_9->Text = L"回答待ちです。";
	textblock2_10->Text = L"回答待ちです。";
	textblock2_11->Text = L"回答待ちです。";
}

void MoshaTypingApp::MainPage::button3_2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	DisplayChangeDeleteC();
	DisplayChangeIndicationA();
}

void MoshaTypingApp::MainPage::checkbox1_1_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e) { AA = 1; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_1_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){AA = 0; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_2_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Aa = 1; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_2_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Aa = 0; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_3_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Ha = 1; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_3_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Ha = 0; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_4_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Hga = 1; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_4_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Hga = 0; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_5_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Hkya = 1; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_5_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Hkya = 0; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_6_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Hla = 1; checkboxfunction();}
void MoshaTypingApp::MainPage::checkbox1_6_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e){Hla = 0; checkboxfunction();}

void MainPage::checkboxfunction() 
{
	if (AA == 0 && Aa == 0 && Ha == 0 && Hga == 0 && Hkya == 0 && Hla == 0) {
		checkbox1_1->IsChecked = true;
	}
}


void MainPage::DisplayChangeIndicationA()
{
	textblock1_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	button1_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	checkbox1_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	checkbox1_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
	checkbox1_3->Visibility = Windows::UI::Xaml::Visibility::Visible;
	checkbox1_4->Visibility = Windows::UI::Xaml::Visibility::Visible;
	checkbox1_5->Visibility = Windows::UI::Xaml::Visibility::Visible;
	checkbox1_6->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock1_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock1_3->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ractangle1_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void MainPage::DisplayChangeDeleteA()
{
	textblock1_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	button1_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	checkbox1_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	checkbox1_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	checkbox1_3->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	checkbox1_4->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	checkbox1_5->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	checkbox1_6->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock1_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock1_3->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ractangle1_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}

void MainPage::DisplayChangeIndicationB()
{
	//textblock2_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_3->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_4->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_5->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_6->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_7->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_8->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_9->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_10->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_11->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_12->Visibility = Windows::UI::Xaml::Visibility::Visible;
	//textblock2_13->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock2_14->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textbox2_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	button2_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	button2_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void MainPage::DisplayChangeDeleteB()
{
	textblock2_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_3->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_4->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_5->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_6->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_7->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_8->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_9->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_10->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_11->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_12->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_13->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock2_14->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textbox2_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	button2_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	button2_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}

void MainPage::DisplayChangeIndicationC()
{
	textblock3_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_3->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_4->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_5->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_6->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_7->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_8->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ractangle3_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_9->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_10->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_11->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_12->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_13->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_14->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_15->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_16->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ractangle3_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_17->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_18->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_19->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_20->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_21->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_22->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_23->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_24->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ractangle3_3->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_25->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_26->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_27->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_28->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_29->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_30->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_31->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_32->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_33->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ractangle3_4->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textbox3_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	textblock3_34->Visibility = Windows::UI::Xaml::Visibility::Visible;
	button3_1->Visibility = Windows::UI::Xaml::Visibility::Visible;
	button3_2->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void MainPage::DisplayChangeDeleteC()
{
	textblock3_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_3->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_4->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_5->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_6->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_7->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_8->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ractangle3_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_9->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_10->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_11->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_12->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_13->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_14->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_15->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_16->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ractangle3_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_17->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_18->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_19->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_20->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_21->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_22->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_23->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_24->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ractangle3_3->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_25->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_26->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_27->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_28->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_29->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_30->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_31->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_32->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_33->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ractangle3_4->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textbox3_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	textblock3_34->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	button3_1->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	button3_2->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}



