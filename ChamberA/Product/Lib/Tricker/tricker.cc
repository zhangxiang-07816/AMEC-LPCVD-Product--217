/*
 * tricker.cc
 *
 *  Created on: May 19, 2022
 *      Author: HaihangRen
 */
#include "tricker.h"
using namespace UTILITY;

namespace R2H_AMEC_PRODUCT
{

Tricker617::Tricker617(): __last_heartbeat_count(0), __last_ticks(0), __timer(0), __timeout_value(2000000)
{
	
}

void Tricker617::Init(R2H_Task_ProcessDataObjectManager *pObjectManager)
{
	INITIALIZE_PTR(pObjectManager, "ISO Heater Jacket ON", R2H_TASK_RX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_hearer_jacket_ptr, &__iso_hearer_jacket_bit);
	INITIALIZE_PTR(pObjectManager, "ISO Heater Jacket ON [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_hearer_jacket_fb_ptr, &__iso_hearer_jacket_fb_bit);
	
	INITIALIZE_PTR(pObjectManager, "Throttle Heater Jacket ON", R2H_TASK_RX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__throttle_hearer_jacket_ptr, &__throttle_hearer_jacket_bit);
	INITIALIZE_PTR(pObjectManager, "Throttle Heater Jacket ON [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__throttle_hearer_jacket_fb_ptr, &__throttle_hearer_jacket_fb_bit);
	
	INITIALIZE_PTR(pObjectManager, "ISO Fast Vlv Open [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_fast_vlv_open_fb_ptr, &__iso_fast_vlv_open_fb_bit);
	INITIALIZE_PTR(pObjectManager, "ISO Fast Vlv Opened", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_fast_vlv_opened_ptr, &__iso_fast_vlv_opened_bit);
	INITIALIZE_PTR(pObjectManager, "ISO Fast Vlv Closed", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_fast_vlv_closed_ptr, &__iso_fast_vlv_closed_bit);
	
	INITIALIZE_PTR(pObjectManager, "ISO Slow Vlv Open", R2H_TASK_RX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_slow_vlv_open_ptr, &__iso_slow_vlv_open_bit);
	INITIALIZE_PTR(pObjectManager, "ISO Slow Vlv Open [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_slow_vlv_open_fb_ptr, &__iso_slow_vlv_open_fb_bit);
	INITIALIZE_PTR(pObjectManager, "ISO Slow Vlv Opened", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_slow_vlv_opened_ptr, &__iso_slow_vlv_opened_bit);
	INITIALIZE_PTR(pObjectManager, "ISO Slow Vlv Closed", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__iso_slow_vlv_closed_ptr, &__iso_slow_vlv_closed_bit);
	
	INITIALIZE_PTR(pObjectManager, "V-AR 9", R2H_TASK_RX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__v_ar_9_ptr, &__v_ar_9_bit);
	INITIALIZE_PTR(pObjectManager, "V-AR 9 [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__v_ar_9_fb_ptr, &__v_ar_9_fb_bit);
	
	INITIALIZE_PTR(pObjectManager, "V-AR 10", R2H_TASK_RX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__v_ar_10_ptr, &__v_ar_10_bit);
	INITIALIZE_PTR(pObjectManager, "V-AR 10 [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__v_ar_10_fb_ptr, &__v_ar_10_fb_bit);
	
	INITIALIZE_PTR(pObjectManager, "Over Pressure PV (N.O)", R2H_TASK_RX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__over_pressure_pv_ptr, &__over_pressure_pv_bit);
	INITIALIZE_PTR(pObjectManager, "Over Pressure PV (N.O) [FB]", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__over_pressure_pv_fb_ptr, &__over_pressure_pv_fb_bit);
	
	INITIALIZE_PTR(pObjectManager, "Device Heartbeat For Temperature Controller", R2H_TASK_TX_DIAGNOSTIC_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__temperature_controller_heartbeat_ptr, 0);
	INITIALIZE_PTR(pObjectManager, "ST1 Heater Controller Availability", R2H_TASK_TX_BLOCK_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__st1_temperature_controller_availablity_ptr, 0);
	INITIALIZE_PTR(pObjectManager, "ST2 Heater Controller Availability", R2H_TASK_TX_BLOCK_AREA, SIDE_DATA_TYPE_USHORT, (R2H_BYTE**)&__st2_temperature_controller_availablity_ptr, 0);
	INITIALIZE_PTR(pObjectManager, "ST1 Heater Controller Watchdog Error", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__st1_temperature_controller_wdt_ptr, &__st1_temperature_controller_wdt_bit);
	INITIALIZE_PTR(pObjectManager, "ST2 Heater Controller Watchdog Error", R2H_TASK_TX_BIT_AREA, SIDE_DATA_TYPE_BIT, (R2H_BYTE**)&__st2_temperature_controller_wdt_ptr, &__st2_temperature_controller_wdt_bit);
}

void Tricker617::Procceed(R2H_ULONG counterMicros)
{
	SET_BIT(__iso_hearer_jacket_fb_ptr, __iso_hearer_jacket_fb_bit, BIT_STATUS(__iso_hearer_jacket_ptr, __iso_hearer_jacket_bit));
	SET_BIT(__throttle_hearer_jacket_fb_ptr, __throttle_hearer_jacket_fb_bit, BIT_STATUS(__throttle_hearer_jacket_ptr, __throttle_hearer_jacket_bit));
	SET_BIT(__v_ar_9_fb_ptr, __v_ar_9_fb_bit, BIT_STATUS(__v_ar_9_ptr, __v_ar_9_bit));
	SET_BIT(__v_ar_10_fb_ptr, __v_ar_10_fb_bit, BIT_STATUS(__v_ar_10_ptr, __v_ar_10_bit));
	SET_BIT(__over_pressure_pv_fb_ptr, __over_pressure_pv_fb_bit, BIT_STATUS(__over_pressure_pv_ptr, __over_pressure_pv_bit));
	
	if(BIT_STATUS(__iso_fast_vlv_open_fb_ptr, __iso_fast_vlv_open_fb_bit))
	{
		ENABLE_BIT(__iso_fast_vlv_opened_ptr, __iso_fast_vlv_opened_bit);
		DISABLE_BIT(__iso_fast_vlv_closed_ptr, __iso_fast_vlv_closed_bit);
	}
	else
	{
		DISABLE_BIT(__iso_fast_vlv_opened_ptr, __iso_fast_vlv_opened_bit);
		ENABLE_BIT(__iso_fast_vlv_closed_ptr, __iso_fast_vlv_closed_bit);
	}
	
	if(BIT_STATUS(__iso_slow_vlv_open_ptr, __iso_slow_vlv_open_bit))
	{
		ENABLE_BIT(__iso_slow_vlv_open_fb_ptr, __iso_slow_vlv_open_fb_bit);
		ENABLE_BIT(__iso_slow_vlv_opened_ptr, __iso_slow_vlv_opened_bit);
		DISABLE_BIT(__iso_slow_vlv_closed_ptr, __iso_slow_vlv_closed_bit);
	}
	else
	{
		DISABLE_BIT(__iso_slow_vlv_open_fb_ptr, __iso_slow_vlv_open_fb_bit);
		DISABLE_BIT(__iso_slow_vlv_opened_ptr, __iso_slow_vlv_opened_bit);
		ENABLE_BIT(__iso_slow_vlv_closed_ptr, __iso_slow_vlv_closed_bit);
	}
	
	R2H_UINT16 heartbeat = *((R2H_UINT16*)__temperature_controller_heartbeat_ptr);
	
	if(heartbeat == __last_heartbeat_count)
	{
		if(__timer < __timeout_value)
			__timer += counterMicros - __last_ticks;
		/*
		R2H_ULONG delta = counterMicros - __last_ticks;
		if(delta > __timeout_value)
			__timer = __timeout_value;
		else
			__timer += delta;
			*/
			
	}
	else
	{
		__timer = 0;
	}
	__last_heartbeat_count = heartbeat;
	__last_ticks = counterMicros;
	
	if(__timer >= __timeout_value)
	{
		*((R2H_UINT16*)__st1_temperature_controller_availablity_ptr) = 0x8001;
		*((R2H_UINT16*)__st2_temperature_controller_availablity_ptr) = 0x8001;
		DISABLE_BIT(__st1_temperature_controller_wdt_ptr, __st1_temperature_controller_wdt_bit);
		DISABLE_BIT(__st2_temperature_controller_wdt_ptr, __st2_temperature_controller_wdt_bit);
	}
	else
	{
		*((R2H_UINT16*)__st1_temperature_controller_availablity_ptr) = 0;
		*((R2H_UINT16*)__st2_temperature_controller_availablity_ptr) = 0;
		ENABLE_BIT(__st1_temperature_controller_wdt_ptr, __st1_temperature_controller_wdt_bit);
		ENABLE_BIT(__st2_temperature_controller_wdt_ptr, __st2_temperature_controller_wdt_bit);		
	}
}

}
