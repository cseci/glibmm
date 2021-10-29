// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/datainputstream.h>
#include <giomm/private/datainputstream_p.h>


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
#include <glibmm/error.h>
#include "slot_async.h"

namespace Gio
{

bool
DataInputStream::read_line(std::string& line, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  char* c_line = g_data_input_stream_read_line(gobj(),
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    ::Glib::Error::throw_exception(gerror);
  if (c_line)
  {
    line = c_line;
    g_free(c_line);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

bool
DataInputStream::read_line(std::string& line)
{
  GError* gerror = nullptr;
  char* c_line = g_data_input_stream_read_line(gobj(),
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    nullptr, &gerror);
  if (gerror)
    ::Glib::Error::throw_exception(gerror);
  if (c_line)
  {
    line = c_line;
    g_free(c_line);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

void
DataInputStream::read_line_async(
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_data_input_stream_read_line_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

bool
DataInputStream::read_line_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data)
{
  GError* gerror = nullptr;
  gsize size = 0;
  gchar* buffer =
    g_data_input_stream_read_line_finish(gobj(), Glib::unwrap(result), &size, &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  bool retval = false;
  if (buffer && size)
  {
    retval = (buffer != nullptr);
    data = std::string(buffer, size);
    g_free(buffer);
  }

  return retval;
}

#ifndef GIOMM_DISABLE_DEPRECATED

G_GNUC_BEGIN_IGNORE_DEPRECATIONS
bool
DataInputStream::read_until(
  std::string& data, const std::string& stop_chars, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  char* c_str = g_data_input_stream_read_until(gobj(), stop_chars.c_str(),
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    ::Glib::Error::throw_exception(gerror);
  if (c_str)
  {
    data = c_str;
    g_free(c_str);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

/** non-cancellable version of read_until()
 */
bool
DataInputStream::read_until(std::string& data, const std::string& stop_chars)
{
  GError* gerror = nullptr;
  char* c_str = g_data_input_stream_read_until(gobj(), stop_chars.c_str(),
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    nullptr, &gerror);
  if (gerror)
    ::Glib::Error::throw_exception(gerror);
  if (c_str)
  {
    data = c_str;
    g_free(c_str);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

void
DataInputStream::read_until_async(const std::string& stop_chars, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_data_input_stream_read_until_async(gobj(), stop_chars.c_str(), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

bool
DataInputStream::read_until_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data)
{
  GError* gerror = nullptr;
  gsize size = 0;
  gchar* buffer =
    g_data_input_stream_read_until_finish(gobj(), Glib::unwrap(result), &size, &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  bool retval = false;
  if (buffer && size)
  {
    retval = (buffer != nullptr);
    data = std::string(buffer, size);
    g_free(buffer);
  }

  return retval;
}
G_GNUC_END_IGNORE_DEPRECATIONS
#endif // GIOMM_DISABLE_DEPRECATED


bool
DataInputStream::read_upto(
  std::string& data, const std::string& stop_chars, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  char* c_str = g_data_input_stream_read_upto(gobj(), stop_chars.c_str(), -1, /* null-terminated */
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    Glib::unwrap(cancellable), &gerror);
  if (gerror)
    ::Glib::Error::throw_exception(gerror);
  if (c_str)
  {
    data = c_str;
    g_free(c_str);
    return true;
  }
  // end of stream reached, return failure status
  return false;
}

/** non-cancellable version of read_upto()
 */
bool
DataInputStream::read_upto(std::string& data, const std::string& stop_chars)
{
  GError* gerror = nullptr;
  char* c_str = g_data_input_stream_read_upto(gobj(), stop_chars.c_str(), -1, /* null-terminated */
    nullptr, // pass nullptr since we can easily determine the length from the returned std::string
    nullptr, &gerror);

  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  if (c_str)
  {
    data = c_str;
    g_free(c_str);
    return true;
  }

  // end of stream reached, return failure status
  return false;
}

void
DataInputStream::read_upto_async(const std::string& stop_chars, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_data_input_stream_read_upto_async(gobj(), stop_chars.c_str(), -1, /* null-terminated */
    io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

bool
DataInputStream::read_upto_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data)
{
  GError* gerror = nullptr;
  gsize size = 0;
  gchar* buffer =
    g_data_input_stream_read_upto_finish(gobj(), Glib::unwrap(result), &size, &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  bool retval = false;
  if (buffer && size)
  {
    retval = (buffer != nullptr);
    data = std::string(buffer, size);
    g_free(buffer);
  }

  return retval;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::DataInputStream> wrap(GDataInputStream* object, bool take_copy)
{
  return Glib::RefPtr<Gio::DataInputStream>( dynamic_cast<Gio::DataInputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& DataInputStream_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &DataInputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_data_input_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void DataInputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* DataInputStream_Class::wrap_new(GObject* object)
{
  return new DataInputStream((GDataInputStream*)object);
}


/* The implementation: */

GDataInputStream* DataInputStream::gobj_copy()
{
  reference();
  return gobj();
}

DataInputStream::DataInputStream(const Glib::ConstructParams& construct_params)
:
  Gio::BufferedInputStream(construct_params)
{

}

DataInputStream::DataInputStream(GDataInputStream* castitem)
:
  Gio::BufferedInputStream((GBufferedInputStream*)(castitem))
{}


DataInputStream::DataInputStream(DataInputStream&& src) noexcept
: Gio::BufferedInputStream(std::move(src))
{}

DataInputStream& DataInputStream::operator=(DataInputStream&& src) noexcept
{
  Gio::BufferedInputStream::operator=(std::move(src));
  return *this;
}


DataInputStream::~DataInputStream() noexcept
{}


DataInputStream::CppClassType DataInputStream::datainputstream_class_; // initialize static member

GType DataInputStream::get_type()
{
  return datainputstream_class_.init().get_type();
}


GType DataInputStream::get_base_type()
{
  return g_data_input_stream_get_type();
}


DataInputStream::DataInputStream(const Glib::RefPtr<InputStream>& base_stream)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Gio::BufferedInputStream(Glib::ConstructParams(datainputstream_class_.init(), "base_stream", const_cast<GInputStream*>(Glib::unwrap(base_stream)), nullptr))
{
  

}

Glib::RefPtr<DataInputStream> DataInputStream::create(const Glib::RefPtr<InputStream>& base_stream)
{
  return Glib::RefPtr<DataInputStream>( new DataInputStream(base_stream) );
}

void DataInputStream::set_byte_order(DataStreamByteOrder order)
{
  g_data_input_stream_set_byte_order(gobj(), ((GDataStreamByteOrder)(order)));
}

DataStreamByteOrder DataInputStream::get_byte_order() const
{
  return ((DataStreamByteOrder)(g_data_input_stream_get_byte_order(const_cast<GDataInputStream*>(gobj()))));
}

void DataInputStream::set_newline_type(DataStreamNewlineType type)
{
  g_data_input_stream_set_newline_type(gobj(), ((GDataStreamNewlineType)(type)));
}

DataStreamNewlineType DataInputStream::get_newline_type() const
{
  return ((DataStreamNewlineType)(g_data_input_stream_get_newline_type(const_cast<GDataInputStream*>(gobj()))));
}

guchar DataInputStream::read_byte(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  guchar retvalue = g_data_input_stream_read_byte(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guchar DataInputStream::read_byte()
{
  GError* gerror = nullptr;
  guchar retvalue = g_data_input_stream_read_byte(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint16 DataInputStream::read_int16(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gint16 retvalue = g_data_input_stream_read_int16(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint16 DataInputStream::read_int16()
{
  GError* gerror = nullptr;
  gint16 retvalue = g_data_input_stream_read_int16(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint16 DataInputStream::read_uint16(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  guint16 retvalue = g_data_input_stream_read_uint16(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint16 DataInputStream::read_uint16()
{
  GError* gerror = nullptr;
  guint16 retvalue = g_data_input_stream_read_uint16(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint32 DataInputStream::read_int32(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gint32 retvalue = g_data_input_stream_read_int32(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint32 DataInputStream::read_int32()
{
  GError* gerror = nullptr;
  gint32 retvalue = g_data_input_stream_read_int32(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint32 DataInputStream::read_uint32(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  guint32 retvalue = g_data_input_stream_read_uint32(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint32 DataInputStream::read_uint32()
{
  GError* gerror = nullptr;
  guint32 retvalue = g_data_input_stream_read_uint32(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint64 DataInputStream::read_int64(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gint64 retvalue = g_data_input_stream_read_int64(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gint64 DataInputStream::read_int64()
{
  GError* gerror = nullptr;
  gint64 retvalue = g_data_input_stream_read_int64(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint64 DataInputStream::read_uint64(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  guint64 retvalue = g_data_input_stream_read_uint64(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

guint64 DataInputStream::read_uint64()
{
  GError* gerror = nullptr;
  guint64 retvalue = g_data_input_stream_read_uint64(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void DataInputStream::read_line_utf8(std::string& line, const Glib::RefPtr<Cancellable>& cancellable, gsize& length)
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), &(length), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void DataInputStream::read_line_utf8(std::string& line, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), nullptr, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void DataInputStream::read_line_utf8(std::string& line, gsize& length)
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), &(length), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void DataInputStream::read_line_utf8(std::string& line)
{
  GError* gerror = nullptr;
  line = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_utf8(gobj(), nullptr, nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void DataInputStream::read_line_finish_utf8(const Glib::RefPtr<AsyncResult>& result, std::string& data, gsize& length)
{
  GError* gerror = nullptr;
  data = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_finish_utf8(gobj(), Glib::unwrap(result), &(length), &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}

void DataInputStream::read_line_finish_utf8(const Glib::RefPtr<AsyncResult>& result, std::string& data)
{
  GError* gerror = nullptr;
  data = Glib::convert_return_gchar_ptr_to_stdstring(g_data_input_stream_read_line_finish_utf8(gobj(), Glib::unwrap(result), nullptr, &(gerror)));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
}


Glib::PropertyProxy< DataStreamByteOrder > DataInputStream::property_byte_order() 
{
  return Glib::PropertyProxy< DataStreamByteOrder >(this, "byte-order");
}

Glib::PropertyProxy_ReadOnly< DataStreamByteOrder > DataInputStream::property_byte_order() const
{
  return Glib::PropertyProxy_ReadOnly< DataStreamByteOrder >(this, "byte-order");
}

Glib::PropertyProxy< DataStreamNewlineType > DataInputStream::property_newline_type() 
{
  return Glib::PropertyProxy< DataStreamNewlineType >(this, "newline-type");
}

Glib::PropertyProxy_ReadOnly< DataStreamNewlineType > DataInputStream::property_newline_type() const
{
  return Glib::PropertyProxy_ReadOnly< DataStreamNewlineType >(this, "newline-type");
}


} // namespace Gio


