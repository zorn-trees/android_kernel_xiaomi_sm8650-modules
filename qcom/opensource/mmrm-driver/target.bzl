load(":mmrm_modules.bzl", "mmrm_driver_modules")
load(":mmrm_modules_build.bzl", "define_consolidate_gki_modules")

def define_pineapple(target = "pineapple"):
    define_consolidate_gki_modules(
        target = target,
        registry = mmrm_driver_modules,
        modules = [
            "msm-mmrm"
        ],
)
