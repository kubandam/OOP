#include "Account.h"

int Account::objectCount = 0;

int Account::GetObjectCount()
{
	return Account::objectCount;
}
Account::Account(int n, Client* c)
{
	this->number = n;
	this->owner = c;
	this->interestRate = 1.2;
	this->balance = 0;
	Account::objectCount += 1;
}

Account::Account(int n, Client* c, double ir)
{
	this->number = n;
	this->owner = c;
	this->interestRate = ir;
	this->balance = 0;
	Account::objectCount += 1;
}
Account::~Account()
{
	this->number = 0;
	this->owner = 0;
	this->interestRate = 0;
	this->balance = 0;
	Account::objectCount -= 1;

}
int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client* Account::GetOwner()
{
	return this->owner;
}


bool Account::CanWithdraw(double a)
{
	if (this->balance >= a) {
		return true;
	}
	return false;
}
bool Account::Withdraw(double a)
{
	if (this->CanWithdraw(a) == true) {
		this->balance = this->balance - a;
		return true;
	}
	return false;
}

void Account::Deposit(double a) {
	this->balance = this->balance + a;
}
void Account::AddInterest()
{
	double balance = this->balance;
	double ir = this->interestRate;
	double deposit = (balance / 100) * ir;
	this->Deposit(deposit);
}
