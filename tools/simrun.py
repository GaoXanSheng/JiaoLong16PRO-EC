"""8051 模拟器调用封装。

Windows 的 SDCC 包用 ``s51.exe``；Ubuntu 把模拟器拆到 sdcc-ucsim 包，命令名是
``ucsim_51``。ucsim 的命令回显和 dump 输出来自不同线程，一次性喂完整段脚本时
两路输出会字符级交错，把 dump 行拼坏。这里逐条喂入并留出输出时间。
"""
import subprocess
import threading
import time

from toolchain import simulator

# 每条命令后等待的秒数，足够 ucsim 打印完一整页 dump
PACE = 0.25


def run_simulator(commands, timeout=120):
    sim = simulator()
    if sim is None:
        raise RuntimeError("未找到 8051 模拟器（s51 或 ucsim_51）")

    proc = subprocess.Popen([str(sim), "-q"], stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                            text=True, encoding="utf-8", errors="replace")
    output = []

    def pump():
        for line in proc.stdout:
            output.append(line)

    reader = threading.Thread(target=pump, daemon=True)
    reader.start()
    try:
        for command in commands:
            if proc.poll() is not None:
                break
            try:
                proc.stdin.write(command + "\n")
                proc.stdin.flush()
            except BrokenPipeError:
                break
            time.sleep(PACE)
        proc.stdin.close()
        proc.wait(timeout=timeout)
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()
        raise
    finally:
        reader.join(timeout=5)
        if proc.stdin and not proc.stdin.closed:
            proc.stdin.close()
        if proc.stdout:
            proc.stdout.close()
    return "".join(output)
