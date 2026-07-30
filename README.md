# Xiaomi Zorn SM8650 external kernel modules

This repository consolidates the external kernel module sources used by the
Zorn kernel build. It is intended to be checked out at
`kernel/xiaomi/sm8650-modules`.

## Imported source snapshots

The initial repository tree was assembled from these depth-1 source snapshots:

| Path | Upstream revision |
|---|---|
| `qcom/opensource/wlan` | MiCode `vendor_qcom_opensource_wlan` at `9334caee227fadf339b03fe1f2f53875305f6ed8` |
| `qcom/opensource/dataipa` | CodeLinaro `LA.VENDOR.14.3.0.r1-14500-lanai.0` at `c40698e6116eb4f3792c2af7053dae8a5886dec2` |
| `qcom/opensource/datarmnet` | CodeLinaro `LA.VENDOR.14.3.0.r1-14500-lanai.0` at `c5d70f15d54c8489bd452d52729bcfcd301ab985` |
| `qcom/opensource/datarmnet-ext` | CodeLinaro `LA.VENDOR.14.3.0.r1-14500-lanai.0` at `a167b03697bd705f21374e8873ef7c0b26b562b4` |
| `qcom/opensource/securemsm-kernel` | CodeLinaro `LA.VENDOR.14.3.0.r1-14500-lanai.0` at `2300cfc8ccb68255a3e218f7a27682a573351231` |
| `xiaomi/touch-driver` | MiCode `vendor_xiaomi_proprietary_touch-driver` at `c286ab85f4982c9b5967e18405f4e2da0332ce4d` |

The imported snapshots are represented by one root commit because unrelated
shallow histories cannot be combined into a new repository without either
rewriting their roots or depending on missing parent objects. The exact source
revisions above preserve the provenance of every imported subtree.

The active development branch is `lineage-23.2`.
