//
//  Client.cpp
//  Chat-clientServer
//
//  Created by Imad Collin on 2017-12-26.
//  Copyright © 2017 Imad Collin. All rights reserved.
//

#include "Client.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")

using namespace std;

#define DEFAULT_PORT "27015"
#define IP_Address "172.0.0.1"

//================Steps====================//
//Bind the socket to an IP address

//Listening

//While connected keep messages and echo channel open

//Notify for any message from both sides

//Close the connection

 void ClientClass::fun(){
    int client;
    struct hostent *server;
    int portNum = 3000; // NOTE that the port number is same for both client and server
    char buffer[256];
    
    struct sockaddr_in server_addr;
    
    client = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client < 0)
        cout<<"ERROR opening socket"<<endl;
    //  server = gethostbyname(argv[1]);
    server=NULL; //ToDo ... server ->
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    // AF_INET: address domain of the socket.
    //  htons() converts the port number from host byte order
    //  to a port number in network byte order.
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    
    /* ---------------- connect() ---------------- */
    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum << endl;

    //Messaging
    cin >> buffer;
    int n = write(client, buffer, strlen(buffer));
    if (n < 0)
        cout<<"ERROR writing to socket"<<endl;
    
    n = read(client, buffer, 255);
    if (n < 0)
        cout<<"ERROR reading from socket"<<endl;
    printf("%s\n", buffer);
    close(client);
}

