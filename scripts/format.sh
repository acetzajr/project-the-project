#/bin/bash
STYLE=GNU
if ! clang-format --Werror --dry-run --style=$STYLE $1 2>/dev/null; then
    clang-format -i --style=$STYLE $1
    echo "  * $1"
fi