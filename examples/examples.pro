TEMPLATE = subdirs
SUBDIRS += example01 \
    example-others/example02.pro \
    example-others/example03.pro \
    example-others/example04.pro \
    example-others/example05.pro \
    example-others/example06.pro \
    example-others/example07.pro \
    example08 \
    example09 \
    example10 \
    example-others/example11.pro \
    example-others/example12.pro \
    example-others/example13.pro

# The pre-built shared libraries used for example08 are built by example09, so
# we need to build example09 before building example08.
example08.depends += example09
