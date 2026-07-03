#!/bin/sh
set -eu
PREFIX="${1:-/opt/heirloom}"
ok=0; fail=0
for b in ex vi; do
  if [ -x "$PREFIX/bin/$b" ]; then
    if "$PREFIX/bin/$b" -c q < /dev/null >/dev/null 2>&1; then
      printf '  %s: OK\n' "$b"; ok=$((ok+1))
    else
      printf '  %s: launched but exited non-zero\n' "$b"; fail=$((fail+1))
    fi
  else
    printf '  %s: NOT INSTALLED\n' "$b"; fail=$((fail+1))
  fi
done
printf 'ok=%d fail=%d\n' "$ok" "$fail"
[ "$fail" = "0" ]
