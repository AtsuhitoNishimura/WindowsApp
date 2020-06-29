//
// MainPage.xaml.h
// MainPage クラスの宣言。
//

#pragma once

#include "MainPage.g.h"
#include "QuestionMaker.h"

namespace MoshaTypingApp
{
	/// <summary>
	/// それ自体で使用できる空白ページまたはフレーム内に移動できる空白ページ。
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
	private:
		void button1_1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void MainPage::DisplayChangeIndicationA();
		void MainPage::DisplayChangeDeleteA();
		void MainPage::DisplayChangeIndicationB();
		void MainPage::DisplayChangeDeleteB();
		void MainPage::DisplayChangeIndicationC();
		void MainPage::DisplayChangeDeleteC();
		void button2_1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button2_2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button3_1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void button3_2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		int AA = 1;
		int Aa = 1;
		int Ha = 1;
		int Hga = 1;
		int Hkya = 1;
		int Hla = 1;
		int Configuration;
		void checkbox1_1_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_1_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_2_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_2_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_3_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_3_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_4_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_4_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_5_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_5_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_6_Checked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void checkbox1_6_Unchecked(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		QuestionMaker^ QM;
		void MainPage::checkboxfunction();
		int MondaiBangou = 1;
		String^ KaitouList[4][4];//[問題番号][1:問題、2:答え、3:入力された文字列、4:正誤]
		int MondaiBangouListNum = MondaiBangou - 1;
	};
}
