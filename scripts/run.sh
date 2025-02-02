#!/bin/bash
if ! ./scripts/build.sh; then
  exit 1
fi
./build/bin/$1