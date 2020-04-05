#include <iostream>
#include "Bank.h"
#include "Client.h"
#include "Account.h"

using namespace std;
int main()
{

    Bank* b = new Bank(100, 1000);
    Client* o = b->CreateClient(0, "Jano");
    Client* c = b->CreateClient(1, "Miro");
    Account* a = b->CreateAccount(0, o);
    PartnerAccount* pa = b->CreateAccount(1, o, c);

    cout << a->GetOwner()->GetName() << endl;
    cout << pa->GetPartner()->GetName() << endl;

    cout << b->GetClient(1)->GetName() << endl;
    cout << pa->GetOwner()->GetName() << endl;

    cout << a->GetObjectCount() << endl;
    cout << o->GetObjectCount() << endl;


}