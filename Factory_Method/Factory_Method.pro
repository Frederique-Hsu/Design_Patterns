TEMPLATE = app
CONFIG += c++17

HEADERS += \
    ConcreteCreator.hpp \
    ConcreteProduct.h++ \
    Creator.hh \
    Product.h++

SOURCES += \
    Client.cxx \
    ConcreteCreator.cpp \
    ConcreteProduct.c++ \
    Creator.cc \
    Product.c++
