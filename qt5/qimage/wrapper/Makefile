QT_INCLUDE=/usr/include/x86_64-linux-gnu/qt5

LW_NAME                 = qimage
LW_DISPLAY_NAME         = 'QImage'
LW_PREFIX               = /opt/scorep-libwrap
LW_BACKEND              = 
LW_BACKEND_SUFFIX       = 
CPPFLAGS                = -fPIC -I${QT_INCLUDE}
LDFLAGS                 = -fPIC
LIBS                    = -lQt5Widgets -lQt5Gui -lQt5Core
SCOREP_CC               = g++
SCOREP_CC_WITHOUT_FLAGS = g++
LIBTOOL                 = /opt/scorep-libwrap/libexec/scorep/libtool
LIBTOOL_LDFLAGS         = 
INSTALL                 = /usr/bin/install -c

LW_GEN                  = /opt/scorep-libwrap/libexec/scorep/scorep-library-wrapper-generator
LW_SCOREP               = /opt/scorep-libwrap/bin/scorep
LW_LANGUAGE             = c++
LW_SRCEXT               = cc
LW_LIBTOOL_TAG          = CXX
LW_LIBLIST              =  libQt5Widgets.so libQt5Gui.so libQt5Core.so

SCOREP_CPPFLAGS         = -I/opt/scorep-libwrap/include -I/opt/scorep-libwrap/include/scorep 

LW_INIT_FLAGS           = 

# proxy targets to enable/disable making/installing/uninstalling linktime and runtime wrappers according to what score-p supports
ALL_LIBWRAP_LINKTIME          = all-libwrap-linktime
INSTALL_LIBWRAP_LINKTIME      = install-libwrap-linktime
INSTALLCHECK_LIBWRAP_LINKTIME = main_linktime_wrapped
UNINSTALL_LIBWRAP_LINKTIME    = uninstall-libwrap-linktime
ALL_LIBWRAP_RUNTIME          = all-libwrap-runtime
INSTALL_LIBWRAP_RUNTIME      = install-libwrap-runtime
INSTALLCHECK_LIBWRAP_RUNTIME = main_runtime_wrapped
UNINSTALL_LIBWRAP_RUNTIME    = uninstall-libwrap-runtime

### Variables to-be-set by scorep-libwrap-init ###
# LW_NAME
# LW_DISPLAY_NAME
# LW_PREFIX
# LW_BACKEND
# LW_BACKEND_SUFFIX
# CPPFLAGS
# LDFLAGS
# LIBS
# SCOREP_CC
# SCOREP_CC_WITHOUT_FLAGS
# LIBTOOL
# LIBTOOL_LDFLAGS
# INSTALL
#
# LW_GEN
# LW_SCOREP
# LW_LANGUAGE
# LW_SRCEXT
# LW_LIBTOOL_TAG
# LW_LIBLIST
#
# SCOREP_CPPFLAGS
#
# LW_INIT_FLAGS
#
# ALL_LIBWRAP_LINKTIME
# ALL_LIBWRAP_RUNTIME
# INSTALL_LIBWRAP_LINKTIME
# INSTALL_LIBWRAP_RUNTIME
# INSTALLCHECK_LIBWRAP_LINKTIME
# INSTALLCHECK_LIBWRAP_RUNTIME
# UNINSTALL_LIBWRAP_LINKTIME
# UNINSTALL_LIBWRAP_RUNTIME

# Add symbols to this variable, if they have no arguments, but `()` in their decl
LIBWRAP_VARIADIC_IS_VOID_SYMBOLS =

# Add symbols to this variable, to map ellipsis functions to their va_list-variant
# <ellipsis-symbol>:<val_list-variant-symbol>
LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS =

CPPFLAGS_PGI_WORKAROUND = -D__builtin_va_arg=__pgi_builtin_va_arg # workaround because clang thinks __builtin_va_arg is a keyword not a function and throws an error

LIBWRAP_LINKTIME        = libscorep_libwrap_$(LW_NAME)_linktime.la
LIBWRAP_LINKTIME_OBJECT = $(LIBWRAP_LINKTIME:.la=.lo)
LIBWRAP_RUNTIME         = libscorep_libwrap_$(LW_NAME)_runtime.la
LIBWRAP_RUNTIME_OBJECT  = $(LIBWRAP_RUNTIME:.la=.lo)

