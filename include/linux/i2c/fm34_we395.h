/* include/linux/i2c/fm34_we395.h - fm34_we395 voice processor driver
 * sound/soc/sh/fortmedia/fm34_we395.c - fm34_we395 voice processor driver
 *
 * Copyright (C) 2012 Samsung Electronics
 * Copyright (C) 2013 Renesas Mobile Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */


#ifndef __FEM34_WE395_PDATA_H__
#define __FM34_WE395_PDATA_H__

struct fm34_platform_data {
	void (*set_mclk) (bool, bool);
	int gpio_pwdn;
	int gpio_rst;
	int gpio_bp;
};

#define FM34_MODULE_NAME	"fm34_we395"

#endif
