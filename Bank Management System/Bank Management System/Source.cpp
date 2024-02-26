#include<iostream>
#include<string>
using namespace std;
struct Person
{
	long long n_id, money_amount;
	int pass;
	string name;
};
int main()
{
	Person p[10000];
	char select;
	long long n_id, money_amount;
	int pass;
	string name;
	cout << "---------------------- Bank Management System ---------------------" << endl;
	do
	{
		cout << "Press" << endl;
		cout << "1-To open an account" << endl;
		cout << "2-To do bank transactions with your account" << endl;
		cout << "3-To edit or delete an account" << endl;
		cout << "4-To exit" << endl;
		cin >> select;
		if (select == '1')
		{
			char choice;
			cout << "Press" << endl;
			cout << "1-To continue" << endl;
			cout << "2-To back to main menu" << endl;
			cin >> choice;
			if (choice == '1')
			{
				cout << "Enter your name" << endl;
				cin >> name;
				cout << "Enter your national ID" << endl;
				cin >> n_id;
				cout << "Enter an amount of money" << endl;
				cin >> money_amount;
				cout << "Create a password for your account" << endl;
				cin >> pass;
				if (p[pass].pass == pass)
					cout << "This password has an account" << endl;
				else
				{
					p[pass].name = name;
					p[pass].n_id = n_id;
					p[pass].money_amount = money_amount;
					p[pass].pass = pass;
				}
			}
			else if (choice == '2')
			{
				continue;
			}
		}
		else if (select == '2')
		{
			char choice;
			cout << "Press" << endl;
			cout << "1-To deposit" << endl;
			cout << "2-To withdraw" << endl;
			cout << "3-To show account details" << endl;
			cout << "4-To back to main menu" << endl;
			cin >> choice;
			if (choice == '1')
			{
				cout << "Enter your password" << endl;
				cin >> pass;
				if (pass == p[pass].pass)
				{
					cout << "Enter amount of money you want to deposit" << endl;
					cin >> money_amount;
					if (money_amount <= p[pass].money_amount)
					{
						p[pass].money_amount -= money_amount;
						cout << "Take your money,your money_amount is " << money_amount << endl;
					}
					else
					{
						cout << "Your money_amount is not enough,please check your money_amount from account details" << endl;
						continue;
					}
				}
				else
				{
					cout << "There is no account with this password" << endl;
					continue;
				}
			}
			else if (choice == '2')
			{
				cout << "Enter your password" << endl;
				cin >> pass;
				if (pass == p[pass].pass)
				{
					cout << "Enter amount of money you want to withdraw" << endl;
					cin >> money_amount;
					
						p[pass].money_amount += money_amount;
						cout << "withdraw is done" << endl;
					
				}
				else
				{
					cout << "There is no account with this password" << endl;
					continue;
				}
			}
			else if (choice == '3')
			{
				cout << "Enter your password" << endl;
				cin >> pass;
				if (pass == p[pass].pass)
				{
					cout << "Account details" << endl;
					cout << "Your name is " << p[pass].name << endl;
					cout << "Your national ID is " << p[pass].n_id << endl;
					cout << "Your bank balance is" << p[pass].money_amount << endl;
				}
				else
				{
					cout << "There is no account with this password" << endl;
					continue;
				}
			}
		}
		else if (select == '3')
		{
			char choice;
			cout << "Press" << endl;
			cout << "1-To enter with password" << endl;
			cout << "2-To enter with name and national ID" << endl;
			cout << "3-To back to main menu" << endl;
			cin >> choice;
			if (choice == '1')
			{
				cout << "Enter your password to edit or delete the account" << endl;
				cin >> pass;
				int pass1 = pass;
				if (pass == p[pass].pass)
				{
					char dec;
					cout << "Press" << endl;
					cout << "1-To edit your account" << endl;
					cout << "2-To delete your account" << endl;
					cout << "3-To back to main menu" << endl;
					cin >> dec;
					if (dec == '1')
					{
						cout << "Enter a new name" << endl;
						cin >> name;
						cout << "Enter a new national ID" << endl;
						cin >> n_id;
						cout << "Enter a new amount of money" << endl;
						cin >> money_amount;
						cout << "Enter a new password" << endl;
						cin >> pass;
						if (pass != pass1 && pass == p[pass].pass)
						{
							cout << "This password has an account" << endl;
						}
						else
						{
							p[pass].name = name;
							p[pass].n_id = n_id;
							p[pass].money_amount = money_amount;
							p[pass].pass = pass;
							cout << "The account info changed" << endl;
						}
					}
					else if (dec == '2')
					{
						p[pass].name = -1;
						p[pass].n_id = -1;
						p[pass].money_amount = -1;
						p[pass].pass = -1;
						cout << "Your account has been deleted" << endl;
					}
				}
				else
				{
					cout << "There is no account with this password" << endl;
					continue;
				}
			}
			else if (choice == '2')
			{
				cout << "Enter your name and national ID to edit or delete your account" << endl;
				cin >> name>>n_id;
				bool found = 0;
				for (int i = 0; i < 10000; i++)
				{
					if (name == p[i].name && n_id == p[i].n_id)
					{
						found = 1;
						break;
					}
				}
				if (found)
				{
					char dec;
					cout << "Press" << endl;
					cout << "1-To edit your account" << endl;
					cout << "2-To delete your account" << endl;
					cout << "3-To back to main menu" << endl;
					cin >> dec;
					if (dec == '1')
					{
						cout << "Enter a new name" << endl;
						cin >> name;
						cout << "Enter a new national ID" << endl;
						cin >> n_id;
						cout << "Enter a new amount of money" << endl;
						cin >> money_amount;
						cout << "Enter a new password" << endl;
						cin >> pass;
						if (pass == p[pass].pass)
						{
							cout << "This password has an account" << endl;
							continue;
						}
						else
						{
							p[pass].name = name;
							p[pass].n_id = n_id;
							p[pass].money_amount = money_amount;
							p[pass].pass = pass;
							cout << "The account info changed" << endl;
						}
					}
					else if (dec == '2')
					{
						p[pass].name = -1;
						p[pass].n_id = -1;
						p[pass].money_amount = -1;
						p[pass].pass = -1;
						cout << "Your account has been deleted" << endl;
					}
				}
				else
				{
					cout << "There is no account with these info" << endl;
					continue;
				}
				
			}
		}
		cout << "--------------------------------------------" << endl;
	} while (select != '4');
	

	return 0;
}
