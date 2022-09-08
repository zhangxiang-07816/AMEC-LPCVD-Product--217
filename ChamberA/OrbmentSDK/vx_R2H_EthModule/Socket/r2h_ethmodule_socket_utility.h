/*
 * r2h_ethmodule_socket_utility.h
 *
 *  Created on: Jul 2, 2022
 *      Author: HaihangRen
 */

#ifndef R2H_ETHMODULE_SOCKET_UTILITY_H_
#define R2H_ETHMODULE_SOCKET_UTILITY_H_

#include "../r2h_ethmodule_data_type.h"
#include "../r2h_ethmodule_error_code.h"
#include <exception>

namespace NEO_Socket
{

R2H_SOCKET create_socket();

void close_socket(R2H_SOCKET devHandle);

void socket_bind_listen(R2H_SOCKET devHandle, R2H_CONST_STRING ip, R2H_TCP_PORT port, R2H_INT32 backlog);

void socket_connect(R2H_SOCKET devHandle, R2H_CONST_STRING ip, R2H_TCP_PORT port);

void socket_accept(R2H_SOCKET devHandle, R2H_STRING ip, R2H_TCP_PORT* port, R2H_SOCKET* newdevHandle);

void socket_recv(R2H_SOCKET devHandle, R2H_BYTE* buffer, R2H_INT32 size, R2H_INT32 *timeout);

void socket_send(R2H_SOCKET devHandle, const R2H_BYTE* buffer, R2H_INT32 size, R2H_INT32 *timeout);

void socket_clr(R2H_SOCKET devHandle, R2H_INT32 timeout);


}



#endif /* R2H_ETHMODULE_SOCKET_UTILITY_H_ */
