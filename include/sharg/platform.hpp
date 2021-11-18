// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2020, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2020, Knut Reinert & MPI für molekulare Genetik
// Copyright (c) 2020-2021, deCODE Genetics
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file and also available at: https://github.com/seqan/b.i.o./blob/master/LICENSE
// -----------------------------------------------------------------------------------------------------

#pragma once

#include <cinttypes>
#include <ciso646> // makes _LIBCPP_VERSION available
#include <cstddef> // makes __GLIBCXX__ available

/*!\file
 * \brief Provides platform and dependency checks.
 * \author Svenja Mehringer <svenja.mehringer AT fu-berlin.de>
 */

// ============================================================================
//  C++ standard and features
// ============================================================================

// C++ standard [required]
#ifdef __cplusplus
static_assert(__cplusplus >= 201709, "SARG requires C++20, make sure that you have set -std=c++20.");
#else
#    error "This is not a C++ compiler."
#endif

#if __has_include(<version>)
#    include <version>
#endif

// ============================================================================
//  Dependencies
// ============================================================================

// SARG [required]
#if __has_include(<sarg/version.hpp>)
#    include <sarg/version.hpp>
#else
#    error SARG include directory not set correctly. Forgot to add -I ${INSTALLDIR}/include to your CXXFLAGS?
#endif

// SeqAn3 [required]
#if __has_include(<seqan3/version.hpp>)
#    include <seqan3/version.hpp>
static_assert(seqan3::seqan3_version_major == 3, "SeqAn >= 3.1 is required by SARG.");
static_assert(seqan3::seqan3_version_minor >= 1, "SeqAn >= 3.1 is required by SARG.");
#else
#    error The SeqAn3 library was not included.
#endif

// ============================================================================
//  Documentation
// ============================================================================

// Doxygen related
// this macro is a NO-OP unless doxygen parses it, in which case it resolves to the argument
#ifndef SARG_DOXYGEN_ONLY
#    define SARG_DOXYGEN_ONLY(x)
#endif
