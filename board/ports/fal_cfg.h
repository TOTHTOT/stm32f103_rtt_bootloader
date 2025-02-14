/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-12-8      zylx         first version
 */

#ifndef _FAL_CFG_H_
#define _FAL_CFG_H_

#include <rtthread.h>
#include <board.h>

extern const struct fal_flash_dev stm32_onchip_flash;
#define RT_APP_PART_ADDR            (0x08000000 + 32 * 1024)  // app partition begin address

/* flash device table */
#define FAL_FLASH_DEV_TABLE                                          \
{                                                                    \
    &stm32_onchip_flash,                                             \
}
/* ====================== Partition Configuration ========================== */
#ifdef FAL_PART_HAS_TABLE_CFG

/* partition table */
#define FAL_PART_TABLE                                                                \
    {                                                                                  \
			{FAL_PART_MAGIC_WORD, "app", "onchip_flash", 32 * 1024, 150 * 1024, 0},       \
			  {FAL_PART_MAGIC_WORD, "factory", "onchip_flash", 182 * 1024, 1 * 1024, 0},       \
        {FAL_PART_MAGIC_WORD, "download", "onchip_flash", 183 * 1024, 73 * 1024, 0}, \
    } 
#endif /* FAL_PART_HAS_TABLE_CFG */
#endif /* _FAL_CFG_H_ */
