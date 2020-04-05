#include "Client.h"

int Client::objectCount = 0;

int Client::GetObjectCount()
{
	return Client::objectCount;
}

Client::Client(int c, string n)
{
	this->code = c;
	this->name = n;
	Client::objectCount += 1;
}
Client::~Client()
{
	this->code = 0;
	this->name = nullptr;
	Client::objectCount -= 1;

}
int Client::GetCode()
{
	return this->code;
}
string Client::GetName()
{

	return this->name;
}