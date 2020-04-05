#pragma once
#include "Account.h"

class PartnerAccount : public Account
{
private:
	Client* partner;

public:
	PartnerAccount(int n, Client* c, Client* p);
	PartnerAccount(int n, Client* c, Client* p, double ir);
	Client* GetPartner();
};
