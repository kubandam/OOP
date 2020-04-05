#pragma once
#include <string>
using namespace std;

class Client
{
private:
	static int objectCount;
	int code;
	string name;
public:
	static int GetObjectCount();

	Client(int c, string n);
	~Client();
	int GetCode();
	string GetName();
};
