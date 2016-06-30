#include <iostream>
using namespace std;

//existing interface ( source )
//Abstract Adaptee interface
class INokiaSocket
{
	void nokiaRoundSocket () = 0;
};
//concreat Adaptee interface
class NokiaSocket : INokiaSocket
{
	void nokiaRoundSocket()
	{
		cout<< "I am Nokia Round socket"
	}
};

//Target interface
//Abstract 
class ISamsungSocket
{
	void samsungFlatSocket()=0;
};

//concreat target class
class SamsungSocket : ISamsungSocket
{
	void samsungFlatSocket()
	{
		cout << "I am Samsung Flat socket"
	}
};

//Adeptor class
class SocketAdeptor : ISamsungSocket
{
	INokiaSocket *nokiaSocket;
};