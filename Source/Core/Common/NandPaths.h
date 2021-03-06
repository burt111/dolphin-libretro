// Copyright 2008 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <string>
#include <utility>
#include <vector>

#include "Common/CommonTypes.h"

static const u64 TITLEID_SYSMENU = 0x0000000100000002;
static const std::string TITLEID_SYSMENU_STRING = "0000000100000002";

namespace Common
{
void InitializeWiiRoot(bool use_temporary);
void ShutdownWiiRoot();

enum FromWhichRoot
{
  FROM_CONFIGURED_ROOT,  // not related to currently running game - use D_WIIROOT_IDX
  FROM_SESSION_ROOT,     // request from currently running game - use D_SESSION_WIIROOT_IDX
};

std::string GetTicketFileName(u64 _titleID, FromWhichRoot from);
std::string GetTMDFileName(u64 _titleID, FromWhichRoot from);
std::string GetTitleDataPath(u64 _titleID, FromWhichRoot from);
std::string GetTitleContentPath(u64 _titleID, FromWhichRoot from);
bool CheckTitleTMD(u64 _titleID, FromWhichRoot from);
bool CheckTitleTIK(u64 _titleID, FromWhichRoot from);

// Escapes characters that are invalid or have special meanings in the host file system
std::string EscapeFileName(const std::string& filename);
// Escapes characters that are invalid or have special meanings in the host file system
std::string EscapePath(const std::string& path);
// Reverses escaping done by EscapeFileName
std::string UnescapeFileName(const std::string& filename);
}
