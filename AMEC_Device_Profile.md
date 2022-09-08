# Electrical Engineering Reserved

| Variable Name                      | Data Type | Unit | Access | Comment                                                      |
| ---------------------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Heater Exchange Serial Port Status | USHORT    | N/A  | Tx     | 0x0000: There is no error<br/>0x0001: Sending request error<br/>0x0002: Data frame format error<br/>0x0003: Receiving response error |
| Throttle Valve SIPE                | FLOAT     | Torr | Rx     |                                                              |



# Controller

| Variable Name                   | Data Type | Unit | Access | Comment                                                      |
| ------------------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| PLC Tick Counter                | UINT      | N/A  | Tx     | PLC system tick counter (micro-second)                       |
| Aggregated System State         | UINT      | N/A  | Tx     | Bit0: Runtime State 0 -> Not running 1 -> Running <br/>Bit1: ECAT Network State 0 -> Communication not Started 1 -> Communicating <br/>Bit2: ECAT Slaves State 0 -> At least one slave is not working in OP state 1 -> All slaves are working in OP state <br/>Bit3: Sub-Controller State 0 -> At least one sub-controller is working in WDT ERR state 1 -> All sub-controllers are connected and the communication is normal |
|                                 |           |      |        |                                                              |
| SMART ECAT Communication Status | USHORT    | N/A  | Tx     | 0x0000: The communication has not started yet. <br/>0x0001: During communication. <br/>0x0002: The cable disconnection has occurred. |
| SMART ECAT Event Code           | UINT      | N/A  | Tx     | 0x00000001: EtherCAT operation status change <br/>0x00001001: Bus mismatch (mismatch between ENI file and communication status) <br/>0x00001002: Alias address is overlapped <br/>0x00001003: Cable disconnection <br/>0x00001004: Violation of EtherCAT cycle time <br/>0x00010001: Cyclic command: Working counter error <br/>0x0001000B: No response or failed of slave initial command <br/>0x0001000F: Not all slave is op status during receiving cyclic frame <br/>0x00010010: Ethernet link connection error <br/>0x00010014: Slave error status information <br/>0x00010019: CoE SDO Abort <br/>0x0001001E: PDI Watchdog expired on slave <br/>0x00040002: Detection of HC Group(Boot) <br/>0x00040003: Detection of HC Group <br/>0x00040004: Completion of the HC topology change <br/>0x00040005: Slave removed <br/>0x00040006: Slave added |



## Device Common

| Variable Name       | Data Type | Unit | Access | Comment                                                      |
| ------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Device Availability | USHORT    | N/A  | Tx     | 0x0000: There is no error <br/>0x0001: SMART-ECAT cannot communicate with the slave <br/>0x0002: The slave status is not OP (Operational) <br/>0x8000: Serial Port Communication Error (For industrial bus gateway) <br/>0x8001: Device Watchdog Error (For sub-control system) |



## Heater Exchange

