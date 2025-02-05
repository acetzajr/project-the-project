#!/bin/bash
START=$(./scripts/millis.sh)
dirs=("gtg")
for dir in "${dirs[@]}"; do
  echo "Formatting files in: $dir"
  # Find and format .c/.h files (exclude build/ if needed)
  find "$dir" -type f \( -name "*.c" -o -name "*.h" \) -exec clang-format -i {} \; 2>/dev/null
done
END=$(./scripts/millis.sh)
echo "## Formatting time: $(($END - $START)) milliseconds"
