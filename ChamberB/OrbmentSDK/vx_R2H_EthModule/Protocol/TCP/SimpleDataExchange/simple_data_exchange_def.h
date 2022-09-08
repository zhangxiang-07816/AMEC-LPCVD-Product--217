/*
 * simple_data_exchange_def.h
 *
 *  Created on: Jul 2, 2022
 *      Author: HaihangRen
 */

#ifndef SIMPLE_DATA_EXCHANGE_DEF_H_
#define SIMPLE_DATA_EXCHANGE_DEF_H_

#include "../../../r2h_ethmodule_data_type.h"

namespace R2H_ETHMODULE_PROTOCOL_PACKAGE
{
typedef struct SDE_FUNC_CODE
{
	union
	{
		R2H_BYTE 						raw_value;
		struct
		{
			R2H_BYTE					read_diagnostic 	: 1;
			R2H_BYTE					read_dev_tx_pdo 	: 1;
			R2H_BYTE					write_dev_rx_pdo 	: 1;
			R2H_BYTE					dummy_bit3			: 1;
			R2H_BYTE					cmd_flag		 	: 1;
			R2H_BYTE					ack_flag		 	: 1;
			R2H_BYTE					dummy_bit7 			: 1;
			R2H_BYTE					exception_flag 		: 1;
		};
	};
}__attribute__((packed)) SDE_FUNC_CODE_T;

typedef struct SDE_ADDR
{
	R2H_UINT16							start;
	R2H_UINT16							size;
}__attribute__((packed)) SDE_ADDR_T;

typedef struct SDE_DATAGRAM_HEADER
{
	R2H_UINT16 							transaction;
	R2H_BYTE							protocol_identifier[3];//0x53 0x44 0x45
	SDE_FUNC_CODE_T						func;
	SDE_ADDR_T							diag_addr;
	SDE_ADDR_T							dev_tx_addr;
	SDE_ADDR_T							dev_rx_addr;
	R2H_UINT16							bytes;
}__attribute__((packed)) SDE_DATAGRAM_HEADER_T;

typedef enum SDE_EXCEPTION_CODE
{
	NO_EXCEPTION						= 0x00,

	WRITE_DEV_RX_UNSUPPORTED			= 0x01,
	READ_DIAG_UNSUPPORTED				= 0x02,
	READ_DEV_TX_UNSUPPORTED				= 0x03,

	READ_DIAG_OUT_OF_RANGE				= 0x10,
	READ_DEV_TX_OUT_OF_RANGE			= 0x11,
	WRITE_DEV_RX_OUT_OF_RANGE			= 0x12,
	
	SDE_EC_READ_SIZE_LIMIT				= 0x20,
	SDE_EC_WRITE_SIZE_LIMIT				= 0x21,
	SDE_EC_NOT_EXPECTED_MSG_SIZE		= 0x22,

}SDE_EXCEPTION_CODE_T;

}
#endif /* SIMPLE_DATA_EXCHANGE_DEF_H_ */
