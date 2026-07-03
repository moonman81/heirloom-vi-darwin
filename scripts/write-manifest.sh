#!/bin/sh
set -eu
PREFIX="$1"
PKG="$2"
MF=".install-manifest-$PKG.txt"
{
  for b in ex vi; do
    [ -f "$PREFIX/bin/$b" ] && printf '%s\n' "$PREFIX/bin/$b"
  done
  find "$PREFIX/share/man/5man/man1" -name 'vi.1' -o -name 'ex.1' 2>/dev/null
} > "$MF"
printf 'manifest written: %s (%s entries)\n' "$MF" "$(wc -l < "$MF" | tr -d ' ')"