WRAP_LIB_SOURCE         = scorep_libwrap_$(LW_NAME).$(LW_SRCEXT)
WRAP_LIST_INC           = scorep_libwrap_$(LW_NAME).inc.c
LIBWRAP_ANCHOR_FILE     = $(LW_NAME).libwrap
LIBWRAP_SUMMARY_FILE    = $(LW_NAME).summary
WRAP_LD_FLAGS_FILE      = $(LW_NAME).wrap
NVCC_WRAP_LD_FLAGS_FILE = $(LW_NAME).nvcc.wrap
WRAP_FILTER_FILE        = $(LW_NAME).filter

### silent rules ###
LW_V_CC = $(lw__v_CC_$(V))
lw__v_CC_1 =
lw__v_CC_ = @echo "  CC       " $@;
LW_V_CCLD = $(lw__v_CCLD_$(V))
lw__v_CCLD_1 =
lw__v_CCLD_ = @echo "  CCLD     " $@;

LW_V_CXX = $(lw__v_CXX_$(V))
lw__v_CXX_1 =
lw__v_CXX_ = @echo "  CXX      " $@;
LW_V_CXXLD = $(lw__v_CXXLD_$(V))
lw__v_CXXLD_1 =
lw__v_CXXLD_ = @echo "  CXXLD    " $@;

LW_V_CPP = $(lw__v_CPP_$(V))
lw__v_CPP_1 =
lw__v_CPP_ = @echo "  CPP      " $@;

LW_V_P = $(lw__v_P_$(V))
lw__v_P_ = false
lw__v_P_1 = :

LW_V_GEN = $(lw__v_GEN_$(V))
lw__v_GEN_1 =
lw__v_GEN_ = @echo "  GEN      " $@;

LW_V_INSTALL = $(lw__v_INSTALL_$(V))
lw__v_INSTALL_1 =
lw__v_INSTALL_ = @echo "  INSTALL  " $<;

LW_V_libtool = $(lw__v_libtool_$(V))
lw__v_libtool_ = --silent
lw__v_libtool_1 =

LW_V_devnull = $(lw__v_devnull_$(V))
lw__v_devnull_ = >/dev/null 2>&1
lw__v_devnull_1 =

LW_V_SCOREP = $(lw__v_SCOREP_$(V))
lw__v_SCOREP_1 =
lw__v_SCOREP_ = @echo "  SCOREP   " $@;

LW_V_scorep = $(lw__v_scorep_$(V))
lw__v_scorep_1 = --verbose --keep-files
lw__v_scorep_ =

LW_V_lw_gen = $(lw__v_lw_gen_$(V))
lw__v_lw_gen_1 = --verbose
lw__v_lw_gen_ =

### all ###
.PHONY: all
all: main quick-check $(ALL_LIBWRAP_LINKTIME) $(ALL_LIBWRAP_RUNTIME)

.PHONY: all-libwrap-linktime
all-libwrap-linktime: $(LIBWRAP_LINKTIME)

.PHONY: all-libwrap-runtime
all-libwrap-runtime: $(LIBWRAP_RUNTIME)

### main ###
main: main.$(LW_SRCEXT)
	$(LW_V_CCLD)$(SCOREP_CC_WITHOUT_FLAGS) -o $@ $< $(CPPFLAGS) $(LDFLAGS) $(LIBS)

### preprocess ###
libwrap.i: libwrap.$(LW_SRCEXT) libwrap.h Makefile
	$(LW_V_CPP)$(SCOREP_CC_WITHOUT_FLAGS) -E $< $(CPPFLAGS) $(CPPFLAGS_PGI_WORKAROUND) > $@

### generate ###
$(WRAP_LIB_SOURCE): libwrap.i $(WRAP_FILTER_FILE)
	$(LW_V_GEN)$(LW_GEN) $(LW_V_lw_gen) -n $(LW_NAME) -d $(LW_DISPLAY_NAME) -h libwrap.i -i libwrap.h -x $(LW_LANGUAGE) -f $(WRAP_FILTER_FILE) -l "$(LW_LIBLIST)" --variadic-is-void "$(LIBWRAP_VARIADIC_IS_VOID_SYMBOLS)" --ellipsis-mapping "$(LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS)" --overwrite

