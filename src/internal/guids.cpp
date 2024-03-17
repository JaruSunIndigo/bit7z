// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

/*
 * bit7z - A C++ static library to interface with the 7-zip shared libraries.
 * Copyright (c) 2014-2023 Riccardo Ostani - All Rights Reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include "internal/guids.hpp"

namespace bit7z {

// GUIDs of Interfaces
#ifndef _WIN32
const GUID IID_IUnknown = {
    0x00000000, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 }
};
#endif

// IStream.h
const GUID IID_ISequentialInStream = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00 }
};
const GUID IID_ISequentialOutStream = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00 }
};
const GUID IID_IInStream = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00 }
};
const GUID IID_IOutStream = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00 }
};
const GUID IID_IStreamGetSize = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x06, 0x00, 0x00 }
};
const GUID IID_IStreamGetProps = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x08, 0x00, 0x00 }
};
const GUID IID_IStreamGetProps2 = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x03, 0x00, 0x09, 0x00, 0x00 }
};

// ICoder.h
const GUID IID_ICompressProgressInfo = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00 }
};

// IPassword.h
const GUID IID_ICryptoGetTextPassword = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x05, 0x00, 0x10, 0x00, 0x00 }
};
const GUID IID_ICryptoGetTextPassword2 = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x05, 0x00, 0x11, 0x00, 0x00 }
};

// IArchive.h
const GUID IID_ISetProperties = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x03, 0x00, 0x00 }
};
const GUID IID_IInArchive = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x60, 0x00, 0x00 }
};
const GUID IID_IOutArchive = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0xA0, 0x00, 0x00 }
};
const GUID IID_IArchiveExtractCallback = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x20, 0x00, 0x00 }
};
const GUID IID_IArchiveOpenVolumeCallback = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x30, 0x00, 0x00 }
};
const GUID IID_IArchiveOpenSetSubArchiveName = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x50, 0x00, 0x00 }
};
const GUID IID_IArchiveUpdateCallback = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x80, 0x00, 0x00 }
};
const GUID IID_IArchiveUpdateCallback2 = {
    0x23170F69, 0x40C1, 0x278A, { 0x00, 0x00, 0x00, 0x06, 0x00, 0x82, 0x00, 0x00 }
};

}  // namespace bit7z
