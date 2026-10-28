#!/usr/bin/env bash
set -euo pipefail
repo_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
build_dir=${BUILD_DIR:-"$repo_dir/build"}
cmake_bin=${CMAKE:-cmake}
python_bin=${PYTHON:-python3}
"$cmake_bin" -S "$repo_dir" -B "$build_dir" -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
"$cmake_bin" --build "$build_dir" --parallel 2
"$build_dir/structure_tests"
"$python_bin" "$repo_dir/tests/cli.py" "$build_dir/data_structures_app"
