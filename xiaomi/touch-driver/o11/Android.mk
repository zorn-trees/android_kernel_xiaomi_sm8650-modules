# SPDX-License-Identifier: GPL-2.0-only

ifneq (, $(filter zorn,$(call get-miodm-device-name)))
KBUILD_OPTIONS += CONFIG_TOUCH_THP_SUPPORT=1
KBUILD_OPTIONS += CONFIG_TOUCH_FOD_SUPPORT=1
KBUILD_OPTIONS += CONFIG_CMD_DATA_BUF_SIZE=1
endif

KBUILD_OPTIONS += TOUCH_ROOT=$(KERNEL_SRC)/$(M)/..
KBUILD_OPTIONS += TOUCHFEATURE_ROOT=$(KERNEL_SRC)/$(M)/..

DLKM_DIR := device/qcom/common/dlkm
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := xiaomi_touch.ko
LOCAL_MODULE_KBUILD_NAME := ../xiaomi/xiaomi_touch.ko
LOCAL_MODULE_DDK_BUILD := true
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := xiaomi
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
include $(DLKM_DIR)/Build_external_kernelmodule.mk

include $(CLEAR_VARS)
LOCAL_MODULE := focaltech_touch.ko
LOCAL_MODULE_KBUILD_NAME := focaltech_3683/focaltech_touch.ko
LOCAL_MODULE_DDK_BUILD := true
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_OWNER := xiaomi
LOCAL_MODULE_PATH := $(KERNEL_MODULES_OUT)
include $(DLKM_DIR)/Build_external_kernelmodule.mk