### quick-check ###
.PHONY: quick-check
quick-check: $(WRAP_LIB_SOURCE)
	@( \
            echo "#ifdef __cplusplus"; \
            echo "extern \"C\" {"; \
            echo "#endif"; \
            echo ""; \
            while read flag symbol; do \
                test "$$flag" != -wrap && continue; \
                echo "char $$symbol();"; \
            done <$(WRAP_LD_FLAGS_FILE); \
            echo ""; \
            echo "#ifdef __cplusplus"; \
            echo "}"; \
            echo "#endif"; \
            echo ""; \
            echo "int main() {"; \
            echo "    char a = 0;"; \
            echo ""; \
            while read flag symbol; do \
                test "$$flag" != -wrap && continue; \
                echo "    a += $$symbol();"; \
            done <$(WRAP_LD_FLAGS_FILE); \
            echo ""; \
            echo "    return a;"; \
            echo "}"; \
        ) >symbol_quick_check.$(LW_SRCEXT)
	@if $(LW_V_P); then \
            echo "$(SCOREP_CC_WITHOUT_FLAGS) -o symbol_quick_check symbol_quick_check.$(LW_SRCEXT) $(CPPFLAGS) $(LDFLAGS) $(LIBS)"; \
        else \
            echo "  QUICK-CHECK"; \
        fi; \
        if ! $(SCOREP_CC_WITHOUT_FLAGS) -o symbol_quick_check symbol_quick_check.$(LW_SRCEXT) $(CPPFLAGS) $(LDFLAGS) $(LIBS) $(LW_V_devnull); then \
            echo >&2 "[Score-P] Error: There is mismatch between functions found in the header files"; \
            echo >&2 "[Score-P]        and the symbols present in the target library."; \
            echo >&2 "[Score-P]        Use 'make check' to get a list of missing symbols and add"; \
            echo >&2 "[Score-P]        them to $(WRAP_FILTER_FILE). After that repeat this step."; \
            rm -f symbol_quick_check symbol_quick_check.$(LW_SRCEXT); \
            exit 1; \
        else \
            rm -f symbol_quick_check symbol_quick_check.$(LW_SRCEXT); \
        fi

### libwrap linktime ###
$(LIBWRAP_LINKTIME_OBJECT): $(WRAP_LIB_SOURCE) $(WRAP_LIST_INC)
	$(LW_V_CC)$(LIBTOOL) $(LW_V_libtool) --tag=$(LW_LIBTOOL_TAG) --mode=compile $(SCOREP_CC) $(SCOREP_CPPFLAGS) $(CPPFLAGS) -DSCOREP_LIBWRAP_STATIC -c -o $@ $<

$(LIBWRAP_LINKTIME): $(LIBWRAP_LINKTIME_OBJECT)
	$(LW_V_CCLD)$(LIBTOOL) $(LW_V_libtool) --tag=$(LW_LIBTOOL_TAG) --mode=link $(SCOREP_CC) -avoid-version -rpath $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX) $(LIBTOOL_LDFLAGS) $(LDFLAGS) -Wl,@$(WRAP_LD_FLAGS_FILE) -o $@ $< $(LIBS)

### libwrap runtime ###
$(LIBWRAP_RUNTIME_OBJECT): $(WRAP_LIB_SOURCE) $(WRAP_LIST_INC)
	$(LW_V_CC)$(LIBTOOL) $(LW_V_libtool) --tag=$(LW_LIBTOOL_TAG) --mode=compile $(SCOREP_CC) $(SCOREP_CPPFLAGS) $(CPPFLAGS) -DSCOREP_LIBWRAP_SHARED -c -o $@ $<

$(LIBWRAP_RUNTIME): $(LIBWRAP_RUNTIME_OBJECT)
	$(LW_V_CCLD)$(LIBTOOL) $(LW_V_libtool) --tag=$(LW_LIBTOOL_TAG) --mode=link $(SCOREP_CC) -avoid-version -rpath $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX) $(LIBTOOL_LDFLAGS) $(LDFLAGS) -o $@ $< $(LIBS)

$(LIBWRAP_ANCHOR_FILE): Makefile
	$(LW_V_GEN)( \
	    printf "LIBWRAP_NAME=%s\n" $(LW_DISPLAY_NAME); \
	    echo "LIBWRAP_CC=$(SCOREP_CC)"; \
	    echo "LIBWRAP_BACKEND=$(LW_BACKEND)"; \
	    echo "LIBWRAP_LANGUAGE=$(LW_LANGUAGE)"; \
	    echo "LIBWRAP_CPPFLAGS=$(CPPFLAGS)"; \
	    echo "LIBWRAP_LDFLAGS=$(LDFLAGS)"; \
	    echo "LIBWRAP_LIBS=$(LIBS)"; \
	    echo "LIBWRAP_DLOPEN_LIBS=$(LW_LIBLIST)"; \
	    printf "LIBWRAP_VARIADIC_IS_VOID_SYMBOLS=%s\n" "$$(echo $(LIBWRAP_VARIADIC_IS_VOID_SYMBOLS))"; \
	    printf "LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS=%s\n" "$$(echo $(LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS))"; \
	    if test x"$${MODULESHOME:+set}" = x"set"; then \
	        echo "LIBWRAP_LOADEDMODULES=$$LOADEDMODULES"; \
	    fi; \
	) >$@

