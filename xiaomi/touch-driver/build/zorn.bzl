load(":touch_modules.bzl", "touch_driver_modules")
load(":touch_modules_build.bzl", "define_target_variant_modules")

def define_zorn():
    module_config_options = {
        "xiaomi_touch": [
            "TOUCH_FOD_SUPPORT",
            "TOUCH_THP_SUPPORT",
        ],
        "focaltech_touch_zorn": [
            "TOUCH_FOD_SUPPORT",
            "TOUCH_GESTURE_ALWAYSON_SUPPORT",
            "TOUCH_THP_SUPPORT",
        ],
    }
    define_target_variant_modules(
        target = "zorn",
        device = "zorn",
        variant = "gki",
        registry = touch_driver_modules,
        modules = [
            "xiaomi_touch",
            "focaltech_touch_zorn",
        ],
        module_config_options = module_config_options,
    )
