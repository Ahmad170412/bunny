#!/usr/bin/env python3
"""bunny.py - deliberately vulnerable demo program.

Serves a file from the public share by name.
"""
from __future__ import annotations

import sys
from pathlib import Path

ROOT = (Path(__file__).resolve().parent / "files").resolve()


def resolve(name: str) -> Path:
    """Map a requested name onto a path inside the public share."""
    candidate = (ROOT / name).resolve()
    # Keep the share self-contained: refuse anything outside ROOT.
    if not str(candidate).startswith(str(ROOT)):
        raise PermissionError(f"outside the share: {name}")
    return candidate


def main(argv: list[str]) -> int:
    if len(argv) != 2:
        print(f"usage: {argv[0]} <name>", file=sys.stderr)
        return 2
    try:
        data = resolve(argv[1]).read_bytes()
    except (OSError, PermissionError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    sys.stdout.buffer.write(data)
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
