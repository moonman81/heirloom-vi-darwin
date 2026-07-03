# GNUmakefile — heirloom-vi-darwin ALM wrapper
#
# GNU make prefers GNUmakefile over makefile, so this file takes
# precedence.  Targets follow the same shape as the other five
# heirloom-*-darwin repos.

SHELL     = /bin/sh
PREFIX   ?= /opt/heirloom
PKG      ?= vi
TITLE    ?= Ritter ex/vi (2.11BSD 3.7 lineage)

# The upstream tarball must be dropped here by the user.  See README.md.
UPSTREAM_TARBALL ?= vendor/ritter_vi.tar.gz
UPSTREAM_DIR     ?= build/ritter_vi

ROOT     ?=

# Colour output if attached to a tty.
ifeq ($(shell tty >/dev/null 2>&1 && echo yes),yes)
  C_BOLD  := \033[1m
  C_OK    := \033[32m
  C_WARN  := \033[33m
  C_FAIL  := \033[31m
  C_RESET := \033[0m
endif

.PHONY: help
help:
	@printf '$(C_BOLD)heirloom-vi-darwin$(C_RESET) — ALM targets\n\n'
	@printf '  %-16s %s\n' 'bootstrap'  'install brew + heirloom prerequisites'
	@printf '  %-16s %s\n' 'configure'  'verify upstream tarball present + prep'
	@printf '  %-16s %s\n' 'patch'      'extract vendor/ritter_vi.tar.gz + apply patches/'
	@printf '  %-16s %s\n' 'build'      'compile ex + vi'
	@printf '  %-16s %s\n' 'install'    'install into $$(ROOT)$$(PREFIX)'
	@printf '  %-16s %s\n' 'verify'     'smoke-test the installed binaries'
	@printf '  %-16s %s\n' 'uninstall'  'remove installed files per manifest'
	@printf '  %-16s %s\n' 'clean'      'remove build tree'
	@printf '  %-16s %s\n' 'distclean'  'clean + remove extracted upstream'
	@printf '  %-16s %s\n' 'help'       'print this help'
	@printf '\n'
	@printf 'You must obtain $$(UPSTREAM_TARBALL) from the TUHS Archive\n'
	@printf 'before running any of the above.  See README.md.\n'

.PHONY: bootstrap
bootstrap:
	@sh scripts/bootstrap.sh

.PHONY: configure
configure:
	@sh scripts/configure.sh '$(UPSTREAM_TARBALL)'

.PHONY: patch
patch: $(UPSTREAM_DIR)/Makefile
$(UPSTREAM_DIR)/Makefile:
	@sh scripts/apply-patches.sh '$(UPSTREAM_TARBALL)' '$(UPSTREAM_DIR)'

.PHONY: build all
build all: patch
	@printf '$(C_BOLD)build$(C_RESET) — compiling ex + vi in $(UPSTREAM_DIR)\n'
	@$(MAKE) -C $(UPSTREAM_DIR) CC=cc EXTRA_CFLAGS='-I../../compat -D_DARWIN_C_SOURCE' -k || \
		printf '$(C_WARN)build did not complete cleanly; check output$(C_RESET)\n'

.PHONY: install
install: build
	@sh scripts/install.sh '$(ROOT)$(PREFIX)' '$(UPSTREAM_DIR)'
	@sh scripts/write-manifest.sh '$(PREFIX)' '$(PKG)'

.PHONY: verify
verify:
	@sh scripts/verify.sh '$(PREFIX)'

.PHONY: uninstall
uninstall:
	@sh scripts/uninstall.sh '$(PREFIX)' '$(PKG)'

.PHONY: status
status:
	@sh scripts/status.sh '$(PREFIX)' '$(PKG)'

.PHONY: clean
clean:
	rm -rf build/

.PHONY: distclean
distclean: clean
	rm -f .install-manifest-$(PKG).txt
