CONFIG += mer-qdoc-template
MER_QDOC.project = sdk-user-manual
MER_QDOC.config = doc/sdk-user-manual.qdocconf
MER_QDOC.style = offline
MER_QDOC.path = /usr/share/doc/sdk-user-manual

OTHER_FILES += \
    doc/sdk-user-manual.qdocconf \
    doc/src/*.qdoc