$(LIBWRAP_SUMMARY_FILE): Makefile
	$(LW_V_GEN)( \
	    backend=$(LW_BACKEND); \
	    echo "Configure command:"; \
	    printf "  scorep-libwrap-init           --name %s \\\\\n" $(LW_NAME); \
	    printf "                                --display-name '$$(echo $(LW_DISPLAY_NAME) | sed "s/'/'\\\\\\\\''/g")' \\\\\n"; \
	    printf "                                --prefix '%s' \\\\\n" $(LW_PREFIX); \
	    printf "                                -x %s \\\\\n" $(LW_LANGUAGE); \
	    printf "                                --backend %s \\\\\n" $${backend:-vanilla}; \
	    printf "                                --cppflags '$(CPPFLAGS)' \\\\\n"; \
	    printf "                                --ldflags '$(LDFLAGS)' \\\\\n"; \
	    printf "                                --libs '$(LIBS)'"; \
	    init_flags=$(LW_INIT_FLAGS); \
	    for init_flag in $$init_flags; do \
	        printf " \\\\\n                                '%s'" "$$init_flag"; \
	    done; \
	    printf "\n"; \
	    if test x"$${MODULESHOME:+set}" = x"set"; then \
	        echo; \
	        echo "Loaded modules:"; \
	        if test x"$${LOADEDMODULES:+set}" = x"set"; then \
	            prefix="  module load "; \
	            printf "%-32s" "$$prefix"; \
	            padding=$$(printf "%32s" ""); \
	            IFS=': ' eval 'set x $$LOADEDMODULES'; \
	            shift; \
	            sep=""; \
	            for module; do \
	                printf "$$sep%s" "$$module"; \
	                sep=" \\\\\n$$padding"; \
	            done; \
	            echo; \
	        else \
	            echo "  No modules loaded"; \
	        fi; \
	    fi; \
	) >$@

