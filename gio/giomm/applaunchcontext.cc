// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/applaunchcontext.h>
#include <giomm/private/applaunchcontext_p.h>


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

#include <giomm/appinfo.h>
#include <giomm/file.h>
#include <gio/gio.h>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::AppLaunchContext> wrap(GAppLaunchContext* object, bool take_copy)
{
  return Glib::RefPtr<Gio::AppLaunchContext>( dynamic_cast<Gio::AppLaunchContext*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& AppLaunchContext_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &AppLaunchContext_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_app_launch_context_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void AppLaunchContext_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* AppLaunchContext_Class::wrap_new(GObject* object)
{
  return new AppLaunchContext((GAppLaunchContext*)object);
}


/* The implementation: */

GAppLaunchContext* AppLaunchContext::gobj_copy()
{
  reference();
  return gobj();
}

AppLaunchContext::AppLaunchContext(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

AppLaunchContext::AppLaunchContext(GAppLaunchContext* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


AppLaunchContext::AppLaunchContext(AppLaunchContext&& src) noexcept
: Glib::Object(std::move(src))
{}

AppLaunchContext& AppLaunchContext::operator=(AppLaunchContext&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


AppLaunchContext::~AppLaunchContext() noexcept
{}


AppLaunchContext::CppClassType AppLaunchContext::applaunchcontext_class_; // initialize static member

GType AppLaunchContext::get_type()
{
  return applaunchcontext_class_.init().get_type();
}


GType AppLaunchContext::get_base_type()
{
  return g_app_launch_context_get_type();
}


AppLaunchContext::AppLaunchContext()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(applaunchcontext_class_.init()))
{
  

}

Glib::RefPtr<AppLaunchContext> AppLaunchContext::create()
{
  return Glib::RefPtr<AppLaunchContext>( new AppLaunchContext() );
}

void AppLaunchContext::setenv(const Glib::ustring& variable, const Glib::ustring& value)
{
  g_app_launch_context_setenv(gobj(), variable.c_str(), value.c_str());
}

void AppLaunchContext::unsetenv(const Glib::ustring& variable)
{
  g_app_launch_context_unsetenv(gobj(), variable.c_str());
}

std::vector<Glib::ustring> AppLaunchContext::get_environment() const
{
  return Glib::ArrayHandler<Glib::ustring>::array_to_vector(g_app_launch_context_get_environment(const_cast<GAppLaunchContext*>(gobj())), Glib::OWNERSHIP_DEEP);
}

std::string AppLaunchContext::get_display(const Glib::RefPtr<AppInfo>& info, const Glib::ListHandle< Glib::RefPtr<Gio::File> >& files)
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_app_launch_context_get_display(gobj(), Glib::unwrap(info), files.data()));
}

std::string AppLaunchContext::get_startup_notify_id(const Glib::RefPtr<AppInfo>& info, const Glib::ListHandle< Glib::RefPtr<Gio::File> >& files)
{
  return Glib::convert_return_gchar_ptr_to_stdstring(g_app_launch_context_get_startup_notify_id(gobj(), Glib::unwrap(info), files.data()));
}

void AppLaunchContext::launch_failed(const std::string& startup_notify_id)
{
  g_app_launch_context_launch_failed(gobj(), startup_notify_id.c_str());
}


} // namespace Gio


