#!/bin/sh
set -eu
PREFIX="${1:-/opt/heirloom}"; PKG="${2:-vi}"
printf 'heirloom-vi-darwin status\n'
printf '  prefix: %s\n' "$PREFIX"
for b in ex vi; do
  if [ -x "$PREFIX/bin/$b" ]; then
    printf '  %s: installed\n' "$b"
  else
    printf '  %s: NOT installed\n' "$b"
  fi
done
MF=".install-manifest-$PKG.txt"
if [ -f "$MF" ]; then
  printf '  manifest: %s (%s entries)\n' "$MF" "$(wc -l < "$MF" | tr -d ' ')"
fi
