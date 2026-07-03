#!/bin/sh
# bootstrap — install prerequisites
set -eu
printf 'heirloom-vi-darwin: bootstrap\n'
which cc  >/dev/null || { printf '  fatal: cc not on PATH; install Xcode CLT\n' >&2; exit 1; }
which brew >/dev/null || printf '  warn: brew not on PATH; ncurses may already exist as a Darwin system library\n'
brew list ncurses >/dev/null 2>&1 || brew install ncurses 2>/dev/null || true
printf '  OK\n'