| Variable Name        | Data Type | Unit          | Access | Comment                                                      |
| -------------------- | --------- | ------------- | ------ | ------------------------------------------------------------ |
| Temperature Reading  | SHORT     | 0.1℃          | Tx     | 0.0 to 150.0℃= 0h to 5DCh (0.1℃/dig)                         |
| Flow Reading         | SHORT     | 0.1LPM/0.1GPM | Tx     | 0.0 to 150.0LPM = 0h to 5DCh (0.1LPM/dig) <br/>0.0 to 40.0GPM = 0h to 190h (0.1GPM/dig) |
| Pressure Reading     | SHORT     | 0.01MPa/1PSI  | Tx     | 0.00 to 2.00MPa = 0h to C8h (0.01MPa/dig) <br/>0 to 290PSI = 0h to 122h (1PSI/dig) |
| Resistance Reading   | SHORT     | 0.01MΩ        | Tx     | 0 to 2.00MΩ= 0h to C8h (0.01MΩ/dig)                          |
| Status Flag          | USHORT    | N/A           | Tx     | bit0: Run flag (0 = Stop 1 = Run) <br/>bit1: Fault flag (0 = Not occurred 1 = Fault alarm given off) <br/>bit2: Warning flag (0 = Not occurred 1 = Warning alarm given off) <br/>bit3: Flow Unit flag (0 = LPM 1 = GPM) <br/>bit4: Press Unit flag (0 = MPa 1 = PSI) <br/>bit5: Remote flag (0 = Local 1 = SER REMOTE) <br/>bit6: AUTO PURGE ready flag (0 = Condition isn’t formed 1 = Condition is formed)<br/>bit7: AUTO PURGE running flag (0 = Stop 1 = running) <br/>bit8: Time out (0 = Not occurred 1 = Occurred) bit9: TEMP READY flag (0 = Condition isn’t formed 1 = Condition is formed) |
| Temperature Setpoint | SHORT     | 0.1℃          | Rx     |                                                              |
| Flow Setpoint        | SHORT     | LPM           | Rx     |                                                              |
| Control Flag         | USHORT    | N/A           | Rx     | bit0: Run/ Stop flag (0= Stop, 1= Run)  <br/>bit1: AUTO PURGE flag (0= Stop, 1= Run) |



## Lift Motor

| Variable Name            | Data Type | Unit  | Access | Comment                                                      |
| ------------------------ | --------- | ----- | ------ | ------------------------------------------------------------ |
| Controller Status        | USHORT    | N/A   | Tx     | Same as CiA402 motor driver status word (0x6041)             |
| Current Position         | INT       | 0.1mm | Tx     |                                                              |
| Controller Error Code    | UINT      | N/A   | Tx     | 0x00000000: NO_ERROR <br/>0x00000001: ECAT_FAULT <br/>0x00000003: DRV_FAULT <br/>0x00000004: DRV_OPT_MODE_ERROR <br/>0x00000005: DRV_LIMIT_ERROR <br/>0x00000006: OPT_TIMEOUT <br/>0x00000007: DRV_WARNING <br/>0x00000008: HOMING_ERROR <br/>0x00000009: DRV_NOT_ENABLED |
| Controller ACK           | UINT      | N/A   | Tx     | Bit0: Enable Driver and Motor <br/>Bit1: Disable Driver and Motor <br/>Bit2: Reset Driver Fault <br/>Bit3: Reset Driver Encoder <br/>Bit4: Move to Absolute Position <br/>Bit5: Move to Relative Position |
| Enable                   | BIT       | N/A   | Rx     | Turn on the bit to energize motor                            |
| Controller CMD           | UINT      | N/A   | Rx     | Bit0: Enable Driver and Motor <br/>Bit1: Disable Driver and Motor <br/>Bit2: Reset Driver Fault <br/>Bit3: Reset Driver Encoder <br/>Bit4: Move to Absolute Position <br/>Bit5: Move to Relative Position |
| Controller CMD Parameter | UINT      | N/A   | Rx     |                                                              |



## Baratron

| Variable Name         | Data Type | Unit | Access | Comment                                                      |
| --------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Reading Valid         | BIT       | N/A  | Tx     | Indicates whether the Value parameter contains a valid value within the specified accuracy or not.  0 = invalid, 1 = valid. |
| Over-range Exceeded   | BIT       | N/A  | Tx     |                                                              |
| Under-range Exceeded  | BIT       | N/A  | Tx     |                                                              |
| Pressure Reading      | FLOAT     | Torr | Tx     |                                                              |
| Trip Point Output All | UINT      | N/A  | Tx     | Bit 0: Status of High Trip (I 0x600E, SI 0x01)  <br/>Bit 1: Status Low Trip (I 0x600E, SI 0x02)  <br/>Bit 2: Status High Trip (I 0x600F, SI, 0x01)  <br/>Bit 3: Status Low Trip (I 0x600F, SI, 0x02)  <br/>…  <br/>Bit 30: Status High Trip (I 608F, SI 0x01)  <br/>Bit 31: Status Low Trip (I 608F, SI 0x02) |
| Trigger Point A       | BIT       | N/A  | Tx     |                                                              |
| Trigger Point B       | BIT       | N/A  | Tx     |                                                              |
| Zeroing               | BIT       | N/A  | Rx     |                                                              |
| Zeroing [FB]          | BIT       | N/A  | Tx     |                                                              |



