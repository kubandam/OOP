#include "Bank.h"

Bank::Bank(int c, int a)
{
	this->clients = new Client * [c];
	this->maxClientsCount = c;
	this->clientsCount = 0;

	this->accounts = new Account * [a];
	this->maxAccountsCount = c;
	this->accountCount = 0;
}

Bank::~Bank()
{
	delete[]clients;
	delete[]accounts;
	this->clients = nullptr;
	this->accounts = nullptr;
	this->clientsCount = 0;
	this->maxClientsCount = 0;
	this->maxAccountsCount = 0;
	this->accountCount = 0;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetCode() == c)
			return this->clients[i];
	}
	return nullptr;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < this->accountCount; i++)
	{
		if (this->accounts[i]->GetNumber() == n)
			return this->accounts[i];
	}
	return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
	Client* newclient = new Client(c, n);
	this->clients[this->clientsCount] = newclient;
	this->clientsCount++;
	return newclient;
}

Account* Bank::CreateAccount(int n, Client* c)
{
	Account* newaccount = new Account(n, c);
	this->accounts[this->accountCount] = newaccount;
	this->accountCount++;
	return newaccount;
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	Account* newaccount = new Account(n, c, ir);
	this->accounts[this->accountCount] = newaccount;
	this->accountCount++;
	return newaccount;
}
PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p)
{
	if (this->accountCount != 0) {
		PartnerAccount* account = new PartnerAccount(n, c, p);
		this->accounts[this->accountCount] = account;
		this->accountCount++;
		return account;
	}
	return nullptr;
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	if (this->accountCount != 0) {
		PartnerAccount* account = new PartnerAccount(n, c, p, ir);
		this->accounts[this->accountCount] = account;
		this->accountCount++;
		return account;
	}
	return nullptr;
}

void Bank::AddInterest()
{
	for (int i = 0; i < this->accountCount; i++)
	{
		double balance = this->accounts[i]->GetBalance();
		double ir = this->accounts[i]->GetInterestRate();
		double deposit = (balance / 100) * ir;
		this->accounts[i]->Deposit(deposit);
	}
}