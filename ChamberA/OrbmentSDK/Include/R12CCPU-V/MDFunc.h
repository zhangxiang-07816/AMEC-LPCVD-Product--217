#ifdef __cplusplus
extern "C" {
#endif
	short  mdOpen( short, short, long * );
	short  mdClose( long );
	short  mdControl( long, short, short );
	short  mdTypeRead( long, short, short * );
	short  mdInit( long );
	long  mdSendEx( long, long, long, long, long, long*, void* );
	long  mdReceiveEx( long, long, long, long, long, long*, void* );
	long  mdDevSetEx( long, long, long, long, long );
	long  mdDevRstEx( long, long, long, long, long );
	long  mdRandWEx( long, long, long, void*, void*, long );
	long  mdRandREx( long, long, long,  void*, void*, long );
	long  mdGetLabelInfo( long, long, long, long, void*, void*, unsigned long long* );
	long  mdRandWLabelEx( long, long, long, void*, void*, long, unsigned long long );
	long  mdRandRLabelEx( long, long, long, void*, void*, long, unsigned long long );
#ifdef __cplusplus
}
#endif


#define	DevX		(1)
#define	DevLX(x)	(DevX*1000+(x))
#define	DevY		(2)
#define	DevLY(x)	(DevY*1000+(x))
#define	DevL		(3)
#define	DevM		(4)
#define	DevSM		(5)
#define	DevF		(6)
#define	DevTT		(7)
#define	DevTC		(8)
#define	DevCT		(9)
#define	DevCC		(10)
#define	DevTN		(11)
#define	DevCN		(12)
#define	DevD		(13)
#define	DevSD		(14)
#define	DevZ		(20)
#define	DevR		(22)
#define	DevZR		(220)
#define	DevB		(23)
#define	DevLB(x)	(DevB*1000+(x))
#define	DevW		(24)
#define	DevLW(x)	(DevW*1000+(x))
#define	DevQSB		(25)
#define	DevLSB(x)	(DevQSB*1000+(x))
#define	DevSTT		(26)
#define	DevSTC		(27)
#define	DevQSW		(28)
#define	DevLSW(x)	(DevQSW*1000+(x))
#define	DevSPG(x)	(29*1000+(x))
#define	DevQV		(30)
#define	DevMRB		(33)
#define	DevSTN		(35)
#define	DevWw		(36)
#define	DevWr		(37)
#define	DevLZ		(38)
#define	DevRD		(39)
#define	DevLTT		(41)
#define	DevLTC		(42)
#define	DevLTN		(43)
#define	DevLCT		(44)
#define	DevLCC		(45)
#define	DevLCN		(46)
#define	DevLSTT		(47)
#define	DevLSTC		(48)
#define	DevLSTN		(49)
#define	DevSPB		(50)
#define	DevSPB1		(501)
#define	DevSPB2		(502)
#define	DevSPB3		(503)
#define	DevSPB4		(504)
#define	DevHSPB1	(511)
#define	DevHSPB2	(512)
#define	DevHSPB3	(513)
#define	DevHSPB4	(514)
#define DevGV		(600)
#define DevGV_0		(601)
#define DevGV_1		(602)
#define DevGV_2		(603)
#define DevGV_3		(604)
#define DevGV_4		(605)
#define DevGV_5		(606)
#define DevGV_6		(607)
#define DevGV_7		(608)
#define DevGV_8		(609)
#define DevGV_9		(610)
#define DevGV_A		(611)
#define DevGV_B		(612)
#define DevGV_C		(613)
#define DevGV_D		(614)
#define DevGV_E		(615)
#define DevGV_F		(616)
#define	DevMAIL		(101)
#define	DevMAILNC	(102)
#define	DevRBM		(-32768)
#define	DevRAB		(-32736)
#define	DevRX		(-32735)
#define	DevRY		(-32734)
#define	DevRW		(-32732)
#define	DevSB		(-32669)
#define	DevSW		(-32668)