## Throttle Valve

| Variable Name              | Data Type | Unit | Access | Comment                                                      |
| -------------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Pressure Reading           | FLOAT     | Torr | Tx     | Pressure of the sensor handler in Data Unit Pressure (SHP).  |
| Valve Position Reading     | FLOAT     | %    | Tx     | The value of the current valve position.                     |
| Control Mode Status        | BYTE      | N/A  | Tx     | 0: Idle <br/>1: Homing <br/>2: Position <br/>3: Process <br/>4: Hold <br/>5: Close <br/>6: Open <br/>7-15: Reserved <br/>16-254: Manufacturer specific 255: Exception |
| Remote Control Status      | BIT       | N/A  | Tx     | 0: Remote control active <br/>1: No remote control active    |
| Control Value Out of Range | BIT       | N/A  | Tx     |                                                              |
| PCVASM State               | BYTE      | N/A  | Tx     | State of the PCV Application State Machine. <br/>0: Start <br/>1: Executing <br/>2: Exception <br/>3-15: Reserved <br/>16-255: Manufacturer specific |
| Pressure Setpoint          | FLOAT     | Torr | Rx     |                                                              |
| Valve Position Setpoint    | FLOAT     | %    | Rx     |                                                              |
| Control Mode Set           | BYTE      | N/A  | Rx     | 0: Idle <br/>1: Homing <br/>2: Position <br/>3: Process <br/>4: Hold <br/>5: Close <br/>6: Open <br/>7-15: Reserved <br/>16-254: Manufacturer specific 255: not allowed (Exception) |



## UPC

| Variable Name           | Data Type | Unit | Access | Comment                                                      |
| ----------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Active Exception Status | BYTE      | N/A  | Tx     | ETG5003-1 <br/>Bit 0: Device Warning <br/>Bit 1: Manufacturer Warning <br/>Bit 2: Device Error <br/>Bit 3: Manufacturer Error <br/>Bit 4...7: Reserved |
| Pressure Reading        | FLOAT     | Torr | Tx     |                                                              |
| Flow Reading            | FLOAT     | SCCM | Tx     |                                                              |
| Pressure Setpoint       | FLOAT     | Torr | Rx     |                                                              |
| Actuator Mode           | BYTE      | N/A  | Rx     | 0:Feedback(Default) <br/>1:Position <br/>2:Fully Open <br/>3:Fully Close <br/>4:Freeze Position |



## MFC

| Variable Name           | Data Type | Unit | Access | Comment                                                      |
| ----------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Active Exception Status | BYTE      | N/A  | Tx     | ETG5003-1  <br/>Bit 0: Device Warning  <br/>Bit 1: Manufacturer Warning  <br/>Bit 2: Device Error  <br/>Bit 3: Manufacturer Error  <br/>Bit 4...7: Reserved |
| Flow Reading            | FLOAT     | SCCM | Tx     |                                                              |
| Flow Setpoint           | FLOAT     | SCCM | Rx     |                                                              |
| Actuator Control Mode   | BYTE      |      | Rx     | 0:Feedback(Default)  <br/>1:Position  <br/>2:Fully Open  <br/>3:Fully Close  <br/>4:Freeze Position |



## MFC with Pressure

| Variable Name           | Data Type | Unit | Access | Comment                                                      |
| ----------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Active Exception Status | BYTE      | N/A  | Tx     | ETG5003-1 <br/>Bit 0: Device Warning <br/>Bit 1: Manufacturer Warning <br/>Bit 2: Device Error <br/>Bit 3: Manufacturer Error <br/>Bit 4...7: Reserved |
| Flow Reading            | FLOAT     | SCCM | Tx     |                                                              |
| Pressure Reading        | FLOAT     | Torr | Tx     |                                                              |
| Temperature Reading     | FLOAT     | ℃    | Tx     |                                                              |
| Flow Setpoint           | FLOAT     | SCCM | Rx     |                                                              |
| Actuator Control Mode   | BYTE      |      | Rx     | 0:Feedback(Default) <br/>1:Position <br/>2:Fully Open <br/>3:Fully Close <br/>4:Freeze Position |



