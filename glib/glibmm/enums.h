// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GLIBMM_ENUMS_H
#define _GLIBMM_ENUMS_H


/* Copyright (C) 2016 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <glib.h>

namespace Glib
{
/** @addtogroup glibmmEnums glibmm Enums and Flags */

/** 
 *  @var ParamFlags PARAM_READABLE
 * The parameter is readable.
 * 
 *  @var ParamFlags PARAM_WRITABLE
 * The parameter is writable.
 * 
 *  @var ParamFlags PARAM_READWRITE
 * Alias for PARAM_READABLE | PARAM_WRITABLE.
 * 
 *  @var ParamFlags PARAM_CONSTRUCT
 * The parameter will be set upon object construction.
 * 
 *  @var ParamFlags PARAM_CONSTRUCT_ONLY
 * The parameter can only be set upon object construction.
 * 
 *  @var ParamFlags PARAM_LAX_VALIDATION
 * Upon parameter conversion (see g_param_value_convert())
 * strict validation is not required.
 * 
 *  @var ParamFlags PARAM_STATIC_NAME
 * The string used as name when constructing the 
 * parameter is guaranteed to remain valid and
 * unmodified for the lifetime of the parameter. 
 * @newin{2,8}
 * 
 *  @var ParamFlags PARAM_STATIC_NICK
 * The string used as nick when constructing the
 * parameter is guaranteed to remain valid and
 * unmmodified for the lifetime of the parameter.
 * @newin{2,8}
 * 
 *  @var ParamFlags PARAM_STATIC_BLURB
 * The string used as blurb when constructing the 
 * parameter is guaranteed to remain valid and 
 * unmodified for the lifetime of the parameter. 
 * @newin{2,8}
 * 
 *  @var ParamFlags PARAM_EXPLICIT_NOTIFY
 * Calls to g_object_set_property() for this
 * property will not automatically result in a "notify" signal being
 * emitted: the implementation must call g_object_notify() themselves
 * in case the property actually changes.  @newin{2,42}
 * 
 *  @var ParamFlags PARAM_PRIVATE
 * Internal.
 * 
 *  @var ParamFlags PARAM_DEPRECATED
 * The parameter is deprecated and will be removed
 * in a future version. A warning will be generated if it is used
 * while running with G_ENABLE_DIAGNOSTIC=1.
 * @newin{2,26}
 * 
 *  @enum ParamFlags
 * 
 * Through the ParamFlags flag values, certain aspects of parameters
 * can be configured. See also G_PARAM_STATIC_STRINGS.
 *
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>%ParamFlags operator|(ParamFlags, ParamFlags)</tt><br>
 * <tt>%ParamFlags operator&(ParamFlags, ParamFlags)</tt><br>
 * <tt>%ParamFlags operator^(ParamFlags, ParamFlags)</tt><br>
 * <tt>%ParamFlags operator~(ParamFlags)</tt><br>
 * <tt>%ParamFlags& operator|=(ParamFlags&, ParamFlags)</tt><br>
 * <tt>%ParamFlags& operator&=(ParamFlags&, ParamFlags)</tt><br>
 * <tt>%ParamFlags& operator^=(ParamFlags&, ParamFlags)</tt><br>
 */
enum ParamFlags
{
  PARAM_READABLE = 1 << 0,
  PARAM_WRITABLE = 1 << 1,
  PARAM_READWRITE = 0x3,
  PARAM_CONSTRUCT = 1 << 2,
  PARAM_CONSTRUCT_ONLY = 1 << 3,
  PARAM_LAX_VALIDATION = 1 << 4,
  PARAM_STATIC_NAME = 1 << 5,
  PARAM_PRIVATE = 0x20,
  PARAM_STATIC_NICK = 1 << 6,
  PARAM_STATIC_BLURB = 1 << 7,
  PARAM_EXPLICIT_NOTIFY = 1 << 30,
  PARAM_DEPRECATED = (gint)(1u << 31)
};

/** @ingroup glibmmEnums */
inline ParamFlags operator|(ParamFlags lhs, ParamFlags rhs)
  { return static_cast<ParamFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline ParamFlags operator&(ParamFlags lhs, ParamFlags rhs)
  { return static_cast<ParamFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline ParamFlags operator^(ParamFlags lhs, ParamFlags rhs)
  { return static_cast<ParamFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline ParamFlags operator~(ParamFlags flags)
  { return static_cast<ParamFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline ParamFlags& operator|=(ParamFlags& lhs, ParamFlags rhs)
  { return (lhs = static_cast<ParamFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline ParamFlags& operator&=(ParamFlags& lhs, ParamFlags rhs)
  { return (lhs = static_cast<ParamFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline ParamFlags& operator^=(ParamFlags& lhs, ParamFlags rhs)
  { return (lhs = static_cast<ParamFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


} //namespace Glib


#endif /* _GLIBMM_ENUMS_H */
