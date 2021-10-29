// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/settingsschemakey.h>
#include <giomm/private/settingsschemakey_p.h>


/* Copyright (C) 2015 The giomm Development Team
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

} // namespace Gio

namespace
{
} // anonymous namespace


/* Why reinterpret_cast<SettingsSchemaKey*>(gobject) is needed:
 *
 * A SettingsSchemaKey instance is in fact always a GSettingsSchemaKey instance.
 * Unfortunately, GSettingsSchemaKey cannot be a member of SettingsSchemaKey,
 * because it is an opaque struct.  Also, the C interface does not provide
 * any hooks to install a destroy notification handler, thus we cannot
 * wrap it dynamically either.
 *
 * The cast works because SettingsSchemaKey does not have any member data, and
 * it is impossible to derive from it.  This is ensured by using final on the
 * class and by using = delete on the default constructor.
 */

namespace Glib
{

Glib::RefPtr<Gio::SettingsSchemaKey> wrap(GSettingsSchemaKey* object, bool take_copy)
{
  if(take_copy && object)
    g_settings_schema_key_ref(object);

  // See the comment at the top of this file, if you want to know why the cast works.
  return Glib::RefPtr<Gio::SettingsSchemaKey>(reinterpret_cast<Gio::SettingsSchemaKey*>(object));
}

} // namespace Glib


namespace Gio
{


void SettingsSchemaKey::reference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_key_ref(reinterpret_cast<GSettingsSchemaKey*>(const_cast<SettingsSchemaKey*>(this)));
}

void SettingsSchemaKey::unreference() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  g_settings_schema_key_unref(reinterpret_cast<GSettingsSchemaKey*>(const_cast<SettingsSchemaKey*>(this)));
}

GSettingsSchemaKey* SettingsSchemaKey::gobj()
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<GSettingsSchemaKey*>(this);
}

const GSettingsSchemaKey* SettingsSchemaKey::gobj() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  return reinterpret_cast<const GSettingsSchemaKey*>(this);
}

GSettingsSchemaKey* SettingsSchemaKey::gobj_copy() const
{
  // See the comment at the top of this file, if you want to know why the cast works.
  const auto gobject = reinterpret_cast<GSettingsSchemaKey*>(const_cast<SettingsSchemaKey*>(this));
  g_settings_schema_key_ref(gobject);
  return gobject;
}


Glib::ustring SettingsSchemaKey::get_name() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_key_get_name(const_cast<GSettingsSchemaKey*>(gobj())));
}

Glib::ustring SettingsSchemaKey::get_summary() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_key_get_summary(const_cast<GSettingsSchemaKey*>(gobj())));
}

Glib::ustring SettingsSchemaKey::get_description() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_settings_schema_key_get_description(const_cast<GSettingsSchemaKey*>(gobj())));
}

Glib::VariantType SettingsSchemaKey::get_value_type() const
{
  return Glib::wrap(const_cast<GVariantType*>(g_settings_schema_key_get_value_type(const_cast<GSettingsSchemaKey*>(gobj()))), true);
}

Glib::VariantBase SettingsSchemaKey::get_default_value() const
{
  return Glib::wrap(g_settings_schema_key_get_default_value(const_cast<GSettingsSchemaKey*>(gobj())), false);
}

Glib::VariantBase SettingsSchemaKey::get_range() const
{
  return Glib::wrap(g_settings_schema_key_get_range(const_cast<GSettingsSchemaKey*>(gobj())), false);
}

bool SettingsSchemaKey::range_check(const Glib::VariantBase& value) const
{
  return g_settings_schema_key_range_check(const_cast<GSettingsSchemaKey*>(gobj()), const_cast<GVariant*>((value).gobj()));
}


} // namespace Gio