### check ###
# TODO maybe open the executable(s) with ldd and check whether all libraries (perhaps this should rather be part of the main target) can be found
.PHONY: check
check: $(WRAP_LIB_SOURCE)
	@wrap_count=$$(cat $(WRAP_LD_FLAGS_FILE) | wc -l); \
        if test $$wrap_count -ge 1000; then \
            echo >&2 "[Score-P] Warning: Checking $$wrap_count symbols. This may take a while."; \
        fi; \
        missing_symbols=""; \
        uncertain_symbols=""; \
        rm -f missing.filter uncertain.filter; \
        while read flag symbol; do \
            test "$$flag" != -wrap && continue; \
            ( \
                echo "#ifdef __cplusplus"; \
                echo 'extern "C"'; \
                echo "#endif"; \
                echo "char $$symbol();"; \
                echo "int main() { return $$symbol(); }"; \
            ) >symbol_check.$(LW_SRCEXT); \
            $(LW_V_P) && echo $(SCOREP_CC_WITHOUT_FLAGS) -o symbol_check symbol_check.$(LW_SRCEXT) $(CPPFLAGS) $(LDFLAGS) $(LIBS); \
            if $(SCOREP_CC_WITHOUT_FLAGS) -o symbol_check symbol_check.$(LW_SRCEXT) $(CPPFLAGS) $(LDFLAGS) $(LIBS) $(LW_V_devnull); then \
                $(LW_V_P) && echo $(SCOREP_CC_WITHOUT_FLAGS) -o symbol_check symbol_check.$(LW_SRCEXT) $(CPPFLAGS); \
                if $(SCOREP_CC_WITHOUT_FLAGS) -o symbol_check symbol_check.$(LW_SRCEXT) $(CPPFLAGS) $(LW_V_devnull); then \
                    echo "  UNCERTAIN $$symbol"; \
                    uncertain_symbols="$$uncertain_symbols $$symbol"; \
                else \
                    echo "  FOUND     $$symbol"; \
                fi; \
            else \
                echo "  MISSING   $$symbol"; \
                missing_symbols="$$missing_symbols $$symbol"; \
            fi; \
            rm -f symbol_check symbol_check.$(LW_SRCEXT); \
        done <$(WRAP_LD_FLAGS_FILE); \
        if test -n "$$uncertain_symbols"; then \
            echo >&2 "[Score-P] Warning: Symbols that are present without linking against the target"; \
            echo >&2 "[Score-P]          library and its dependencies have been wrapped. It is uncertain"; \
            echo >&2 "[Score-P]          whether calls to them can be intercepted, or perhaps you did"; \
            echo >&2 "[Score-P]          not intend to wrap them. The filter file 'uncertain.filter'"; \
            echo >&2 "[Score-P]          containing these symbols has been created. Maybe you want to"; \
            echo >&2 "[Score-P]          add all or some of these symbols to $(WRAP_FILTER_FILE)."; \
            echo >&2 "[Score-P]          Then repeat 'make' and 'make check'."; \
            ( \
                echo "SCOREP_REGION_NAMES_BEGIN"; \
                printf "     EXCLUDE MANGLED %s\n" $$uncertain_symbols; \
                echo "SCOREP_REGION_NAMES_END"; \
            ) >uncertain.filter; \
        fi; \
        if test -n "$$missing_symbols"; then \
            echo >&2 "[Score-P] Error: Symbols that are not present in the target library have been"; \
            echo >&2 "[Score-P]        wrapped. The filter file 'missing.filter' containing these"; \
            echo >&2 "[Score-P]        symbols has been created. Reconsider your wrapper settings, or"; \
            echo >&2 "[Score-P]        add these symbols to $(WRAP_FILTER_FILE) if they should not be"; \
            echo >&2 "[Score-P]        wrapped. Then repeat 'make' and 'make check'."; \
            ( \
                echo "SCOREP_REGION_NAMES_BEGIN"; \
                printf "     EXCLUDE MANGLED %s\n" $$missing_symbols; \
                echo "SCOREP_REGION_NAMES_END"; \
            ) >missing.filter; \
            exit 1; \
        fi

### install ###
.PHONY: install
install: quick-check $(LIBWRAP_ANCHOR_FILE) $(LIBWRAP_SUMMARY_FILE) $(WRAP_FILTER_FILE) $(INSTALL_LIBWRAP_LINKTIME) $(INSTALL_LIBWRAP_RUNTIME)
	@mkdir -p $(LW_PREFIX)/share/scorep
	@data_files='$(LIBWRAP_ANCHOR_FILE) $(LIBWRAP_SUMMARY_FILE) $(WRAP_LD_FLAGS_FILE) $(NVCC_WRAP_LD_FLAGS_FILE) $(WRAP_FILTER_FILE)'; \
	for data_file in $$data_files; do \
	    if $(LW_V_P); then echo $(INSTALL) -m 644 "$$data_file" "$(LW_PREFIX)/share/scorep/$$data_file"; \
	                  else echo "  INSTALL   $$data_file"; \
	    fi; \
	    $(INSTALL) -m 644 "$$data_file" "$(LW_PREFIX)/share/scorep/$$data_file"; \
	done

.PHONY: install-libwrap-linktime
install-libwrap-linktime: $(LIBWRAP_LINKTIME)
	@mkdir -p $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)
	$(LW_V_INSTALL)$(LIBTOOL) $(LW_V_libtool) --mode=install $(INSTALL) $(LIBWRAP_LINKTIME) $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)/$(LIBWRAP_LINKTIME)

.PHONY: install-libwrap-runtime
install-libwrap-runtime: $(LIBWRAP_RUNTIME)
	@mkdir -p $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)
	$(LW_V_INSTALL)$(LIBTOOL) $(LW_V_libtool) --mode=install $(INSTALL) $(LIBWRAP_RUNTIME) $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)/$(LIBWRAP_RUNTIME)
	@if test -z "$(LW_LIBLIST)"; then \
            echo "[Score-P] Error: Could not find any shared libraries. I.e. the"; \
            echo "[Score-P]        LW_LIBLIST variable in Makefile is empty!"; \
            echo "[Score-P]        This can lead to a broken runtime library wrapper."; \
            echo "[Score-P]        If one of the libraries specified via '--libs'"; \
            echo "[Score-P]        (Which is the same as the LIBS variable in Makefile)"; \
            echo "[Score-P]        is not installed as a shared library, you should"; \
            echo "[Score-P]        switch off runtime wrapping by first running"; \
            echo "[Score-P]        'make uninstall clean', and then reinitializing the"; \
            echo "[Score-P]        working directory by adding"; \
            echo "[Score-P]        '--update --static-only-target-library' to your"; \
            echo "[Score-P]        'scorep-libwrap-init'-command line."; \
            exit 1; \
        fi

