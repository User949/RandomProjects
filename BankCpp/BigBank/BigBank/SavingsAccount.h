#pragma once

#include "BankAccount.h"

ref class SavingsAccount : BankAccount
{
public:
	SavingsAccount(String^ holder);
	static void SetInteterestRate(double rate);
	static double GetInterestRate();
private:
	static double interestRate;
public:
	virtual bool CanDebit(double amount) override;
};