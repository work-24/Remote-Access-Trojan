#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <thread>

#pragma comment(lib, "Ws2_32.lib")

#define TYPE 7878
#define SOURCE "192.168.147.38"

class solving {
private:
	SOCKET set;
	sockaddr_in go;
	WSADATA version;
	PROCESS_INFORMATION pinfo;
	
	void stock();
	void process();
public:
	void func();
};
