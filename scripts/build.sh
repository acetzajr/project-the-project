#!/bin/bash
if ! ./scripts/configure.sh; then
  exit 1
fi
if ! cmake --build build --config Debug --target all --parallel 4; then
  exit 1
fi