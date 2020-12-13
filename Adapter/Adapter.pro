TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    Adaptee.hpp \
    Adapter.hpp \
    Multi_Inheritance_Adapter.hpp \
    Target.hpp

SOURCES += \
    Adaptee.cpp \
    Adpater.cpp \
    Multi_Inheritance_Adapter.cpp \
    Target.cpp \
    main.cpp
