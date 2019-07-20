#include "DSP28x_Project.h"
#include "libs/safepipe/safepipe_rx.h"

/*
    Although we call this safepipe, it is not safe at all!!!
    Callers must obey the rules, otherwise bad things will happen!!!
    For readers, safepipe_readable----->safepipe_read_update----->safepipe_get_current_read_buf
    For writers, safepipe_writeable----->safepipe_get_current_write_buf----->safepipe_write_update
    For writers(int), safepipe_writeable----->safepipe_write_update----->safepipe_get_current_write_buf
*/

void safepipe_rx_init(safepipe_rx_t *pipe_p,int size,void **buf_p)
{
    //check the size, at least 4 as one for write guard, one for read guard, two for use
    if(size < 4)
    {
        return;
    }
    pipe_p->size = size;
    pipe_p->read_count = 0;
    pipe_p->write_count = 2;
    pipe_p->buf_p = buf_p;
}

Uint16 safepipe_rx_writeable(safepipe_rx_t *pipe_p)
{
    Uint16 new_write_count;
    new_write_count = (pipe_p->write_count + 1) % pipe_p->size;

    if(new_write_count != pipe_p->read_count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void safepipe_rx_write_update(safepipe_rx_t *pipe_p)
{
    Uint16 new_write_count;
    new_write_count = (pipe_p->write_count + 1) % pipe_p->size;
    pipe_p->write_count = new_write_count;
}

void *safepipe_rx_get_current_write_buf(safepipe_rx_t *pipe_p)
{
    return pipe_p->buf_p[pipe_p->write_count];
}

void *safepipe_rx_get_ori_write_buf(safepipe_rx_t *pipe_p)
{
    Uint16 old_write_count;
    old_write_count = (pipe_p->write_count - 1) % pipe_p->size;
    return pipe_p->buf_p[old_write_count];
}

Uint16 safepipe_rx_readable(safepipe_rx_t *pipe_p)
{
    Uint16 new_read_count;
    new_read_count = (pipe_p->read_count + 2) % pipe_p->size;

    if(new_read_count != pipe_p->write_count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void safepipe_rx_read_update(safepipe_rx_t *pipe_p)
{
    Uint16 new_read_count;
    new_read_count = (pipe_p->read_count + 1) % pipe_p->size;
    pipe_p->read_count = new_read_count;
}

void *safepipe_rx_get_current_read_buf(safepipe_rx_t *pipe_p)
{
    return pipe_p->buf_p[pipe_p->read_count];
}
