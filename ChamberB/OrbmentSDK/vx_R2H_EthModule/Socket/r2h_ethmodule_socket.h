/*
 * r2h_ethmodule_socket.h
 *
 *  Created on: 2019-1-30
 *      Author: CrazyHein
 */

#ifndef R2H_ETHMODULE_SOCKET_H_
#define R2H_ETHMODULE_SOCKET_H_

#include <vxWorks.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <selectLib.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <inetLib.h>
#include <sys/types.h>
#include <string.h>

#include "../r2h_ethmodule_data_type.h"
#include "../r2h_ethmodule_error_code.h"

namespace R2H_ETHMODULE_PROTOCOL_PACKAGE
{

#define R2H_ETHMODULE_INVALID_SOCKET		(ERROR)

R2H_INT32 r2h_create_socket(R2H_SOCKET* socketDescriptor);

R2H_INT32 r2h_close_socket(	R2H_SOCKET socketDescriptor);

R2H_INT32 r2h_socket_bindlisten(	R2H_SOCKET 		socketDescriptor,
									R2H_STRING 		serverIp,
									R2H_TCP_PORT 	serverPort,
									R2H_INT32 		backlog);

R2H_INT32 r2h_socket_connect(	R2H_SOCKET 		socketDescriptor,
								R2H_STRING 		serverIp,
								R2H_TCP_PORT 	serverPort);

R2H_INT32 r2h_socket_accept(	R2H_SOCKET 		socketDescriptor,
								R2H_STRING		clientIp,
								R2H_TCP_PORT*	clientPort,
								R2H_SOCKET*		newsocketDescriptor);

R2H_INT32 r2h_socket_recv(	R2H_SOCKET 		socketDescriptor,
							R2H_UINT8* 		dataBuffer,
							R2H_INT32 		dataBufferSizeInByte,
							R2H_INT32 		timeout);

R2H_INT32 r2h_socket_send(	R2H_SOCKET 		socketDescriptor,
							R2H_UINT8* 		dataBuffer,
							R2H_INT32 		dataBufferSizeInByte,
							R2H_INT32 		timeout);


}


#endif /* R2H_ETHMODULE_SOCKET_H_ */
