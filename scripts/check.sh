#!/usr/bin/env bash
set -euo pipefail
repo_dir=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)
build_dir=${BUILD_DIR:-"$repo_dir/../labstruct-build"}
cmake_bin=${CMAKE:-cmake}
go_bin=${GO:-go}
python_bin=${PYTHON:-python3}
"$cmake_bin" -S "$repo_dir" -B "$build_dir" -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTING=ON
"$cmake_bin" --build "$build_dir" --parallel 2
"$build_dir/structure_tests"
"$python_bin" "$repo_dir/tests/cli.py" "$build_dir/data_structures_app"
(
    cd "$repo_dir/go"
    export GOTOOLCHAIN=local
    "$go_bin" test ./...
    "$go_bin" build -o "$build_dir/labstruct-go" .
)
"$python_bin" "$repo_dir/tests/cli.py" "$build_dir/labstruct-go" --go
"$python_bin" "$repo_dir/tests/interop.py" "$build_dir/data_structures_app" "$build_dir/labstruct-go"
