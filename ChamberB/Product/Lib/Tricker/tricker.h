/*
 * tricker.h
 *
 *  Created on: May 19, 2022
 *      Author: HaihangRen
 */

#ifndef TRICKER_H_
#define TRICKER_H_

#include "../IOControl/r2h_task_io_control.h"
#include "../common_def.h"
#include "../utility.h"

namespace R2H_AMEC_PRODUCT
{
class Tricker617
{
public:
	Tricker617();
	void Init(R2H_Task_ProcessDataObjectManager *pObjectManager);
	void Procceed(R2H_ULONG counterMicros);
private:
	R2H_BYTE* __iso_hearer_jacket_ptr;
	R2H_UINT32 __iso_hearer_jacket_bit;
	R2H_BYTE* __iso_hearer_jacket_fb_ptr;
	R2H_UINT32 __iso_hearer_jacket_fb_bit;
	
	R2H_BYTE* __throttle_hearer_jacket_ptr;
	R2H_UINT32 __throttle_hearer_jacket_bit;
	R2H_BYTE* __throttle_hearer_jacket_fb_ptr;
	R2H_UINT32 __throttle_hearer_jacket_fb_bit;
	
	R2H_BYTE* __iso_fast_vlv_open_fb_ptr;
	R2H_UINT32 __iso_fast_vlv_open_fb_bit;
	R2H_BYTE* __iso_fast_vlv_opened_ptr;
	R2H_UINT32 __iso_fast_vlv_opened_bit;
	R2H_BYTE* __iso_fast_vlv_closed_ptr;
	R2H_UINT32 __iso_fast_vlv_closed_bit;
	
	R2H_BYTE* __iso_slow_vlv_open_ptr;
	R2H_UINT32 __iso_slow_vlv_open_bit;
	R2H_BYTE* __iso_slow_vlv_open_fb_ptr;
	R2H_UINT32 __iso_slow_vlv_open_fb_bit;
	R2H_BYTE* __iso_slow_vlv_opened_ptr;
	R2H_UINT32 __iso_slow_vlv_opened_bit;
	R2H_BYTE* __iso_slow_vlv_closed_ptr;
	R2H_UINT32 __iso_slow_vlv_closed_bit;
	
	R2H_BYTE* __v_ar_9_ptr;
	R2H_UINT32 __v_ar_9_bit;
	R2H_BYTE* __v_ar_9_fb_ptr;
	R2H_UINT32 __v_ar_9_fb_bit;
	
	R2H_BYTE* __v_ar_10_ptr;
	R2H_UINT32 __v_ar_10_bit;
	R2H_BYTE* __v_ar_10_fb_ptr;
	R2H_UINT32 __v_ar_10_fb_bit;

	R2H_BYTE* __over_pressure_pv_ptr;
	R2H_UINT32 __over_pressure_pv_bit;
	R2H_BYTE* __over_pressure_pv_fb_ptr;
	R2H_UINT32 __over_pressure_pv_fb_bit;
	
	R2H_BYTE* __temperature_controller_heartbeat_ptr;
	R2H_BYTE* __st1_temperature_controller_availablity_ptr;
	R2H_BYTE* __st2_temperature_controller_availablity_ptr;
	R2H_BYTE* __st1_temperature_controller_wdt_ptr;
	R2H_UINT32 __st1_temperature_controller_wdt_bit;
	R2H_BYTE* __st2_temperature_controller_wdt_ptr;
	R2H_UINT32 __st2_temperature_controller_wdt_bit;
	
	R2H_UINT16 __last_heartbeat_count;
	R2H_ULONG __last_ticks;
	R2H_UINT32 __timer;
	R2H_UINT32 __timeout_value;
};

}





#endif /* TRICKER_H_ */
