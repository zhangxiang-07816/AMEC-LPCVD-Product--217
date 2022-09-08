/*
 * r2h_ethmodule_socket_device.h
 *
 *  Created on: 2019-1-30
 *      Author: CrazyHein
 */

#ifndef R2H_ETHMODULE_SOCKET_DEVICE_H_
#define R2H_ETHMODULE_SOCKET_DEVICE_H_

#include "../Socket/r2h_ethmodule_socket.h"
#include "r2h_ethmodule_socket_device_def.h"
#include <exception>

class R2H_EthModule_SocketDevice
{
public:
	R2H_EthModule_SocketDevice();
	virtual ~R2H_EthModule_SocketDevice();
	
	R2H_ETHMODULE_DEVICE_MODEL_ID_T			DeviceModelIdentifier();
	virtual	R2H_UINT32						GetDeviceModuleSwitch();
	virtual	R2H_INT32						SetDeviceModuleSwitch(R2H_UINT32 sw);
	R2H_UINT16								Port();
	R2H_CONST_STRING						IPv4();
	
protected:
	R2H_SOCKET 								_r2h_socket;
	R2H_CHAR								_ip[R2H_IP4_STR_SIZE];
	R2H_UINT16 								_port;
	R2H_INT32								_communication_timeout;
	R2H_INT32								_communication_interval;
	R2H_ETHMODULE_DEVICE_MODEL_ID_T			_device_model_identifier;
private:
	R2H_EthModule_SocketDevice(const R2H_EthModule_SocketDevice&);
	R2H_EthModule_SocketDevice& operator=(const R2H_EthModule_SocketDevice&);
};

inline R2H_UINT16 R2H_EthModule_SocketDevice::Port()
{
	return _port;
}

inline R2H_CONST_STRING R2H_EthModule_SocketDevice::IPv4()
{
	return _ip;
}

class R2H_EthModule_Exception : public std::exception
{
public:
	R2H_EthModule_Exception(R2H_INT32 errorCode);
	R2H_EthModule_Exception(std::exception &e);
	virtual ~R2H_EthModule_Exception();
	R2H_INT32 ReturnErrorCode();
	const std::exception& ReturnInnerSTDException();
private:
	R2H_INT32			__r2h_ethmodule_error_code;
	std::exception		__inner_std_exception;
};

class R2H_EthModule_SysDriverException : public R2H_EthModule_Exception
{
public:
	explicit R2H_EthModule_SysDriverException(R2H_INT32 code);
	virtual ~R2H_EthModule_SysDriverException();
};

class R2H_EthModule_SysResourceException : public R2H_EthModule_Exception
{
public:
	explicit R2H_EthModule_SysResourceException(R2H_INT32 code);
	virtual ~R2H_EthModule_SysResourceException();
};

#endif /* R2H_ETHMODULE_SOCKET_DEVICE_H_ */
