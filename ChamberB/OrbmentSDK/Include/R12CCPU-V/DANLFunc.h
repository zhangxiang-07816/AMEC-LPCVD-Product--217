#ifndef DANLFUNC_H
#define DANLFUNC_H

typedef struct {
	long		lFilterType;
	float		fCutoffFreqHz1;
	float		fCutoffFreqHz2;
	long		lFilterCalcType;
	long		lDegree;
	float		fRipple;
} DIGITAL_FILTER_SETTINGS_STRUCT;


#ifdef __cplusplus
extern "C" {
#endif

short DANL_SetOpCondition( long* plSet, long lSetNum );
short DANL_GetOpCondition( long* plGet, long lGetNum );
short DANL_DigitalFilter( float* pfData, long lPoint, long lSamplingCycle, DIGITAL_FILTER_SETTINGS_STRUCT DigitalFilterSettings, float* pfOutput );
short DANL_EnvelopeCalculation (float* pfData, long lPoint, float* pfOutput);
short DANL_FFTSpectrum( float* pfData, long lPoint, long lWindowType, long lSpectrumFormat, float* pfOutput );
short DANL_FindCrossPoint( float* pfData, long lPoint, float fReferenceValue, long lCrossPattern, long lMaxPoint, long* plCrossData, long* plCrossPoint );
short DANL_Peak(float* pfData, long lPoint, float* pfMaxData, float* pfMinData);
short DANL_RMS(float* pfData, long lPoint, float* pfOutput);
short DANL_BoundCompareTest( float* pfData, long lPoint, float fLowerLimit, float fUpperLimit, long* plResult );
short DANL_AryBoundCompareTest( float* pfData,long lPoint, float* pfLowerLimit, float* pfUpperLimit, long* plResult );
short DANL_LeastSquare(float* pfDataX, float* pfDataY, long lPoint,long lDegree, float* pfOutput, float* pfCoefficient);
short DANL_MovingAverage(float* pfData, long lPoint, long lAveragePoint, float* pfOutput);
short DANL_StandardDeviation(float* pfData, long lPoint, float* pfOutput);
short DANL_Variance(float* pfData, long lPoint, float* pfOutput);


#ifdef __cplusplus
}
#endif

#endif	/* DANLFUNC_H */
