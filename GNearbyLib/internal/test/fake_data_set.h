// Copyright 2022 Google LLC
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

#ifndef THIRD_PARTY_NEARBY_INTERNAL_TEST_FAKE_DATA_SET_H_
#define THIRD_PARTY_NEARBY_INTERNAL_TEST_FAKE_DATA_SET_H_

#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "internal/data/data_set.h"

namespace nearby {
namespace data {

template <typename T>
class FakeDataSet : public DataSet<T> {
 public:
  using KeyEntryVector = std::vector<std::pair<std::string, T>>;

  explicit FakeDataSet(const absl::flat_hash_map<std::string, T>& entries_map)
      : entries_map_(entries_map) {}

  void Initialize(std::function<void(InitStatus)> callback) override {
    init_callback_ = std::move(callback);
  }

  void LoadEntries(std::function<void(bool, std::unique_ptr<std::vector<T>>)>
                       callback) override {
    load_callback_ = std::move(callback);
  }

  void UpdateEntries(std::unique_ptr<KeyEntryVector> entries_to_save,
                     std::unique_ptr<std::vector<std::string>> keys_to_remove,
                     std::function<void(bool)> callback) override {
    entries_to_save_ = std::move(entries_to_save);
    keys_to_remove_ = std::move(keys_to_remove);
    update_callback_ = std::move(callback);
  }

  void Destroy(std::function<void(bool)> callback) override {
    destroy_callback_ = std::move(callback);
  }

  // Mocked methods
  void InitStatusCallback(InitStatus status) {
    if (init_callback_ != nullptr) {
      init_callback_(status);
    }
  }

  void LoadCallback(bool success) {
    if (load_callback_ != nullptr) {
      auto entries = std::make_unique<std::vector<T>>();
      for (auto it = entries_map_.begin(); it != entries_map_.end(); ++it) {
        entries->push_back(it->second);
      }
      load_callback_(success, std::move(entries));
    }
  }

  void UpdateCallback(bool success) {
    if (success) {
      if (entries_to_save_ != nullptr) {
        for (auto it = entries_to_save_->begin(); it != entries_to_save_->end();
             ++it) {
          auto entry = entries_map_.find(it->first);
          if (entry == entries_map_.end()) {
            entries_map_.emplace(it->first, it->second);
          } else {
            entry->second = it->second;
          }
        }
      }

      if (keys_to_remove_ != nullptr) {
        for (auto it = keys_to_remove_->begin(); it != keys_to_remove_->end();
             ++it) {
          entries_map_.erase(*it);
        }
      }
    }

    entries_to_save_ = nullptr;
    keys_to_remove_ = nullptr;
    if (update_callback_ != nullptr) {
      update_callback_(success);
    }
  }

  void DestroyCallback(bool success) {
    if (success) {
      entries_map_.clear();
    }

    if (destroy_callback_ != nullptr) {
      destroy_callback_(success);
    }
  }

  absl::flat_hash_map<std::string, T>& entries_map() { return entries_map_; }

 private:
  absl::flat_hash_map<std::string, T> entries_map_ = nullptr;
  std::function<void(InitStatus)> init_callback_ = nullptr;
  std::function<void(bool, std::unique_ptr<std::vector<T>>)> load_callback_ =
      nullptr;
  std::unique_ptr<KeyEntryVector> entries_to_save_ = nullptr;
  std::unique_ptr<std::vector<std::string>> keys_to_remove_ = nullptr;
  std::function<void(bool)> update_callback_ = nullptr;
  std::function<void(bool)> destroy_callback_ = nullptr;
};

}  // namespace data
}  // namespace nearby

#endif  // THIRD_PARTY_NEARBY_INTERNAL_TEST_FAKE_DATA_SET_H_
