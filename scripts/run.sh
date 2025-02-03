#!/bin/bash
if ! ./scripts/build.sh; then
  exit 1
fi
START=$(./scripts/seconds.sh)
./build/bin/$1
END=$(./scripts/seconds.sh)
echo "## Running time: $(($END - $START)) seconds"