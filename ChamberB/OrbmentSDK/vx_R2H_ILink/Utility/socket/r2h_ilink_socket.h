#ifndef R2H_ILINK_SOCKET_H_
#define R2H_ILINK_SOCKET_H_

namespace R2H_ILINK
{

#ifdef _WRS_VX_SMP
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

#include "../../r2h_ilink_data_type.h"
#include "../../r2h_ilink_error_code.h"


#define R2H_ILINK_INVALID_SOCKET		(ERROR)

#elif WIN32
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")
#include <winsock2.h>
#include <windows.h>

#include "../../r2h_ilink_data_type.h"
#include "../../r2h_ilink_error_code.h"

#define R2H_ILINK_INVALID_SOCKET		(INVALID_SOCKET)

#endif


R2H_INT32 r2h_create_socket(R2H_SOCKET* socketDescriptor);

R2H_INT32 r2h_close_socket(	R2H_SOCKET socketDescriptor);

R2H_INT32 r2h_socket_bindlisten(	R2H_SOCKET 				socketDescriptor,
									R2H_CONST_STRING 		serverIp,
									R2H_TCP_PORT 			serverPort,
									R2H_INT32 				backlog);

R2H_INT32 r2h_socket_connect(	R2H_SOCKET 				socketDescriptor,
								R2H_CONST_STRING 		serverIp,
								R2H_TCP_PORT 			serverPort);

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

#endif /* R2H_ILINK_SOCKET_H_ */
