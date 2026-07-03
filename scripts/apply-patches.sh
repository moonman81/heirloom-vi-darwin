#!/bin/sh
set -eu
UPSTREAM="$1"
BUILD_DIR="$2"
if [ ! -f "$UPSTREAM" ]; then
  printf 'heirloom-vi-darwin: apply-patches — MISSING %s\n' "$UPSTREAM" >&2
  exit 2
fi
mkdir -p "$BUILD_DIR"
printf '  extracting %s -> %s\n' "$UPSTREAM" "$BUILD_DIR"
tar xzf "$UPSTREAM" -C "$BUILD_DIR"
# Copy compat shim into extracted tree
cp -f compat/*.h "$BUILD_DIR"/ 2>/dev/null || true
# Apply patches in order
for p in patches/*.patch; do
  [ -f "$p" ] || continue
  printf '  applying %s\n' "$p"
  (cd "$BUILD_DIR" && patch -p1 -N -r - < "../../$p") || {
    printf '    !!! patch failed, continuing (may already be applied)\n' >&2
  }
done
printf '  patched tree in %s\n' "$BUILD_DIR"
