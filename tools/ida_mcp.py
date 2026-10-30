#!/usr/bin/env python3
import json
import sys
import urllib.request

URL = "http://127.0.0.1:13337/mcp"


def call(name, args=None, rid=1):
    body = json.dumps({
        "jsonrpc": "2.0",
        "id": rid,
        "method": "tools/call",
        "params": {"name": name, "arguments": args or {}},
    }).encode()
    req = urllib.request.Request(URL, data=body, headers={
        "Content-Type": "application/json",
        "Accept": "application/json, text/event-stream",
    })
    with urllib.request.urlopen(req, timeout=120) as resp:
        raw = resp.read().decode()
    try:
        data = json.loads(raw)
    except json.JSONDecodeError:
        for line in raw.splitlines():
            if line.startswith("data:"):
                data = json.loads(line[5:].strip())
                break
        else:
            raise
    result = data.get("result", data)
    content = result.get("content") if isinstance(result, dict) else None
    if content:
        parts = []
        for item in content:
            if item.get("type") == "text":
                parts.append(item.get("text", ""))
            else:
                parts.append(json.dumps(item))
        return "\n".join(parts)
    return json.dumps(result, ensure_ascii=False)


if __name__ == "__main__":
    tool = sys.argv[1]
    args = json.loads(sys.argv[2]) if len(sys.argv) > 2 else {}
    print(call(tool, args))
