#ifndef _FFT_H_
#define _FFT_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NULL    0         

#define CFFT32_8P_DEFAULTS    {     \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    8,                              \
    3,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    128,                            \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win} 

#define CFFT32_16P_DEFAULTS    {    \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    16,                             \
    4,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    256,                            \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win} 

#define CFFT32_32P_DEFAULTS    {    \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    32,                             \
    5,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    128,                            \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win} 

#define CFFT32_64P_DEFAULTS    {    \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    64,                             \
    6,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    64,                             \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win} 

#define CFFT32_128P_DEFAULTS    {   \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    128,                            \
    7,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    32,                             \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win} 
 
#define CFFT32_256P_DEFAULTS    {   \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    256,                            \
    8,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    16,                             \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win} 
      
#define CFFT32_512P_DEFAULTS    {   \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    512,                            \
    9,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    8,                              \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win}  
  
#define CFFT32_1024P_DEFAULTS    {  \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    1024,                           \
    10,                             \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    4,                              \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win}   

#define CFFT32_2048P_DEFAULTS    {  \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    2048,                           \
    11,                             \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    2,                              \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_izero,  \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))CFFT32_mag,   \
    (void (*)(void *))CFFT32_win}

#define RFFT32_brev_RT_ACQ_DEFAULTS { \
    1,                                \
    0,                                \
    0,                                \
    (int32_t *)NULL,                  \
    (int32_t *)NULL,                  \
    0,                                \
    (void (*)(void *))RFFT32_brev_RT}

#define RFFT32_32P_DEFAULTS    {    \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    16,                             \
    4,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    256,                            \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win}        

#define RFFT32_64P_DEFAULTS    {    \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    32,                             \
    5,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    128,                             \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win}  

#define RFFT32_128P_DEFAULTS    {   \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    64,                             \
    6,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    64,                             \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win} 

#define RFFT32_256P_DEFAULTS    {   \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    128,                            \
    7,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    32,                             \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win} 

#define RFFT32_512P_DEFAULTS    {   \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    256,                            \
    8,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    16,                              \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win} 

#define RFFT32_1024P_DEFAULTS    {  \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    512,                            \
    9,                              \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    8,                              \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win}

#define RFFT32_2048P_DEFAULTS    {  \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    1024,                           \
    10,                             \
    (int32_t *)NULL,                \
    (int32_t *)NULL,                \
    0,                              \
    0,                              \
    4,                              \
    (void (*)(void *))FFT32_init,   \
    (void (*)(void *))FFT32_calc,   \
    (void (*)(void *))RFFT32_split, \
    (void (*)(void *))RFFT32_mag,   \
    (void (*)(void *))RFFT32_win} 

#define RFFT32_4096P_DEFAULTS    { \
    (int32_t *)NULL,               \
    (int32_t *)NULL,               \
    2048,                          \
    11,                            \
    (int32_t *)NULL,               \
    (int32_t *)NULL,               \
    0,                             \
    0,                             \
    2,                             \
    (void (*)(void *))FFT32_init,  \
    (void (*)(void *))FFT32_calc,  \
    (void (*)(void *))RFFT32_split,\
    (void (*)(void *))RFFT32_mag,  \
    (void (*)(void *))RFFT32_win} 
	
typedef struct {   
    int32_t *ipcbptr;
    int32_t *tfptr;
    int16_t size;
    int16_t nrstage;
    int32_t *magptr;
    int32_t *winptr;
    int32_t peakmag;
    int16_t peakfrq;
    int16_t ratio;
    void (*init)(void *);
    void (*izero)(void *);
    void (*calc)(void *);
    void (*mag)(void *);
    void (*win)(void *);
}CFFT32;

typedef struct CFFT32 *CFFT32_Handle;

typedef struct {   
    int32_t *ipcbptr;
    int32_t *tfptr;        
    int16_t size;
    int16_t nrstage;     
    int32_t *magptr;
    int32_t *winptr;
    int32_t peakmag;
    int16_t peakfrq;
    int16_t ratio;
    void (*init)(void *);
    void (*calc)(void *);
    void (*split)(void *);
    void (*mag)(void *);
    void (*win)(void *);
}RFFT32;               

typedef struct RFFT32 *RFFT32_Handle;

typedef struct {
    int16_t acqflag;
    int16_t count;
    int32_t input;
    int32_t *tempptr;
    int32_t *buffptr;
    int16_t size;
    void (*update)(void *);
}RFFT32_brev_RT_ACQ; 

typedef struct RFFT32_brev_RT_ACQ *RFFT32_brev_RT_ACQ_Handle;
void RFFT32_brev_RT(void *); 
void RFFT32_brev(int32_t *src, int32_t *dst, uint16_t size);
void RFFT32_win(void *); 
void RFFT32_split(void *); 
void RFFT32_mag(void *);
void CFFT32_brev(int32_t *src, int32_t *dst, uint16_t size); 
void CFFT32_win(void *); 
void CFFT32_win_dual(void *); 
void FFT32_izero(void *);
void CFFT32_mag(void *);
void FFT32_calc(void *); 
void FFT32_init(void *);

#ifdef __cplusplus
{
#endif

#endif
