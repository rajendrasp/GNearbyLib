// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "internal/platform/implementation/system_clock.h"

#include "absl/time/clock.h"
#include "internal/platform/exception.h"
#include "internal/platform/medium_environment.h"
#include "internal/test/fake_clock.h"

namespace nearby {

absl::Time SystemClock::ElapsedRealtime() {
  absl::optional<FakeClock*> fake_clock =
      MediumEnvironment::Instance().GetSimulatedClock();
  if (fake_clock.has_value()) {
    return (*fake_clock)->Now();
  }
  return absl::Now();
}

Exception SystemClock::Sleep(absl::Duration duration) {
  absl::optional<FakeClock*> fake_clock =
      MediumEnvironment::Instance().GetSimulatedClock();
  if (fake_clock.has_value()) {
    (*fake_clock)->FastForward(duration);
  } else {
    absl::SleepFor(duration);
  }
  return {Exception::kSuccess};
}

}  // namespace nearby