## RPS

| Variable Name                          | Data Type | Unit  | Access | Comment                                                      |
| -------------------------------------- | --------- | ----- | ------ | ------------------------------------------------------------ |
| RF ON Indication                       | BIT       | N/A   | Tx     | Set to 1 if RF is ON                                         |
| RF ON Requested Indication             | BIT       | N/A   | Tx     | Set to 1 if Request is made to ignite plasma                 |
| Remote Control Status                  | BIT       | N/A   | Tx     | 0: Remote control active <br/>1: No remote control active    |
| Control Value out of Range             | BIT       | N/A   | Tx     | 1 = a control value is out of range                          |
| Error Present                          | BIT       | N/A   | Tx     | Set to 1 is any Error is Present                             |
| Warning Present                        | BIT       | N/A   | Tx     | Set to 1 is any Warning is Present                           |
| Setpoint Not Reached                   | BIT       | N/A   | Tx     |                                                              |
| Interlock Open                         | BIT       | N/A   | Tx     |                                                              |
| Over Temperature Indication            | BIT       | N/A   | Tx     |                                                              |
| Actual Regulation/Control Mode Display | BYTE      | N/A   | Tx     | 10 = Monitor only 2 = Power mode 1 = Current mode            |
| Actual Power Setpoint Display          | FLOAT     | Watts | Tx     | Forward Power                                                |
| Actual Forward Power Value             | FLOAT     | Watts | Tx     |                                                              |
| Actual Reflected Power Value           | FLOAT     | Watts | Tx     |                                                              |
| Actual Delivered Power Value           | FLOAT     | Watts | Tx     |                                                              |
| Actual Frequency Command               | FLOAT     | Hz    | Tx     |                                                              |
| Actual Plasma Resistance               | FLOAT     | ohms  | Tx     |                                                              |
| Actual Avg Ignition Vloop              | FLOAT     | Vrms  | Tx     |                                                              |
| Report FET Temperature                 | UINT      | ℃     | Tx     |                                                              |
| Report Ferrite Temperature             | UINT      | ℃     | Tx     |                                                              |
| Report Plasma Block Temperature        | UINT      | ℃     | Tx     |                                                              |
| Active Exception Status                | BYTE      | N/A   | Tx     | A condensed summary byte describing the collection of active device exceptions.<br/>Bit 0: Device Warning<br/>Bit 1: Manufacturer Warning<br/>Bit 2: Device Error<br/>Bit 3: Manufacturer Error<br/>Bit 4...7: Reserved |
| Active Device Warning Details          | USHORT    | N/A   | Tx     | Expanded details of the device warning exceptions.<br/>Bit 0 - Warning present<br/>Bit 1 - Reserved<br/>Bit 2 - OverTemp Warning<br/>Bit 3 – Cooling/Fan Warning<br/>Bit 4 – AC Line Warning<br/>Bit 5 – Voltage Limit Exceeded Warning (DC only)<br/>Bit 6 – Current Limit Exceeded Warning (DC only)<br/>Bit 7 – Power Limit Exceeded Warning<br/>Bit 8-15 – Reserved |
| Active Manufacturer Warning Details    | USHORT    | N/A   | Tx     | Expanded details of the manufacturer warning exceptions specified by the manufacturer. |
| Active Device Error Details            | USHORT    | N/A   | Tx     | Expanded details of the device error exceptions.<br/>Bit 0 – Error present<br/>Bit 1 – Interlock open<br/>Bit 2 - OverTemp Error<br/>Bit 3 – Cooling/Fan Error<br/>Bit 4 – AC Line ErrorBit 5-15 – Reserved |
| Active Manufacturer Error Details      | USHORT    | N/A   | Tx     | Expanded details of the manufacturer warning exceptions specified by the manufacturer. |
| Enable                                 | BIT       | N/A   | Rx     | DO Interlock                                                 |
| RF ON Request                          | BIT       | N/A   | Rx     | Set to 1 to ignite Plasma and have RF ON                     |
| Error Reset                            | BIT       | N/A   | Rx     | MKS: N/A – Errors must be cleared manually, this has no effect on error states |
| Regulation/Control Mode Set            | BYTE      | N/A   | Rx     | 10 = Monitor only 2 = Power mode 1 = Current mode            |
| Forward Power Setpoint                 | FLOAT     | Watts | Rx     | Set to the desired Power (Watts). If left as zero, then 0x6005:0 will display zero, and the Paragon will use the previously stored value from memory. |



