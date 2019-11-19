TEMPLATE = subdirs
SUBDIRS = examples

include(doc/doc.pri)

OTHER_FILES += README \
    rpm/sdk-user-manual.spec
