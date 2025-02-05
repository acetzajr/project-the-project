#!/bin/bash
START=$(./scripts/millis.sh)
dirs=("gtg")
for dir in "${dirs[@]}"; do
  echo "-- Formatting $dir"
  find "$dir" -type f \( -name "*.c" -o -name "*.h" \) \
  -exec ./scripts/format.sh {} \; 2>/dev/null
done
END=$(./scripts/millis.sh)
echo "## Formatting time: $(($END - $START)) milliseconds"
