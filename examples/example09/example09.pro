TEMPLATE = subdirs
SUBDIRS = \
    harbour-demo-app \
    libdemo

harbour-demo-app.depends = libdemo

OTHER_FILES += rpm/*
