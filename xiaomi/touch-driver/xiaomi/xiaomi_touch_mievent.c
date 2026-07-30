// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2024 Xiaomi, Inc.
 */

#include <linux/module.h>
#include <linux/ratelimit.h>

#include "xiaomi_touch.h"

/*
 * Stock forwards these records to Xiaomi's unpublished MiEvent service.
 * Preserve the touch ABI without making panel probe depend on that service.
 */
void xiaomi_touch_mievent_report_int(int event_id, int touch_id,
				    const char *module, const char *key,
				    long value)
{
	pr_warn_ratelimited("xiaomi-touch: event=%d touch=%d module=%s key=%s value=%ld\n",
			    event_id, touch_id, module ?: "", key ?: "", value);
}
EXPORT_SYMBOL_GPL(xiaomi_touch_mievent_report_int);

void xiaomi_touch_mievent_report_str(int event_id, int touch_id,
				    const char *module, const char *value)
{
	pr_warn_ratelimited("xiaomi-touch: event=%d touch=%d module=%s value=%s\n",
			    event_id, touch_id, module ?: "", value ?: "");
}
EXPORT_SYMBOL_GPL(xiaomi_touch_mievent_report_str);
