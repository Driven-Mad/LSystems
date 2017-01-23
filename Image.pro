######################################################################
# Automatically generated by qmake (2.01a) Thu Jan 24 19:42:29 2013
######################################################################

TARGET = Image

OBJECTS_DIR=obj

QT+=gui opengl core

isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}

MOC_DIR=moc

CONFIG -= app_bundle

CONFIG+=c++11
# Input
SOURCES += src/main.cpp \
           src/Image.cpp \
    src/lSystem.cpp \
    src/lObject.cpp \
    src/lParser.cpp \
    src/object.cpp \
    src/NGLScene.cpp \
    src/NGLSceneMouseControls.cpp \
    src/Turtle.cpp
HEADERS+= include/Image.h \
    include/lSystem.h \
    include/lObject.h \
    include/lParser.h \
    include/object.h \
    include/NGLScene.h \
    include/WindowParams.h \
    include/Turtle.h

INCLUDEPATH += ./include
DESTDIR=./

OTHER_FILES = $$PWD/*.txt

CONFIG += console
# note each command you add needs a ; as it will be run as a single line
# first check if we are shadow building or not easiest way is to check out against current
#!equals(PWD, $${OUT_PWD}){
#	copydata.commands = echo "creating destination dirs" ;
#	# now make a dir
#	copydata.commands += mkdir -p $$OUT_PWD/shaders ;
#	copydata.commands += echo "copying files" ;
#	# then copy the files
#	copydata.commands += $(COPY_DIR) $$PWD/shaders/* $$OUT_PWD/shaders/ ;
#	# now make sure the first target is built before copy
#	first.depends = $(first) copydata
#	export(first.depends)
#	export(copydata.commands)
#	# now add it as an extra target
#	QMAKE_EXTRA_TARGETS += first copydata
#}
NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){ # note brace must be here
        message("including $HOME/NGL")
        include($(HOME)/NGL/UseNGL.pri)
}
else{ # note brace must be here
        message("Using custom NGL location")
        include($(NGLDIR)/UseNGL.pri)
}


