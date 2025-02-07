/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "thread.h"

#include <android-base/logging.h>

#include "asm_support_arm64.h"
#include "base/enums.h"

namespace art HIDDEN {

void Thread::InitCpu() {
  CHECK_EQ(THREAD_FLAGS_OFFSET, ThreadFlagsOffset<PointerSize::k64>().Int32Value());
  CHECK_EQ(THREAD_CARD_TABLE_OFFSET, CardTableOffset<PointerSize::k64>().Int32Value());
  CHECK_EQ(THREAD_EXCEPTION_OFFSET, ExceptionOffset<PointerSize::k64>().Int32Value());
  CHECK_EQ(THREAD_ID_OFFSET, ThinLockIdOffset<PointerSize::k64>().Int32Value());
}

void Thread::CleanupCpu() {
  // Do nothing.
}

}  // namespace art
