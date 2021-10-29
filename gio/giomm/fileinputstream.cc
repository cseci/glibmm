// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/fileinputstream.h>
#include <giomm/private/fileinputstream_p.h>


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
#include "slot_async.h"
#include <glibmm/exceptionhandler.h>

namespace Gio
{

Glib::RefPtr<FileInfo>
FileInputStream::query_info(
  const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes)
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(g_file_input_stream_query_info(gobj(), g_strdup((attributes).c_str()),
    const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

Glib::RefPtr<FileInfo>
FileInputStream::query_info(const std::string& attributes)
{
  GError* gerror = nullptr;
  auto retvalue = Glib::wrap(
    g_file_input_stream_query_info(gobj(), g_strdup((attributes).c_str()), nullptr, &(gerror)));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

void
FileInputStream::query_info_async(const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, const std::string& attributes, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_file_input_stream_query_info_async(gobj(), const_cast<char*>(attributes.c_str()), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
FileInputStream::query_info_async(
  const SlotAsyncReady& slot, const std::string& attributes, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_file_input_stream_query_info_async(gobj(), const_cast<char*>(attributes.c_str()), io_priority,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::FileInputStream> wrap(GFileInputStream* object, bool take_copy)
{
  return Glib::RefPtr<Gio::FileInputStream>( dynamic_cast<Gio::FileInputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& FileInputStream_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &FileInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_file_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  Seekable::add_interface(get_type());

  }

  return *this;
}


void FileInputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* FileInputStream_Class::wrap_new(GObject* object)
{
  return new FileInputStream((GFileInputStream*)object);
}


/* The implementation: */

GFileInputStream* FileInputStream::gobj_copy()
{
  reference();
  return gobj();
}

FileInputStream::FileInputStream(const Glib::ConstructParams& construct_params)
:
  Gio::InputStream(construct_params)
{

}

FileInputStream::FileInputStream(GFileInputStream* castitem)
:
  Gio::InputStream((GInputStream*)(castitem))
{}


FileInputStream::FileInputStream(FileInputStream&& src) noexcept
: Gio::InputStream(std::move(src))
  , Seekable(std::move(src))
{}

FileInputStream& FileInputStream::operator=(FileInputStream&& src) noexcept
{
  Gio::InputStream::operator=(std::move(src));
  Seekable::operator=(std::move(src));
  return *this;
}


FileInputStream::~FileInputStream() noexcept
{}


FileInputStream::CppClassType FileInputStream::fileinputstream_class_; // initialize static member

GType FileInputStream::get_type()
{
  return fileinputstream_class_.init().get_type();
}


GType FileInputStream::get_base_type()
{
  return g_file_input_stream_get_type();
}


Glib::RefPtr<FileInfo> FileInputStream::query_info_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  Glib::RefPtr<FileInfo> retvalue = Glib::wrap(g_file_input_stream_query_info_finish(gobj(), Glib::unwrap(result), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


} // namespace Gio


