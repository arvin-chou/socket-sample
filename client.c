/*!
 * \file client.c
 *
 * \date 06/24/2015 10:20:03 PM
 *
 *    Description:  
 *
 *        Version:  1.0
 *       Revision:  none
 *       Compiler:  gcc
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <arpa/inet.h> 


#define SERVER "127.0.0.1"
#define PORT 1234
 
void load_menu(void);
void socketquery(char opt);
 
int main(int argc, char** argv)
{
    load_menu();
    return 0;
}
 
/*
 * http://cboard.cprogramming.com/c-programming/64154-how-make-menu-c-dos.html
 */
void load_menu(void)
{
    int choice;
 
    do
    {
        printf("What's your requirement? 1.DNS 2. QUERY 3. QUIT: ");
        scanf("%d",&choice);
 
        switch(choice)
        {
            case 1: 
                printf("Input URL address: ");
                socketquery(choice);
                break;
            case 2: 
                printf("Input student ID: ");
                socketquery(choice);
                break;
            case 3: printf("Quitting program!\n");
                exit(0);
                break;
            default: printf("Invalid choice!\n");
                break;
        }
 
    } while (choice != 3);
 
}
 
/*
http://www.thegeekstuff.com/2011/12/c-socket-programming/
*/
void socketquery(char opt)
{
    //FIXME: hard code
    char string[256];
     
    scanf("%s", string);
 
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    memset(recvBuff, 0x00,sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return ;
    } 

    memset(&serv_addr, 0x00, sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT); 

    if(inet_pton(AF_INET, SERVER, &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return ;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return ;
    }

    /* Receive message from the server and print to screen */

    // send options
    if( send(sockfd,&opt,sizeof(opt),0) < 0)
    {
        printf("\n Error : Send failed");
        return;
    }

    if (recv(sockfd, recvBuff, sizeof(recvBuff), 0) <0)
    {
        printf("\n Error : recv failed");
        return;
    }

    // send dns
    if( send(sockfd,string,sizeof(string),0) < 0)
    {
        printf("\n Error : Send failed");
        return;
    }

    if (recv(sockfd, recvBuff, sizeof(recvBuff), 0) <0)
    {
        printf("\n Error : recv failed");
        return;
    }

    // receive ip
    if( send(sockfd,string,sizeof(string),0) < 0)
    {
        printf("\n Error : Send failed");
        return;
    }

    if (recv(sockfd, recvBuff, sizeof(recvBuff), 0) <0)
    {
        printf("\n Error : recv failed");
        return;
    }
    printf("receive from server: %s\n", recvBuff);

    /* Close connection */
    close(sockfd);
    return;
}       
