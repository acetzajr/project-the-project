#/bin/bash
if ! clang-format --Werror --dry-run --style=LLVM $1 2>/dev/null; then
    clang-format -i --style=LLVM $1
    echo "Formatting $1"
fi