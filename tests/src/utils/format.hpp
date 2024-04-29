/*
 * bit7z - A C++ static library to interface with the 7-zip shared libraries.
 * Copyright (c) 2014-2023 Riccardo Ostani - All Rights Reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <string>

#include <bit7z/bitformat.hpp>

namespace bit7z { // NOLINT(modernize-concat-nested-namespaces)
namespace test {

template<typename FormatType>
struct TestFormat {
    using Type = FormatType;

    std::string extension;
    const FormatType& format;
};

using TestInputFormat = TestFormat< BitInFormat >;
using TestOutputFormat = TestFormat< BitInOutFormat >;

inline auto format_has_path_metadata( const BitInFormat& format ) noexcept -> bool {
    return ( format != BitFormat::BZip2 ) && ( format != BitFormat::Lzma ) && ( format != BitFormat::Xz );
}

inline auto format_has_size_metadata( const BitInFormat& format ) noexcept -> bool {
    return ( format != BitFormat::BZip2 ) && ( format != BitFormat::Lzma );
}

inline auto format_has_crc32( const BitInFormat& format ) noexcept -> bool {
    return ( format != BitFormat::BZip2 ) &&
           ( format != BitFormat::Iso ) &&
           ( format != BitFormat::Lzh ) && // Actually, Lzh provides a CRC, but it uses the CRC16/ARC algorithm.
           ( format != BitFormat::Lzma ) &&
           ( format != BitFormat::Tar ) &&
           ( format != BitFormat::Wim ) &&
           ( format != BitFormat::Xz );
}

inline auto format_has_crc16( const BitInFormat& format ) noexcept -> bool {
    return format == BitFormat::Lzh;
}

inline auto format_compresses_files( const BitInFormat& format ) noexcept -> bool {
    return ( format != BitFormat::Iso ) && ( format != BitFormat::Tar ) && ( format != BitFormat::Wim );
}

} // namespace test
} // namespace bit7z

#endif //FORMAT_HPP
