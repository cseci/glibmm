// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/fileattributeinfo.h>
#include <giomm/private/fileattributeinfo_p.h>


/* Copyright (C) 2007 The gtkmm Development Team
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

#include <gio/gio.h>

namespace Gio
{

FileAttributeInfo::FileAttributeInfo(const GFileAttributeInfo* ginfo)
: m_name(ginfo->name ? ginfo->name : ""),
  m_type(static_cast<FileAttributeType>(ginfo->type)),
  m_flags(static_cast<FileAttributeInfoFlags>(ginfo->flags))
{
}

FileAttributeInfo::FileAttributeInfo(const FileAttributeInfo& other)
{
  *this = other;
}

FileAttributeInfo&
FileAttributeInfo::operator=(const FileAttributeInfo& other)
{
  m_name = other.m_name;
  m_type = other.m_type;
  m_flags = other.m_flags;
  return *this;
}

FileAttributeInfo::FileAttributeInfo(FileAttributeInfo&& other) noexcept
  : m_name(std::move(other.m_name)),
    m_type(std::move(other.m_type)),
    m_flags(std::move(other.m_flags))
{
}

FileAttributeInfo&
FileAttributeInfo::operator=(FileAttributeInfo&& other) noexcept
{
  m_name = std::move(other.m_name);
  m_type = std::move(other.m_type);
  m_flags = std::move(other.m_flags);

  return *this;
}

FileAttributeInfo::~FileAttributeInfo()
{
}

std::string
FileAttributeInfo::get_name() const
{
  return m_name;
}

FileAttributeType
FileAttributeInfo::get_type() const
{
  return m_type;
}

FileAttributeInfoFlags
FileAttributeInfo::get_flags() const
{
  return m_flags;
}

} // namespace Gio

namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gio::FileAttributeType>::value_type()
{
  return g_file_attribute_type_get_type();
}

// static
GType Glib::Value<Gio::FileAttributeInfoFlags>::value_type()
{
  return g_file_attribute_info_flags_get_type();
}

// static
GType Glib::Value<Gio::FileAttributeStatus>::value_type()
{
  return g_file_attribute_status_get_type();
}


namespace Gio
{


} // namespace Gio


