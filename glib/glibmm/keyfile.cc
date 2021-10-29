// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/keyfile.h>
#include <glibmm/private/keyfile_p.h>


/* Copyright 2006 The gtkmm Development Team
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

namespace Glib
{

/**** Glib::KeyFile ********************************************************/

KeyFile::KeyFile()
{
  gobject_ = g_key_file_new();
  owns_gobject_ = true;
}

KeyFile::KeyFile(GKeyFile* castitem, bool takes_ownership)
{
  gobject_ = castitem;
  owns_gobject_ = takes_ownership;
}

KeyFile::KeyFile(KeyFile&& other) noexcept : gobject_(std::move(other.gobject_)),
                                             owns_gobject_(std::move(other.owns_gobject_))
{
  other.gobject_ = nullptr;
  other.owns_gobject_ = false;
}

KeyFile&
KeyFile::operator=(KeyFile&& other) noexcept
{
  if (owns_gobject_)
    g_key_file_free(gobject_);

  gobject_ = std::move(other.gobject_);
  owns_gobject_ = std::move(other.owns_gobject_);

  other.gobject_ = nullptr;
  other.owns_gobject_ = false;

  return *this;
}

KeyFile::~KeyFile()
{
  if (owns_gobject_)
    g_key_file_free(gobject_);
}

