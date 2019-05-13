TEMPLATE = aux

CONFIG += mer-qdoc-template
MER_QDOC.project = sdk-user-manual
MER_QDOC.config = config/sdk-user-manual.qdocconf
MER_QDOC.style = offline
MER_QDOC.path = /usr/share/doc/sdk-user-manual

OTHER_FILES += \
    $$PWD/config/*.qdocconf \
    $$PWD/config/style/*.css \
    $$PWD/config/images/*.png \
    $$PWD/config/sdk-user-manual.qdocconf \
    $$PWD/src/*.qdoc
