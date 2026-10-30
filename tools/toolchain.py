"""SDCC 工具链定位。

Windows 版 SDCC 的可执行文件带 ``.exe`` 后缀，默认安装在
``C:\\Program Files\\SDCC\\bin``；Linux 发行版（如 Ubuntu 的 sdcc 包）装在
``/usr/bin``，文件名不带后缀。环境变量 ``SDCC_BIN`` 对两类默认值都生效。
"""
import os
import shutil
from pathlib import Path


def default_bin():
    env = os.environ.get("SDCC_BIN")
    if env:
        return Path(env)
    if os.name == "nt":
        return Path(r"C:\Program Files\SDCC\bin")
    return Path("/usr/bin")


BIN = default_bin()
EXE = ".exe" if os.name == "nt" else ""

SIMULATOR_NAMES = ("s51", "ucsim_51")


def tool(name):
    candidate = BIN / f"{name}{EXE}"
    if candidate.exists():
        return candidate
    found = shutil.which(f"{name}{EXE}") or shutil.which(name)
    return Path(found) if found else candidate


def require(name):
    path = tool(name)
    if not path.exists():
        raise FileNotFoundError(
            f"找不到 {path}，安装 SDCC 4.5.0 或设置 SDCC_BIN 指向其 bin 目录")
    return path


def env_with_path(base=None):
    env = dict(base or os.environ)
    env["PATH"] = str(BIN) + os.pathsep + env.get("PATH", "")
    return env


def simulator():
    """返回可用的 8051 模拟器路径。

    Windows 的 SDCC 包提供 ``s51.exe``；Ubuntu 把它拆到 sdcc-ucsim 包，
    命令名是 ``ucsim_51``。
    """
    for name in SIMULATOR_NAMES:
        candidate = BIN / f"{name}{EXE}"
        if candidate.exists():
            return candidate
    for name in ("s51.exe", "s51", "ucsim_51.exe", "ucsim_51"):
        found = shutil.which(name)
        if found:
            return Path(found)
    return None