## Dry Pump

| Variable Name                   | Data Type | Unit | Access | Comment                                                      |
| ------------------------------- | --------- | ---- | ------ | ------------------------------------------------------------ |
| Roughing Status                 | BIT       | N/A  | Tx     | 1:Run; <br/>0:Stop;                                          |
| Booster 1 Status                | BIT       | N/A  | Tx     | 1:Run; <br/>0:Stop;                                          |
| Booster 2 Status                | BIT       | N/A  | Tx     | 1:Run; <br/>0:Stop;                                          |
| Low Speed Mode Status           | BIT       | N/A  | Tx     | 1:Low Speed (Idle); <br/>0:Normal Speed;                     |
| Remote Control Status           | BIT       | N/A  | Tx     | 1:Local. Hand control enabled;  <br/>0:Remote, EtherCAT® control enabled; |
| Warning Status                  | BIT       | N/A  | Tx     | 1:Warning; <br/>0:Normal;                                    |
| Alarm Status                    | BIT       | N/A  | Tx     | 1:Alarm; <br/>0:Normal;                                      |
| Emergency Off Status            | BIT       | N/A  | Tx     | 1:Stop; <br/>0:Normal;                                       |
| N2 Flow Low                     | BIT       | N/A  | Tx     | 1:N2 Flow Low; <br/>0: Normal                                |
| N2 Level Ready                  | BIT       | N/A  | Tx     | 1:OK (High level); <br/>0: Not Ready (Low level)             |
| Pump Interlock Ready            | BIT       | N/A  | Tx     | 1:OK Process may proceed; <br/>0:Process must not run;       |
| Inlet Gate Valve                | BIT       | N/A  | Tx     | 1:Open; <br/>0:Closed                                        |
| TxPdoState                      | BIT       | N/A  | Tx     | True if pump data invalid                                    |
|                                 |           |      |        |                                                              |
| Active Exception Status         | BYTE      | N/A  | Tx     | ETG5003-1  <br/>Bit 0: Device Warning  <br/>Bit 1: Manufacturer Warning  <br/>Bit 2: Device Error  <br/>Bit 3: Manufacturer Error  <br/>Bit 4...7: Reserved |
| Dry Pump Roughing Control       | BIT       | N/A  | Rx     | 1:Run; <br/>0:Stop;  <br/>Valid when Roughing Pump exists (0x9000:01 = 1); |
| Dry Pump Booster 1 Control      | BIT       | N/A  | Rx     | 1:Run; <br/>0:Stop; <br/>Valid when Booster exists (0x9000:02 = 1) and Booster Control mode setting is Independent mode (0x8001:02 = 1); |
| Dry Pump Booster 2 Control      | BIT       | N/A  | Rx     | 1:Run; <br/>0:Stop; <br/>Valid when Booster exists (0x9000:03 = 1) and Booster Control mode setting is Independent mode (0x8001:02 = 1); |
| Dry Pump Low Speed Mode Control | BIT       | N/A  | Rx     | 1:Low Speed (Idle/Sleep/Green Mode); <br/>0:Normal; <br/>When 0x6000:01 = 1, this control is enabled; |



## Temperature Control Loop

