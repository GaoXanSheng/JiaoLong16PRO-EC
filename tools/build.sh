#!/bin/sh
# Linux/macOS 构建入口，等价于 python3 tools/build.py
exec python3 "$(dirname "$0")/build.py" "$@"
