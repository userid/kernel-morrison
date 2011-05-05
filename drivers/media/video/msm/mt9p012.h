/* Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef MT9T012_H
#define MT9T012_H
#ifdef CONFIG_MACH_MOT
#define NEW_MCLK_PCLK
#endif

#ifdef CONFIG_MACH_MOT
#include <mach/board.h>
#else
#include <linux/types.h>
#endif

#ifdef CONFIG_MACH_MOT
extern struct mt9p012_reg_t mt9p012_regs;	/* from mt9p012_reg.c */
#else
extern struct mt9p012_reg mt9p012_regs;	/* from mt9p012_reg.c */
#endif

struct reg_struct {
	uint16_t vt_pix_clk_div;     /* 0x0300 */
	uint16_t vt_sys_clk_div;     /* 0x0302 */
	uint16_t pre_pll_clk_div;    /* 0x0304 */
	uint16_t pll_multiplier;     /* 0x0306 */
	uint16_t op_pix_clk_div;     /* 0x0308 */
	uint16_t op_sys_clk_div;     /* 0x030A */
	uint16_t scale_m;            /* 0x0404 */
	uint16_t row_speed;          /* 0x3016 */
	uint16_t x_addr_start;       /* 0x3004 */
	uint16_t x_addr_end;         /* 0x3008 */
	uint16_t y_addr_start;       /* 0x3002 */
	uint16_t y_addr_end;         /* 0x3006 */
	uint16_t read_mode;          /* 0x3040 */
	uint16_t x_output_size ;     /* 0x034C */
	uint16_t y_output_size;      /* 0x034E */
	uint16_t line_length_pck;    /* 0x300C */
	uint16_t frame_length_lines; /* 0x300A */
	uint16_t coarse_int_time;    /* 0x3012 */
	uint16_t fine_int_time;      /* 0x3014 */
	uint16_t skew;               /* 0x309E */
};


struct mt9p012_i2c_reg_conf {
	unsigned short waddr;
	unsigned short wdata;
};


#ifdef CONFIG_MACH_MOT
struct mt9p012_reg_t {
#else
struct mt9p012_reg {
#endif
	struct reg_struct const *reg_pat;
	uint16_t reg_pat_size;
	struct mt9p012_i2c_reg_conf const *ttbl;
	uint16_t ttbl_size;
	struct mt9p012_i2c_reg_conf const *lctbl;
	uint16_t lctbl_size;
	struct mt9p012_i2c_reg_conf const *rftbl;
	uint16_t rftbl_size;
};

#endif /* MT9T012_H */