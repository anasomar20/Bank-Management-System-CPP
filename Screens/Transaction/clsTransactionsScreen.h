#pragma once
#include<iostream>
#include <iomanip>
#include"..\..\clsScreen.h"
#include"..\..\Models/clsBankClient.h"
#include "..\..\Libraries\clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "..\Client\clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
class clsTrsansactionsScreen :protected clsScreen
{
private:
	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithDraw = 2,
		eShowTotalBalance = 3, eTransfer = 4,eTransferLog = 5 ,
		eShowMainMenue = 6 
	};

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter A Number from 1 to 6 :");
		return Choise;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any Key to go to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eWithDraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		case enTransactionsMenueOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
		case enTransactionsMenueOptions::eShowMainMenue:
			break;
		
		}
	}
public:

	static void ShowTransactionsMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());

	}
};
