#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include <iomanip>
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string UserName, Password;
		short Attampt = 3;
		do
		{

			if (LoginFaild)
			{
				FaildLoginCount++;;
				cout << "\nInvlaid UserName/Password";
				cout << "\nYou Have " << (3- FaildLoginCount) << " Trial(s) to login \n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "You are Locked after 3 faild trials \n\n";
				return false;
			}
			cout << "\nEnter User Name ? ";
			cin >> UserName;
			cout << "\nEnter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
			

		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t	Logain Screen");
		return _Login();
	}
};