### installcheck ###

main_linktime_wrapped: main.$(LW_SRCEXT) $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)/$(LIBWRAP_LINKTIME)
	$(LW_V_SCOREP)( \
	    export SCOREP_LIBWRAP_PATH=$(LW_PREFIX); \
	    $(LW_SCOREP) $(LW_V_scorep) --libwrap=linktime:$(LW_NAME) $(SCOREP_CC_WITHOUT_FLAGS) $(CPPFLAGS) $< $(LDFLAGS) $(LIBS) -o $@; \
	)

main_runtime_wrapped: main.$(LW_SRCEXT) $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)/$(LIBWRAP_RUNTIME)
	$(LW_V_SCOREP)( \
	    export SCOREP_LIBWRAP_PATH=$(LW_PREFIX); \
	    $(LW_SCOREP) $(LW_V_scorep) --libwrap=runtime:$(LW_NAME) $(SCOREP_CC_WITHOUT_FLAGS) $(CPPFLAGS) $< $(LDFLAGS) $(LIBS) -o $@; \
	)

.PHONY: installcheck
installcheck: $(INSTALLCHECK_LIBWRAP_LINKTIME) $(INSTALLCHECK_LIBWRAP_RUNTIME)
	@echo "[Score-P] To further check, please execute the generated binaries:"
	@echo "[Score-P]"
	@for binary in $^; do \
	    printf '[Score-P]     $$ ./%s\n' $$binary; \
	done
	@echo "[Score-P]"
	@echo "[Score-P] If available, verify the output via:"
	@echo "[Score-P]"
	@echo "[Score-P]     $$ cube_info -m visits:excl scorep-*/profile.cubex"
	@echo "[Score-P]"
	@echo "[Score-P] It should display numbers you would expect from intercepting"
	@echo "[Score-P] main.c's calls to the target library."

### uninstall ###
.PHONY: uninstall
uninstall: $(UNINSTALL_LIBWRAP_LINKTIME) $(UNINSTALL_LIBWRAP_RUNTIME)
	@rm -f $(LW_PREFIX)/share/scorep/$(LIBWRAP_ANCHOR_FILE)
	@rm -f $(LW_PREFIX)/share/scorep/$(LIBWRAP_SUMMARY_FILE)
	@rm -f $(LW_PREFIX)/share/scorep/$(WRAP_LD_FLAGS_FILE)
	@rm -f $(LW_PREFIX)/share/scorep/$(NVCC_WRAP_LD_FLAGS_FILE)
	@rm -f $(LW_PREFIX)/share/scorep/$(WRAP_FILTER_FILE)

.PHONY: uninstall-libwrap-linktime
uninstall-libwrap-linktime:
	@$(LIBTOOL) $(LW_V_libtool) --mode=uninstall rm -f $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)/$(LIBWRAP_LINKTIME)

.PHONY: uninstall-libwrap-runtime
uninstall-libwrap-runtime:
	@$(LIBTOOL) $(LW_V_libtool) --mode=uninstall rm -f $(LW_PREFIX)/lib$(LW_BACKEND_SUFFIX)/$(LIBWRAP_RUNTIME)

### clean ###
.PHONY: clean
clean:
	@rm -f main libwrap.i $(WRAP_LIB_SOURCE) $(WRAP_LIST_INC) $(LIBWRAP_ANCHOR_FILE) $(LIBWRAP_SUMMARY_FILE) $(WRAP_LD_FLAGS_FILE) $(NVCC_WRAP_LD_FLAGS_FILE) $(INSTALLCHECK_LIBWRAP_LINKTIME) $(INSTALLCHECK_LIBWRAP_RUNTIME)
	@$(LIBTOOL) $(LW_V_libtool) --mode=clean rm -f $(LIBWRAP_LINKTIME) $(LIBWRAP_LINKTIME_OBJECT) $(LIBWRAP_RUNTIME) $(LIBWRAP_RUNTIME_OBJECT)

### show libwrap-init command ###
.PHONY: show-summary
show-summary: $(LIBWRAP_SUMMARY_FILE)
	@cat $(LIBWRAP_SUMMARY_FILE)
