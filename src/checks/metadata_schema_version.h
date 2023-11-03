/*
 * Copyright 2023 SUSE, LLC.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * - - -
 *
 * This is a simple check that ensures the metadata database contains a schema
 * in the expected version
*/

#ifndef FSCK_SFS_SRC_CHECKS_METADATA_SCHEMA_VERSION_H__
#define FSCK_SFS_SRC_CHECKS_METADATA_SCHEMA_VERSION_H__

#include <filesystem>
#include <memory>

#include "checks.h"
#include "sqlite.h"

class MetadataSchemaVersionFix : public Fix {
 private:
  int schema_version;

  std::string to_string() const;

 public:
  MetadataSchemaVersionFix(const std::filesystem::path& path, int version);
  operator std::string() const { return to_string(); };
  void fix();
};

class MetadataSchemaVersionCheck : public Check {
 private:
  std::unique_ptr<Database> metadata;

 public:
  MetadataSchemaVersionCheck(const std::filesystem::path& path);
  virtual ~MetadataSchemaVersionCheck() override;
  virtual int check() override;
};

const int EXPECTED_METADATA_SCHEMA_VERSION = 4;

#endif  // FSCK_SFS_SRC_CHECKS_METADATA_SCHEMA_VERSION_H__
