#!/bin/bash
./scripts/format-all.sh
START=$(./scripts/millis.sh)
if ! cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON; then
  exit 1
fi
END=$(./scripts/millis.sh)
echo "## Configuration time: $(($END - $START)) milliseconds"