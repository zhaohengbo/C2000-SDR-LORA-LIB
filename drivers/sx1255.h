#ifndef DRIVERS_SX1255_H_
#define DRIVERS_SX1255_H_

#ifdef __cplusplus
extern "C" {
#endif

void sx1255_init(void);
void sx1255_dms_start_rx(void);
void sx1255_dms_start_tx(void);

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* DRIVERS_SX1255_H_ */
