TEMPLATE = subdirs
SUBDIRS = doc examples

docs.depends += examples

OTHER_FILES += README \
    rpm/sdk-user-manual.spec
