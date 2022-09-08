/*
 * r2h_ilink_exception.h
 *
 *  Created on: 2020-3-26
 *      Author: CrazyHein
 */

#ifndef R2H_ILINK_EXCEPTION_H_
#define R2H_ILINK_EXCEPTION_H_

#include <exception>
#include "../r2h_ilink_data_type.h"
#include "../r2h_ilink_error_code.h"

namespace R2H_ILINK
{
	class Exception : public std::exception
	{
	public:
		Exception(R2H_INT32 errorCode);
		Exception(std::exception &e);
		virtual ~Exception();
		R2H_INT32 ReturnErrorCode();
		const std::exception& ReturnInnerSTDException();
	private:
		R2H_INT32			__error_code;
		std::exception		__inner_std_exception;
	};

}



#endif /* R2H_ILINK_EXCEPTION_H_ */
