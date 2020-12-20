TEMPLATE = app
CONFIG += -std=c+=11

HEADERS += \
    Abstration.hpp \
    ConcreteImplementation.hpp \
    ExtendedAbstration.hpp \
    Implementation.hpp

SOURCES += \
    Abstration.cpp \
    ConcreteImplementation.cpp \
    ExtendedAbstration.cpp \
    Implementation.cpp \
    main.cpp

DISTFILES += \
    Abstraction.py \
    ConcreteImplementation.py \
    ExtendedAbstraction.py \
    Implementation.py \
    main.py
