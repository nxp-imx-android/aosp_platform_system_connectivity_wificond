/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include "wificond/scanning/pno_network.h"

#include <android-base/logging.h>

#include "wificond/parcelable_utils.h"

using android::status_t;

namespace com {
namespace android {
namespace server {
namespace wifi {
namespace wificond {

status_t PnoNetwork::writeToParcel(::android::Parcel* parcel) const {
  // This redundant writing of vector length is needed by Java side parsing.
  // See writeToPracel() in wificond/scanning/scan_result.cpp for detailed
  // explanation.
  RETURN_IF_FAILED(parcel->writeInt32(ssid_.size()));
  RETURN_IF_FAILED(parcel->writeByteVector(ssid_));
  return ::android::OK;
}

status_t PnoNetwork::readFromParcel(const ::android::Parcel* parcel) {
  int32_t ignored = 0;
  RETURN_IF_FAILED(parcel->readInt32(&ignored));
  RETURN_IF_FAILED(parcel->readByteVector(&ssid_));
  return ::android::OK;
}

}  // namespace wificond
}  // namespace wifi
}  // namespace server
}  // namespace android
}  // namespace com