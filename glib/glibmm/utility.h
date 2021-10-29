#ifndef _GLIBMM_UTILITY_H
#define _GLIBMM_UTILITY_H

/* Copyright 2002 The gtkmm Development Team
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

#include <glibmmconfig.h>
#include <glibmm/ustring.h>
#include <glib.h>
#include <memory> //For std::unique_ptr.

#ifndef DOXYGEN_SHOULD_SKIP_THIS

#ifndef GLIBMM_DISABLE_DEPRECATED
/* Occasionally, a struct variable has to be initialized after its definition,
 * i.e. when using structs as class member data.  For convenience, the macro
 * GLIBMM_INITIALIZE_STRUCT(Var, Type) is provided.  It even avoids creating
 * a temporary if the compiler is GCC.
 *
 * @deprecated Use e.g. std::memset() instead.
 * It's not used any more in the code generated by _CLASS_BOXEDTYPE_STATIC.
 * It generates compiler warnings if __STRICT_ANSI__ is defined.
 */
#if ((__GNUC__ >= 3) || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96)) && !defined(__STRICT_ANSI__)

#define GLIBMM_INITIALIZE_STRUCT(Var, Type) __builtin_memset(&(Var), 0, sizeof(Type))

#else

// TODO: This causes warnings like this:
//"missing initializer for member"
#define GLIBMM_INITIALIZE_STRUCT(Var, Type) \
  G_STMT_START                              \
  {                                         \
    Type const temp_initializer__ = {       \
      0,                                    \
    };                                      \
    (Var) = temp_initializer__;             \
  }                                         \
  G_STMT_END

#endif
#endif // GLIBMM_DISABLE_DEPRECATED

namespace Glib
{

// These are used by gmmproc-generated type conversions:

#ifndef GLIBMM_DISABLE_DEPRECATED
/** Helper to deal with memory allocated
 * by GLib functions in an exception-safe manner.
 *
 * @deprecated Use make_unique_ptr_gfree() instead.
 */
template <typename T>
class ScopedPtr
{
private:
  T* ptr_;
  ScopedPtr(const ScopedPtr<T>&);
  ScopedPtr<T>& operator=(const ScopedPtr<T>&);

public:
  ScopedPtr() : ptr_(nullptr) {}
  explicit ScopedPtr(T* ptr) : ptr_(ptr) {}
  ~ScopedPtr() noexcept { g_free(ptr_); }
  T* get() const { return ptr_; }
  T** addr() { return &ptr_; }
};
#endif // GLIBMM_DISABLE_DEPRECATED

/** Helper to deal with memory allocated
 * by GLib functions in an exception-safe manner.
 *
 * This just creates a std::unique_ptr that uses g_free() as its deleter.
 */
template <typename T>
std::unique_ptr<T[], decltype(&g_free)>
make_unique_ptr_gfree(T* p)
{
  return std::unique_ptr<T[], decltype(&g_free)>(p, &g_free);
}

// TODO: Deprecate this? We don't use it ourselves.
/** Removes the const nature of a ptr
 *
 */
template <class T>
inline T*
unconst(const T* t)
{
  return const_cast<T*>(t);
}

// Convert const gchar* to ustring, while treating NULL as empty string.
inline Glib::ustring
convert_const_gchar_ptr_to_ustring(const char* str)
{
  return (str) ? Glib::ustring(str) : Glib::ustring();
}

// Convert const gchar* to std::string, while treating NULL as empty string.
inline std::string
convert_const_gchar_ptr_to_stdstring(const char* str)
{
  return (str) ? std::string(str) : std::string();
}

// Convert a non-const gchar* return value to ustring, freeing it too.
inline Glib::ustring
convert_return_gchar_ptr_to_ustring(char* str)
{
  return (str) ? Glib::ustring(Glib::make_unique_ptr_gfree(str).get()) : Glib::ustring();
}

// Convert a non-const gchar* return value to std::string, freeing it too.
inline std::string
convert_return_gchar_ptr_to_stdstring(char* str)
{
  return (str) ? std::string(Glib::make_unique_ptr_gfree(str).get()) : std::string();
}

/** Get a pointer to the C style string in a std::string or Glib::ustring.
 * If the string is empty, a nullptr is returned.
 */
template <typename T>
inline const char*
c_str_or_nullptr(const T& str)
{
  return str.empty() ? nullptr : str.c_str();
}

// Append type_name to dest, while replacing special characters with '+'.
void append_canonical_typename(std::string& dest, const char* type_name);

// Delete data referred to by a void*.
// Instantiations can be used as destroy callbacks in glib functions
// that take a GDestroyNotify parameter, such as g_object_set_qdata_full()
// and g_option_group_set_translate_func().
template <typename T>
void
destroy_notify_delete(void* data)
{
  delete static_cast<T*>(data);
}

// Conversion between different types of function pointers with
// reinterpret_cast can make gcc8 print a warning.
// https://github.com/libsigcplusplus/libsigcplusplus/issues/1
// https://github.com/libsigcplusplus/libsigcplusplus/issues/8
/** Returns the supplied function pointer, cast to a pointer to another function type.
 *
 * When a single reinterpret_cast between function pointer types causes a
 * compiler warning or error, this function may work.
 *
 * Qualify calls with namespace names: sigc::internal::function_pointer_cast<>().
 * If you don't, indirect calls from another library that also contains a
 * function_pointer_cast<>() (perhaps glibmm), can be ambiguous due to ADL
 * (argument-dependent lookup).
 */
template <typename T_out, typename T_in>
inline T_out function_pointer_cast(T_in in)
{
  // The double reinterpret_cast suppresses a warning from gcc8 with the
  // -Wcast-function-type option.
  return reinterpret_cast<T_out>(reinterpret_cast<void (*)()>(in));
}

} // namespace Glib

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* _GLIBMM_UTILITY_H */