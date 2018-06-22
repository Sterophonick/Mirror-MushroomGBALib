
/*---------------------------------------------------------------------------*
 *  INCLUDES                                                                 *
 *---------------------------------------------------------------------------*/

#include <mushroom/msh_bg.h>

/*---------------------------------------------------------------------------*
 *  VARIABLES                                                                *
 *---------------------------------------------------------------------------*/

// Buffer for bg scroll registers because the registers are write-only
_bgofs_t _bgofs_buf[4] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

/*---------------------------------------------------------------------------*
 *  FUNCTIONS                                                                *
 *---------------------------------------------------------------------------*/

void copy_bgmap (void *dst, u16 dw, u16 dx, u16 dy,
                 void *src, u16 sw, u16 sx, u16 sy, u16 sx_num, u16 sy_num,
                 bool maptype, u8 channel) {

	u32 tilesize  = (maptype == BG_MAPTYPE_NORMAL) ? 1 : 0;
	u32 rowsize   = sx_num << tilesize;
	u32 rem_16    = rowsize % 2;

	vu32 *dma_src = &GET_DMA_SRC(channel);
	vu32 *dma_dst = &GET_DMA_DST(channel);
	vu32 *dma_cnt = (vu32 *)&GET_DMA_CNT_L(channel);

	u32 src_start = (u32)src + (((sy * sw) + sx) << tilesize);
	u32 dst_start = (u32)dst + (((dy * dw) + dx) << tilesize);
	u32 src_width = sw << tilesize;
	u32 dst_width = dw << tilesize;
	u32 src_end   = src_start + (sy_num * src_width);
	u32 cnt       = ((DMA_SIZE_16 | DMA_ENABLE | DMA_START_NOW) << 16) | (rowsize >> 1);

	// If row size is a multiple of 2 bytes then use DMA for the whole thing
	if (rem_16 == 0) {
		// DMA copy each row
		while (src_start != src_end) {
			*dma_src = src_start;
			*dma_dst = dst_start;
			*dma_cnt = cnt;

			src_start += src_width;
			dst_start += dst_width;
		}
	// If row size is not a multiple of 2 bytes then use DMA and manually copy the remaining byte
	} else if (rowsize > 1) {
		// DMA copy each row
		while (src_start != src_end) {
			*dma_src = src_start;
			*dma_dst = dst_start;
			*dma_cnt = cnt;

			// Copy remaining byte
			*((u8 *)dst_start + dst_width - 1) = *((u8 *)src_start + src_width - 1);

			src_start += src_width;
			dst_start += dst_width;
		}
	// If row size is 1 byte then do a manual copy
	} else {
		while (src_start != src_end) {
			*(u8 *)dst_start = *(u8 *)src_start;
			src_start += src_width;
			dst_start += dst_width;
		}
	}
}


void load_bgmap (void *data, u8 mapbase, u16 dw, u16 dx, u16 dy, u16 sx_num, u16 sy_num, bool maptype, u8 channel) {
	// If no x offset and width matches then do a straight single block copy
	if ((dx == 0) && (dw == sx_num)) {
		u8 size = (maptype == BG_MAPTYPE_NORMAL) ? 1 : 0;
		dmemcpy(channel, (void *)(MEM_BG + (mapbase * 0x800) + (dy * dw)), data, (sx_num * sy_num) << size);
	} else {
		copy_bgmap((void *)(MEM_BG + (mapbase * 0x800)), dw, dx, dy, data, sx_num, 0, 0, sx_num, sy_num, maptype, channel);
	}
}

