#ifdef __cplusplus
extern "C" {
#endif
	short mdrOpen( short, short, long *, long );
	short mdrClose( long );
	short mdrControl( long, short, long, long, long, short, short );
	short mdrTypeRead( long, short, long, long, long, short, short * );
	short mdrInit( long );
	short mdrSend( long, short, long, long, long, short, long, long, long*, short* );
	short mdrReceive( long, short, long, long, long, short, long, long, long*, short* );
	short mdrDevSet( long, short, long, long, long, short, long, long );
	short mdrDevRst( long, short, long, long, long, short, long, long );
	short mdrRandW( long, short, long, long, long, short, long*, short*, long );
	short mdrRandR( long, short, long, long, long, short, long*, short*, long );
	short mdrGetLabelInfo( long, short, long, long, long, short, long, void*, long*, unsigned long long* );
	short mdrRandWLabel( long, short, long, long, long, short, long*, short*, long, unsigned long long );
	short mdrRandRLabel( long, short, long, long, long, short, long*, short*, long, unsigned long long );
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
#define	DevSTN		(35)
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

