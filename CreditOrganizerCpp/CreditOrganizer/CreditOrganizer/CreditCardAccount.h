#pragma once
#include "LoyaltyScheme.h"

ref class CreditCardAccount
{
public:
	void SetCreditLimit(double amount);
	bool MakePurchase(double amount);
	void MakeRepayment(double amount);
	void PrintStatement();
	long GetAccountNumber();

private:
	initonly long accountNumber;
	double currentBalance;
	double creditLimit;

public:
	CreditCardAccount(long number, double limit);

private:
	static int numberOfAccounts = 0;

public:
	static int GetNumberOfAccounts();

private:
	static double interestRate;

public:
	static CreditCardAccount();

public:
	literal System::String^ name = "Super Platinum Card";

private:
	LoyaltyScheme^ scheme;

public:
	void RedeemLoyaltyPoints();
};