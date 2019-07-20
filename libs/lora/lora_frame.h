#ifndef LIBS_LORA_LORA_FRAME_H_
#define LIBS_LORA_LORA_FRAME_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef  struct
{
	int16 type;
	int16 src_addr;
	int16 dst_addr;
	int16 length;
	int16 data[32];
}lora_frame_t;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* LIBS_LORA_LORA_FRAME_H_ */