bool
KeyFile::load_from_data(const Glib::ustring& data, KeyFileFlags flags)
{
  GError* gerror = nullptr;

  const gboolean result = g_key_file_load_from_data(
    gobj(), data.c_str(), data.bytes(), static_cast<GKeyFileFlags>(unsigned(flags)), &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return (result != 0);
}

bool
KeyFile::load_from_data_dirs(const std::string& file, std::string& full_path, KeyFileFlags flags)
{
  GError* gerror = nullptr;
  char* full_path_c = nullptr;

  const gboolean result = g_key_file_load_from_data_dirs(
    gobj(), file.c_str(), &full_path_c, static_cast<GKeyFileFlags>(unsigned(flags)), &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  if (full_path_c)
    full_path = Glib::make_unique_ptr_gfree(full_path_c).get();
  else
    full_path.erase();

  return (result != 0);
}

bool
KeyFile::load_from_dirs(const std::string& file, const Glib::ArrayHandle<std::string>& search_dirs,
  std::string& full_path, KeyFileFlags flags)
{
  GError* gerror = nullptr;
  char* full_path_c = nullptr;

  const gboolean result =
    g_key_file_load_from_dirs(gobj(), file.c_str(), const_cast<const gchar**>(search_dirs.data()),
      &full_path_c, static_cast<GKeyFileFlags>(unsigned(flags)), &gerror);

  if (gerror)
  {
    if (full_path_c)
    {
      g_free(full_path_c);
    }
    Glib::Error::throw_exception(gerror);
  }

  if (full_path_c)
    full_path = Glib::make_unique_ptr_gfree(full_path_c).get();
  else
    full_path.erase();

  return (result != 0);
}

Glib::ustring
KeyFile::to_data()
{
  GError* gerror = nullptr;
  char* const str = g_key_file_to_data(gobj(), nullptr, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return Glib::convert_return_gchar_ptr_to_ustring(str);
}

Glib::ArrayHandle<Glib::ustring>
KeyFile::get_groups() const
{
  gsize length = 0;
  char** const array = g_key_file_get_groups(const_cast<GKeyFile*>(gobj()), &length);

  return Glib::ArrayHandle<Glib::ustring>(array, length, Glib::OWNERSHIP_DEEP);
}

Glib::ArrayHandle<Glib::ustring>
KeyFile::get_keys(const Glib::ustring& group_name) const
{
  gsize length = 0;
  GError* gerror = nullptr;

  char** const array = g_key_file_get_keys(
    const_cast<GKeyFile*>(gobj()), Glib::c_str_or_nullptr(group_name), &length, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return Glib::ArrayHandle<Glib::ustring>(array, length, Glib::OWNERSHIP_DEEP);
}

Glib::ustring
KeyFile::get_locale_string(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  char* const str = g_key_file_get_locale_string(const_cast<GKeyFile*>(gobj()),
    Glib::c_str_or_nullptr(group_name), key.c_str(), nullptr, &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return Glib::convert_return_gchar_ptr_to_ustring(str);
}

bool
KeyFile::get_boolean(const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  const bool value = static_cast<bool>(
    g_key_file_get_boolean(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror));
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return value;
}

int
KeyFile::get_integer(const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  const int value =
    g_key_file_get_integer(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);
  if (gerror)
    Glib::Error::throw_exception(gerror);

  return value;
}

gint64
KeyFile::get_int64(const Glib::ustring& key) const
{
  GError* gerror = nullptr;

  const gint64 value =
    g_key_file_get_int64(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return value;
}

guint64
KeyFile::get_uint64(const Glib::ustring& key) const
{
  GError* gerror = nullptr;

  const guint64 value =
    g_key_file_get_uint64(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &gerror);

  if (gerror)
    Glib::Error::throw_exception(gerror);

  return value;
}

double
KeyFile::get_double(const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  double retvalue =
    g_key_file_get_double(const_cast<GKeyFile*>(gobj()), nullptr, key.c_str(), &(gerror));

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

void
KeyFile::set_double(const Glib::ustring& key, double value)
{
  g_key_file_set_double(gobj(), nullptr, key.c_str(), value);
}

#define GLIBMM_ERROR_ARG
#define GLIBMM_THROW(err) \
  if (err)                \
  Glib::Error::throw_exception(err)

Glib::ArrayHandle<Glib::ustring>
KeyFile::get_string_list(
  const Glib::ustring& group_name, const Glib::ustring& key GLIBMM_ERROR_ARG) const
{
  gsize length = 0;
  GError* gerror = nullptr;

  char** const array = g_key_file_get_string_list(const_cast<GKeyFile*>(gobj()),
    Glib::c_str_or_nullptr(group_name), key.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return Glib::ArrayHandle<Glib::ustring>(array, length, Glib::OWNERSHIP_DEEP);
}

Glib::ArrayHandle<Glib::ustring>
KeyFile::get_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key,
  const Glib::ustring& locale GLIBMM_ERROR_ARG) const
{
  gsize length = 0;
  GError* gerror = nullptr;

  char** const array = g_key_file_get_locale_string_list(const_cast<GKeyFile*>(gobj()),
    Glib::c_str_or_nullptr(group_name), key.c_str(), locale.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return Glib::ArrayHandle<Glib::ustring>(array, length, Glib::OWNERSHIP_DEEP);
}

Glib::ArrayHandle<bool>
KeyFile::get_boolean_list(
  const Glib::ustring& group_name, const Glib::ustring& key GLIBMM_ERROR_ARG) const
{
  gsize length = 0;
  GError* gerror = nullptr;

  gboolean* const array = g_key_file_get_boolean_list(const_cast<GKeyFile*>(gobj()),
    Glib::c_str_or_nullptr(group_name), key.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return Glib::ArrayHandle<bool>(array, length, Glib::OWNERSHIP_SHALLOW);
}

Glib::ArrayHandle<int>
KeyFile::get_integer_list(
  const Glib::ustring& group_name, const Glib::ustring& key GLIBMM_ERROR_ARG) const
{
  gsize length = 0;
  GError* gerror = nullptr;

  int* const array = g_key_file_get_integer_list(const_cast<GKeyFile*>(gobj()),
    Glib::c_str_or_nullptr(group_name), key.c_str(), &length, &gerror);

  GLIBMM_THROW(gerror);

  return Glib::ArrayHandle<int>(array, length, Glib::OWNERSHIP_SHALLOW);
}

Glib::ArrayHandle<double>
KeyFile::get_double_list(
  const Glib::ustring& group_name, const Glib::ustring& key GLIBMM_ERROR_ARG) const
{
  gsize length = 0;
  GError* gerror = nullptr;

  double* const array = g_key_file_get_double_list(
    const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &length, &gerror);
  GLIBMM_THROW(gerror);

  return Glib::ArrayHandle<double>(array, length, Glib::OWNERSHIP_SHALLOW);
}

void
KeyFile::set_string_list(const Glib::ustring& group_name, const Glib::ustring& key,
  const Glib::ArrayHandle<Glib::ustring>& list)
{
  g_key_file_set_string_list(
    gobj(), Glib::c_str_or_nullptr(group_name), key.c_str(), list.data(), list.size());
}

void
KeyFile::set_locale_string_list(const Glib::ustring& group_name, const Glib::ustring& key,
  const Glib::ustring& locale, const Glib::ArrayHandle<Glib::ustring>& list)
{
  g_key_file_set_locale_string_list(gobj(), Glib::c_str_or_nullptr(group_name), key.c_str(),
    locale.c_str(), list.data(), list.size());
}

void
KeyFile::set_integer_list(
  const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<int>& list)
{
  g_key_file_set_integer_list(gobj(), Glib::c_str_or_nullptr(group_name), key.c_str(),
    const_cast<int*>(list.data()), list.size());
}

void
KeyFile::set_double_list(
  const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<double>& list)
{
  g_key_file_set_double_list(
    gobj(), group_name.c_str(), key.c_str(), const_cast<double*>(list.data()), list.size());
}

void
KeyFile::set_boolean_list(
  const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ArrayHandle<bool>& list)
{
  g_key_file_set_boolean_list(gobj(), Glib::c_str_or_nullptr(group_name), key.c_str(),
    const_cast<gboolean*>(list.data()), list.size());
}

Glib::ustring
KeyFile::get_comment() const
{
  GError* gerror = nullptr;
  char* const str =
    g_key_file_get_comment(const_cast<GKeyFile*>(gobj()), nullptr, nullptr, &gerror);

  GLIBMM_THROW(gerror);

  return Glib::convert_return_gchar_ptr_to_ustring(str);
}

Glib::ustring
KeyFile::get_comment(const Glib::ustring& group_name GLIBMM_ERROR_ARG) const
{
  GError* gerror = nullptr;
  char* const str = g_key_file_get_comment(
    const_cast<GKeyFile*>(gobj()), Glib::c_str_or_nullptr(group_name), nullptr, &gerror);
  GLIBMM_THROW(gerror);

  return Glib::convert_return_gchar_ptr_to_ustring(str);
}

void
KeyFile::set_comment(const Glib::ustring& comment GLIBMM_ERROR_ARG)
{
  GError* gerror = nullptr;
  g_key_file_set_comment(gobj(), nullptr, nullptr, comment.c_str(), &gerror);

  GLIBMM_THROW(gerror);
}

void
KeyFile::set_comment(const Glib::ustring& group_name, const Glib::ustring& comment GLIBMM_ERROR_ARG)
{
  GError* gerror = nullptr;
  g_key_file_set_comment(
    gobj(), Glib::c_str_or_nullptr(group_name), nullptr, comment.c_str(), &gerror);
  GLIBMM_THROW(gerror);
}

} // namespace Glib

namespace
{
} // anonymous namespace


Glib::KeyFileError::KeyFileError(Glib::KeyFileError::Code error_code, const Glib::ustring& error_message)
:
  Glib::Error (G_KEY_FILE_ERROR, error_code, error_message)
{}

Glib::KeyFileError::KeyFileError(GError* gobject)
:
  Glib::Error (gobject)
{}

Glib::KeyFileError::Code Glib::KeyFileError::code() const
{
  return static_cast<Code>(Glib::Error::code());
}

void Glib::KeyFileError::throw_func(GError* gobject)
{
  throw Glib::KeyFileError(gobject);
}


namespace Glib
{


bool KeyFile::load_from_file(const std::string& file, KeyFileFlags flags)
{
  GError* gerror = nullptr;
  bool retvalue = g_key_file_load_from_file(gobj(), file.c_str(), ((GKeyFileFlags)(flags)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

#ifndef GLIBMM_DISABLE_DEPRECATED
G_GNUC_BEGIN_IGNORE_DEPRECATIONS
bool KeyFile::load_from_dirs(const std::string& file, const Glib::ArrayHandle<std::string>& search_dirs, Glib::ArrayHandle<std::string>& full_path, KeyFileFlags flags)
{
  GError* gerror = nullptr;
  bool retvalue = g_key_file_load_from_dirs(gobj(), file.c_str(), const_cast<const gchar**>(search_dirs.data()), const_cast<gchar**>(full_path.data()), ((GKeyFileFlags)(flags)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GLIBMM_DISABLE_DEPRECATED

bool KeyFile::save_to_file(const std::string& filename)
{
  GError* gerror = nullptr;
  bool retvalue = g_key_file_save_to_file(gobj(), filename.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::ustring KeyFile::get_start_group() const
{
  return Glib::convert_return_gchar_ptr_to_ustring(g_key_file_get_start_group(const_cast<GKeyFile*>(gobj())));
}

bool KeyFile::has_group(const Glib::ustring& group_name) const
{
  return g_key_file_has_group(const_cast<GKeyFile*>(gobj()), group_name.c_str());
}

bool KeyFile::has_key(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  bool retvalue = g_key_file_has_key(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::ustring KeyFile::get_value(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  Glib::ustring retvalue = Glib::convert_return_gchar_ptr_to_ustring(g_key_file_get_value(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::ustring KeyFile::get_string(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  Glib::ustring retvalue = Glib::convert_return_gchar_ptr_to_ustring(g_key_file_get_string(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

Glib::ustring KeyFile::get_locale_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale) const
{
  GError* gerror = nullptr;
  Glib::ustring retvalue = Glib::convert_return_gchar_ptr_to_ustring(g_key_file_get_locale_string(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), locale.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool KeyFile::get_boolean(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  bool retvalue = g_key_file_get_boolean(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

int KeyFile::get_integer(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  int retvalue = g_key_file_get_integer(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint64 KeyFile::get_int64(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  gint64 retvalue = g_key_file_get_int64(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint64 KeyFile::get_uint64(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  guint64 retvalue = g_key_file_get_uint64(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

double KeyFile::get_double(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  double retvalue = g_key_file_get_double(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void KeyFile::set_double(const Glib::ustring& group_name, const Glib::ustring& key, double value)
{
  g_key_file_set_double(gobj(), group_name.c_str(), key.c_str(), value);
}

Glib::ustring KeyFile::get_comment(const Glib::ustring& group_name, const Glib::ustring& key) const
{
  GError* gerror = nullptr;
  Glib::ustring retvalue = Glib::convert_return_gchar_ptr_to_ustring(g_key_file_get_comment(const_cast<GKeyFile*>(gobj()), group_name.c_str(), key.c_str(), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void KeyFile::set_list_separator(gchar separator)
{
  g_key_file_set_list_separator(gobj(), separator);
}

void KeyFile::set_value(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& value)
{
  g_key_file_set_value(gobj(), group_name.c_str(), key.c_str(), value.c_str());
}

void KeyFile::set_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& string)
{
  g_key_file_set_string(gobj(), group_name.c_str(), key.c_str(), string.c_str());
}

void KeyFile::set_locale_string(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& locale, const Glib::ustring& string)
{
  g_key_file_set_locale_string(gobj(), group_name.c_str(), key.c_str(), locale.c_str(), string.c_str());
}

void KeyFile::set_boolean(const Glib::ustring& group_name, const Glib::ustring& key, bool value)
{
  g_key_file_set_boolean(gobj(), group_name.c_str(), key.c_str(), static_cast<int>(value));
}

void KeyFile::set_integer(const Glib::ustring& group_name, const Glib::ustring& key, int value)
{
  g_key_file_set_integer(gobj(), group_name.c_str(), key.c_str(), value);
}

void KeyFile::set_int64(const Glib::ustring& group_name, const Glib::ustring& key, gint64 value)
{
  g_key_file_set_int64(gobj(), group_name.c_str(), key.c_str(), value);
}

void KeyFile::set_uint64(const Glib::ustring& group_name, const Glib::ustring& key, guint64 value)
{
  g_key_file_set_uint64(gobj(), group_name.c_str(), key.c_str(), value);
}

void KeyFile::set_comment(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& comment)
{
  GError* gerror = nullptr;
  g_key_file_set_comment(gobj(), group_name.c_str(), key.c_str(), comment.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void KeyFile::remove_comment(const Glib::ustring& group_name, const Glib::ustring& key)
{
  GError* gerror = nullptr;
  g_key_file_remove_comment(gobj(), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void KeyFile::remove_key(const Glib::ustring& group_name, const Glib::ustring& key)
{
  GError* gerror = nullptr;
  g_key_file_remove_key(gobj(), group_name.c_str(), key.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void KeyFile::remove_group(const Glib::ustring& group_name)
{
  GError* gerror = nullptr;
  g_key_file_remove_group(gobj(), group_name.c_str(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}


} // namespace Glib


