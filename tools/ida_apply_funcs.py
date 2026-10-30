import csv
from pathlib import Path

import ida_funcs
import ida_name

FUNCTIONS_CSV = Path(__file__).resolve().parent.parent / "build" / "analysis" / "functions.csv"


def ea_of(region, addr):
    if region in (0, 1):
        return addr
    if region == 2:
        return 0x10000 + (addr - 0x8000)
    return 0x18000 + (addr - 0x8000)


applied = 0
failed = 0
with open(FUNCTIONS_CSV, newline="") as fh:
    for row in csv.DictReader(fh):
        ea = ea_of(int(row["region"]), int(row["address"], 16))
        try:
            if not ida_funcs.get_func(ea):
                ida_funcs.add_func(ea)
            ida_name.set_name(ea, row["name"], ida_name.SN_NOWARN | ida_name.SN_FORCE)
            applied += 1
        except Exception:
            failed += 1
print("applied", applied, "failed", failed)
