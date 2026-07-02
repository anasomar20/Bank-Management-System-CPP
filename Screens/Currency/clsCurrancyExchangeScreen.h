#pragma once
#include <iostream>
#include <string>
#include "..\..\Libraries\clsString.h"
#include "..\..\Libraries\clsInputValidate.h"
#include "..\..\Models/clsCurrency.h"
#include "..\..\clsScreen.h"
#include <iomanip>
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;
class clsCurrencyExchangeScreen :protected clsScreen
{
private:
	enum enCurrencyExchangeMenueOptions {
		eListCurrencys = 1 , eFindCurrency = 2 , eUpdateRate = 3 ,
		eCurrencyCalculator = 4 , eMainMenue = 5
	};

	static short _ReadCurrencyExchangeOption()
	{
		cout << "Choose What do you want to do ? [1 to 5 ]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 9? ");
		return Choise;
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause > 0");
		ShowCurrencyExchangeMenue();
	}

	static void _ShowListCurrencysScrren()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScrren()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScrren()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScrren()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static void _PerformCurrencyExchangeOptions(enCurrencyExchangeMenueOptions CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case enCurrencyExchangeMenueOptions::eListCurrencys:
			system("cls");
			_ShowListCurrencysScrren();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScrren();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScrren();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScrren();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eMainMenue:
			break;
		}
	}

public:

	static void ShowCurrencyExchangeMenue()
	{

		system("cls");
		_DrawScreenHeader("    Currancy Exhange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyExchangeOptions((enCurrencyExchangeMenueOptions)_ReadCurrencyExchangeOption());

	}

};
