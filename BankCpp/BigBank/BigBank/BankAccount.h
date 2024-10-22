#pragma once

using namespace System;

ref class BankAccount abstract
{
public:
	BankAccount(String^ holder);
	void Credit(double amount);
	bool Debit(double amount);
	double GetBalance();
private:
	String^ accountHolder;
	double balance;
public:
	virtual String^ ToString() override;
	virtual bool CanDebit(double amount) abstract;
protected:
	String^ RoutingInstructions(double amount);
};