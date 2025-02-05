// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
// This file is copied from
// https://github.com/ClickHouse/ClickHouse/blob/master/src/DataTypes/getLeastSupertype.h
// and modified by Doris

#pragma once

#include <parallel_hashmap/phmap.h>
#include <vec/data_types/data_type.h>

#include "common/status.h"

namespace doris::vectorized {

/** Get data type that covers all possible values of passed data types.
  * If there is no such data type, throws an exception.
  *
  * Examples: least common supertype for UInt8, Int8 - Int16.
  * Examples: there is no least common supertype for Array(UInt8), Int8.
  */

using TypeIndexSet = phmap::flat_hash_set<TypeIndex>;

Status get_least_supertype(const DataTypes& types, DataTypePtr* type,
                           bool compatible_with_string = false);

Status get_least_supertype(const TypeIndexSet& types, DataTypePtr* type,
                           bool compatible_with_string = false);

} // namespace doris::vectorized
