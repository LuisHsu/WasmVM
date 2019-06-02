#ifndef WASMVM_FRAME__DEF
#define WASMVM_FRAME__DEF

#include <dataTypes/Frame.h>
#include <dataTypes/Entry.h>

struct Frame_ {
    Entry parent;
    vector* locals;       // Value
    ModuleInst* moduleInst;
};

#endif