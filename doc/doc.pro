TEMPLATE = aux

CONFIG += mer-qdoc-template
MER_QDOC.project = sdk-user-manual
MER_QDOC.config = sdk-user-manual.qdocconf
MER_QDOC.style = offline
MER_QDOC.path = /usr/share/doc/sdk-user-manual/

OTHER_FILES += \
    $$PWD/sdk-user-manual.qdocconf \
    $$PWD/index.qdoc

