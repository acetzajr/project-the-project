#!/bin/bash
if ! ./scripts/configure.sh; then
  exit 1
fi
START=$(./scripts/millis.sh)
if ! cmake --build build --config Debug --target all; then
  exit 1
fi
END=$(./scripts/millis.sh)
echo "## Build time: $(($END - $START)) milliseconds"