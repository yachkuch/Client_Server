#include <iostream>
#include <Protocol_communication.h>
#include<Serv_tcp_reader.h>

struct Default_mes
{
	double a;
	int b;
};

int main(int, char**){
    std::cout << "Hello, from CLient!\n";
    
	client<> client(3466, 1, 1);
	auto resault = client.connect_();
	std::cout << "Client resault " << resault << std::endl;
	Defaul_Heder heder;
	heder.type_message = 3;
	heder.size = sizeof(Defaul_Heder);
	Default_mes mes;
	mes.a = 4;
	mes.b = 5;
	char *a = new char[sizeof(Defaul_Heder)];
	memcpy(a,&heder,sizeof(Defaul_Heder));
	client.send_(a, sizeof(Defaul_Heder) + sizeof(Default_mes));
	std::cout << "Finish";
	system("Pause");
	return 0;
    
}
