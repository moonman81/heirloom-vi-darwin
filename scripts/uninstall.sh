#!/bin/sh
set -eu
PREFIX="${1:-/opt/heirloom}"; PKG="${2:-vi}"
MF=".install-manifest-$PKG.txt"
[ -f "$MF" ] || { printf 'no manifest %s\n' "$MF" >&2; exit 1; }
while IFS= read -r f; do
  [ -f "$f" ] && rm -f "$f" && printf '  removed %s\n' "$f"
done < "$MF"
rm -f "$MF"
