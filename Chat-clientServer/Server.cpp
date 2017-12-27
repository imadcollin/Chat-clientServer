//
//  Server.cpp
//  Chat-clientServer
//
//  Created by Imad Collin on 2017-12-27.
//  Copyright © 2017 Imad Collin. All rights reserved.
//

#include "Server.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;


void ServerClass::ServerFun(){
    
    int client, server,portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in server_addr;
    client = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client < 0)
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portno);
    
    socklen_t size;
    
    if ((::bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        exit(-1);
    }
    
    listen(client, 1);
    
    
    
    close(client);
    
    
}

