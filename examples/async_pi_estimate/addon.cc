/*********************************************************************
 * NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>
#include "sync.h"   // NOLINT(build/include)
#include "async.h"  // NOLINT(build/include)

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::New;
using Nan::Set;

// Expose synchronous and asynchronous access to our
// Estimate() function
NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("calculateSync").ToLocalChecked(),
    New<FunctionTemplate>(CalculateSync)->GetFunction());

  Set(target, New<String>("calculateAsync").ToLocalChecked(),
    New<FunctionTemplate>(CalculateAsync)->GetFunction());
}

NODE_MODULE(addon, InitAll)
