#!/bin/sh
set -eu
PREFIX="${1:-/opt/heirloom}"
BUILD_DIR="${2:-build/ritter_vi}"
mkdir -p "$PREFIX/bin" "$PREFIX/share/man/5man/man1"
for b in ex vi; do
  if [ -f "$BUILD_DIR/$b" ]; then
    install -c -m 0755 "$BUILD_DIR/$b" "$PREFIX/bin/$b"
    printf '  installed %s\n' "$PREFIX/bin/$b"
  else
    printf '  missing %s (build did not complete)\n' "$b" >&2
  fi
done
for m in "$BUILD_DIR"/*.1 "$BUILD_DIR"/vi.1 "$BUILD_DIR"/ex.1; do
  [ -f "$m" ] || continue
  install -c -m 0644 "$m" "$PREFIX/share/man/5man/man1/$(basename "$m")"
done
