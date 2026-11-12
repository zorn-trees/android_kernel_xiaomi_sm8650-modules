/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Userspace interface of the xiaomi-touch misc device (/dev/xiaomi-touch).
 *
 * Mirrors the definitions in xiaomi/xiaomi_touch_type_common.h and the
 * checks done in xiaomi_touch_dev_ioctl():
 *   - _IOC_TYPE(cmd) must be XIAOMI_TOUCH_IOC_MAGIC
 *   - _IOC_NR(cmd) selects the enum xiaomi_touch_ioctl_cmd entry
 *   - for XIAOMI_TOUCH_COMMON_DATA_CMD, _IOC_SIZE(cmd) must be
 *     sizeof(struct xiaomi_touch_common_data)
 *
 * A client has to select its touch panel with XIAOMI_TOUCH_IOC_SELECT_TOUCH_ID
 * once after open() before sending any common data.
 */
#ifndef _UAPI_LINUX_XIAOMI_TOUCH_H
#define _UAPI_LINUX_XIAOMI_TOUCH_H

#include <linux/ioctl.h>
#include <linux/types.h>

#define XIAOMI_TOUCH_IOC_MAGIC		'T'
#define XIAOMI_TOUCH_CMD_DATA_BUF_SIZE	256

/* Primary touch panel */
#define XIAOMI_TOUCH_ID_PRIMARY		0

enum xiaomi_touch_ioctl_cmd {
	XIAOMI_TOUCH_COMMON_DATA_CMD = 0,
	XIAOMI_TOUCH_HARDWARE_PARAM_CMD,
	XIAOMI_TOUCH_SELECT_MMAP_CMD,
	XIAOMI_TOUCH_SELECT_TOUCH_ID,
	XIAOMI_TOUCH_GET_FRAME_DATA_INDEX,
	XIAOMI_TOUCH_RAW_DATA_INDEX,
	XIAOMI_TOUCH_UPDATE_REPORT_POINT,
};

enum xiaomi_touch_common_data_cmd {
	XIAOMI_TOUCH_SET_CUR_VALUE = 0,
	XIAOMI_TOUCH_GET_CUR_VALUE,
	XIAOMI_TOUCH_GET_DEF_VALUE,
	XIAOMI_TOUCH_GET_MIN_VALUE,
	XIAOMI_TOUCH_GET_MAX_VALUE,
	XIAOMI_TOUCH_GET_MODE_VALUE,
	XIAOMI_TOUCH_RESET_MODE,
	XIAOMI_TOUCH_SET_LONG_VALUE,
	XIAOMI_TOUCH_SET_THP_IC_CUR_VALUE,
	XIAOMI_TOUCH_GET_THP_IC_CUR_VALUE,
	XIAOMI_TOUCH_SET_CMD_FOR_THP,
	XIAOMI_TOUCH_SET_CMD_FOR_DRIVER,
	XIAOMI_TOUCH_UPDATE_MODEL_RESULT,
};

/* Touch modes (enum common_data_mode, DATA_MODE_x) */
#define XIAOMI_TOUCH_MODE_FOD_ENABLE	10	/* DATA_MODE_10 */
#define XIAOMI_TOUCH_MODE_AOD_ENABLE	11	/* DATA_MODE_11 */
#define XIAOMI_TOUCH_MODE_DOUBLETAP	14	/* DATA_MODE_14 */
#define XIAOMI_TOUCH_MODE_FODICON_ENABLE	16	/* DATA_MODE_16 */
#define XIAOMI_TOUCH_MODE_NONUI		17	/* DATA_MODE_17 */

struct xiaomi_touch_common_data {
	__s8 touch_id;
	__u8 cmd;
	__u16 mode;
	__u16 data_len;
	__s32 data_buf[XIAOMI_TOUCH_CMD_DATA_BUF_SIZE];
};

#define XIAOMI_TOUCH_IOC_COMMON_DATA \
	_IOW(XIAOMI_TOUCH_IOC_MAGIC, XIAOMI_TOUCH_COMMON_DATA_CMD, \
	     struct xiaomi_touch_common_data)

/* The touch id is passed directly as the ioctl argument */
#define XIAOMI_TOUCH_IOC_SELECT_TOUCH_ID \
	_IO(XIAOMI_TOUCH_IOC_MAGIC, XIAOMI_TOUCH_SELECT_TOUCH_ID)

#endif /* _UAPI_LINUX_XIAOMI_TOUCH_H */