| Variable Name              | Data Type | Unit  | Access | Comment                                                      |
| -------------------------- | --------- | ----- | ------ | ------------------------------------------------------------ |
| CHx Operating Status       | USHORT    | N/A   | Tx     | BIT0:  0 -> RUN  1 -> STOP <br/>BIT8:  0 -> AUTO MODE  1 -> MANUAL MODE <br/>BIT9: Reflect Manual MV  0 -> NOT REFLECTED   1 -> REFLECTED <br/>BIT10: Reflect Data for Adjustment 0 -> NOT REFLECTED  1 -> REFLECTED |
| CHx Alarm Status           | USHORT    | N/A   | Tx     | Customized definition                                        |
| CHx Controlled Temperature | FLOAT     | ℃     | Tx     |                                                              |
| CHx Measured Temperature   | FLOAT     | ℃     | Tx     |                                                              |
| CHx MVh Monitoring Value   | FLOAT     | %     | Tx     | Range 0-100.0                                                |
| CHx Output Power Monitor   | FLOAT     | watts | Tx     |                                                              |
| CHx Heating Rate Monitor   | SHORT     | ℃/min | Tx     |                                                              |
| CHx Cooling Rate Monitor   | SHORT     | ℃/min | Tx     |                                                              |
| CHx P Band Monitor         | SHORT     | 0.1 ℃ | Tx     |                                                              |
| CHx I Time Monitor         | SHORT     | 0.1 s | Tx     |                                                              |
| CHx D Time Monitor         | SHORT     | 0.1 s | Tx     |                                                              |
| CHx FF Waiting Monitor     | USHORT    | N/A   | Tx     | For PreBoost                                                 |
| CHx FF Operating Monitor   | USHORT    | N/A   | Tx     | For PreBoost                                                 |
| CHx FF MV0 Monitor         | SHORT     | N/A   | Tx     | For PreBoost                                                 |
| CHx FF MV1 Monitor         | SHORT     | N/A   | Tx     | For PreBoost                                                 |
| CHx FF MV2 Monitor         | SHORT     | N/A   | Tx     | For PreBoost                                                 |
| CHx FF MV3 Monitor         | SHORT     | N/A   | Tx     | For PreBoost                                                 |
| CHx Operating Command      | USHORT    | N/A   | Rx     | BIT0:  0 -> RUN  1 -> STOP   (LEVEL)  <br/>BIT8:  0 -> AUTO MODE  1 -> MANUAL MODE   (LEVEL)  <br/>BIT9: Reflect Manual MV 0 -> DO NOT REFLECT  1 -> REFLECT  (LEVEL)  <br/>BIT10: Reflect Data for Adjustment 0 -> DO NOT REFLECT  1 -> REFLECT  (LEVEL) |
| CHx Setpoint               | FLOAT     | ℃     | Rx     |                                                              |
| CHx Manual MVh             | FLOAT     | %     | Rx     | Range 0-100.0                                                |
| CHx Heating Rate           | SHORT     | ℃/min | Rx     |                                                              |
| CHx Cooling Rate           | SHORT     | ℃/min | Rx     |                                                              |
| CHx P Band Override        | SHORT     | 0.1 ℃ | Rx     |                                                              |
| CHx I Time Override        | SHORT     | 0.1 s | Rx     |                                                              |
| CHx D Time Override        | SHORT     | 0.1 s | Rx     |                                                              |
| CHx FF Waiting Override    | USHORT    | N/A   | Rx     | For PreBoost                                                 |
| CHx FF Operating Override  | USHORT    | N/A   | Rx     | For PreBoost                                                 |
| CHx FF MV0 Override        | SHORT     | N/A   | Rx     | For PreBoost                                                 |
| CHx FF MV1 Override        | SHORT     | N/A   | Rx     | For PreBoost                                                 |
| CHx FF MV2 Override        | SHORT     | N/A   | Rx     | For PreBoost                                                 |
| CHx FF MV3 Override        | SHORT     | N/A   | Rx     | For PreBoost                                                 |
| CHx Power Supply           | BIT       | N/A   | Rx     | Turn ON the main contactor                                   |