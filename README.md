quack_like_a_duck
=================

Project that demonstrates how to wrap a C structure into a hidden implementation structure
and use allocation functions conditionally.

Proviso is, that for internal implementations we want to use vanilla malloc family calls, 
but for external calls we expose MALLOC and
CALLOC macros that will resolve to internal implementations or vanilla implementations
depending on whether you compile with a -DDEBUG flag.
