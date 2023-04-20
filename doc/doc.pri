CONFIG += sailfish-qdoc-template
SAILFISH_QDOC.project = sdk-user-manual
SAILFISH_QDOC.config = sdk-user-manual.qdocconf
SAILFISH_QDOC.style = offline
SAILFISH_QDOC.path = /usr/share/doc/sdk-user-manual

OTHER_FILES += \
    sdk-user-manual.qdocconf \
    src/*.qdoc
