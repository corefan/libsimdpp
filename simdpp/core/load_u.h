/*  libsimdpp
    Copyright (C) 2013  Povilas Kanapickas povilas@radix.lt
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_LOAD_U_H
#define LIBSIMDPP_SIMDPP_CORE_LOAD_U_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/load_u.h>

namespace simdpp {
#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace SIMDPP_ARCH_NAMESPACE {
#endif

/// @{
/** Loads a 128-bit or 256-bit integer, 32-bit or 64-bit float vector from an
    unaligned memory location.

    @par 128-bit version:

    @code
    a[0..127] = *(p)
    @endcode

    @a p must be aligned to the element size. If @a p is aligned to 16 bytes
    only the referenced 16 byte block is accessed. Otherwise, memory within the
    smallest 16-byte aligned 32-byte block may be accessed.

    @icost{ALTIVEC, 4}

    @par 256-bit version:

    @code
    a[0..255] = *(p)
    @endcode
    @a p must be aligned to 32 bytes.
    @icost{SSE2-SSE4.1, NEON, 2}
    @icost{ALTIVEC, 6}

    @a p must be aligned to the element size. If @a p is aligned to 32 bytes
    only the referenced 16 byte block is accessed. Otherwise, memory within the
    smallest 32-byte aligned 64-byte block may be accessed.
*/
// Each integer type is handled separately because higher aligment guarantees
// offer better performance on e.g. ARM. Note, we don't use LDDQU on SSE,
// because it has usage restrictions and offers improved performance only on
// Pentium 4 era processors.
template<unsigned N>
gint8<N>  load_u(gint8<N>& a,  const void* p)
{
    detail::insn::i_load_u(a, p); return a;
}
template<unsigned N>
gint16<N> load_u(gint16<N>& a, const void* p)
{
    detail::insn::i_load_u(a, p); return a;
}
template<unsigned N>
gint32<N> load_u(gint32<N>& a, const void* p)
{
    detail::insn::i_load_u(a, p); return a;
}
template<unsigned N>
gint64<N> load_u(gint64<N>& a, const void* p)
{
    detail::insn::i_load_u(a, p); return a;
}
template<unsigned N>
float32<N> load_u(float32<N>& a, const float* p)
{
    detail::insn::i_load_u(a, p); return a;
}
template<unsigned N>
float64<N> load_u(float64<N>& a, const double* p)
{
    detail::insn::i_load_u(a, p); return a;
}
/// @}

#ifndef DOXYGEN_SHOULD_SKIP_THIS
} // namespace SIMDPP_ARCH_NAMESPACE
#endif
} // namespace simdpp

#endif

