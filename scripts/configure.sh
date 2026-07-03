#!/bin/sh
set -eu
UPSTREAM="${1:-vendor/ritter_vi.tar.gz}"
if [ ! -f "$UPSTREAM" ]; then
  printf 'heirloom-vi-darwin: configure — MISSING %s\n' "$UPSTREAM" >&2
  printf '  Fetch it under your own licence reading from:\n' >&2
  printf '    https://www.tuhs.org/Archive/Applications/Ritter_Vi/2000/ritter_vi.tar.gz\n' >&2
  printf '  Then place at %s and re-run.\n' "$UPSTREAM" >&2
  exit 2
fi
printf 'heirloom-vi-darwin: configure — upstream present at %s\n' "$UPSTREAM"
printf '  SHA-256: %s\n' "$(shasum -a 256 "$UPSTREAM" | awk '{print $1}')"
