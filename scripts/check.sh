#!/usr/bin/env bash
set -euo pipefail
repo_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
cd "$repo_dir"
export GOTOOLCHAIN=local
"${GO:-go}" test ./...
"${GO:-go}" build -o build/labstruct .
"${PYTHON:-python3}" tests/cli.py build/labstruct --go
