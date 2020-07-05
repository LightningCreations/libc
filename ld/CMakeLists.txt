
set(LCLIBC_LD_SYSROOT "${CMAKE_INSTALL_PREFIX}" CACHE PATH "Sets the sysroot for the searchpaths used by the dynamic linker")
set(LCLIBC_LD_DEFAULT_SEARCH_PATH /usr/local/lib /usr/lib /lib CACHE PATH "Sets the search directory and order for the default search path (IE. when ld.so.conf is unavailable)")

