TEMPLATE = app

CONFIG -= app_bundle
CONFIG -= qt

CONFIG += C++11

SOURCES += main.cpp \
    Sorting\sorting.cpp \
    General\utility.cpp \
    Recursion\recursion.cpp \
    Heap\maxheap.cpp \
    General\linkedlist.cpp \
    Stack\stack.cpp \
    Stack\linkedstack.cpp \
    Queue\queue.cpp \
    Queue\linkedqueue.cpp \
    Queue\queue2s.cpp \
    Stack\expeval.cpp \
    Graph\graph.cpp \
    Heap\minheap.cpp

HEADERS += \
    Recursion\recursion.h \
    Sorting\sorting.hpp \
    General\utility.h \
    Heap\maxheap.h \
    General\linkedlist.h \
    Stack\stack.h \
    Stack\linkedstack.h \
    Queue\queue.h \
    Queue\linkedqueue.h \
    Queue\queue2s.h \
    Stack\expeval.h \
    Graph\graph.h \
    Heap\minheap.h
