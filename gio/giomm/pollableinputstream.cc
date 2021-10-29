// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/pollableinputstream.h>
#include <giomm/private/pollableinputstream_p.h>


/* Copyright (C) 2012 The giomm Development Team
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
#include <giomm/cancellable.h>

namespace Gio
{

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::PollableInputStream> wrap(GPollableInputStream* object, bool take_copy)
{
  return Glib::RefPtr<Gio::PollableInputStream>( dynamic_cast<Gio::PollableInputStream*> (Glib::wrap_auto_interface<Gio::PollableInputStream> ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} // namespace Glib


namespace Gio
{


/* The *_Class implementation: */

const Glib::Interface_Class& PollableInputStream_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Interface_Class has to know the interface init function
    // in order to add interfaces to implementing types.
    class_init_func_ = &PollableInputStream_Class::iface_init_function;

    // We can not derive from another interface, and it is not necessary anyway.
    gtype_ = g_pollable_input_stream_get_type();
  }

  return *this;
}

void PollableInputStream_Class::iface_init_function(void* g_iface, void*)
{
  const auto klass = static_cast<BaseClassType*>(g_iface);

  //This is just to avoid an "unused variable" warning when there are no vfuncs or signal handlers to connect.
  //This is a temporary fix until I find out why I can not seem to derive a GtkFileChooser interface. murrayc
  g_assert(klass != nullptr);

  klass->can_poll = &can_poll_vfunc_callback;
  klass->is_readable = &is_readable_vfunc_callback;
  klass->read_nonblocking = &read_nonblocking_vfunc_callback;

}

gboolean PollableInputStream_Class::can_poll_vfunc_callback(GPollableInputStream* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return static_cast<int>(obj->can_poll_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->can_poll)
    return (*base->can_poll)(self);

  using RType = gboolean;
  return RType();
}
gboolean PollableInputStream_Class::is_readable_vfunc_callback(GPollableInputStream* self)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return static_cast<int>(obj->is_readable_vfunc());
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->is_readable)
    return (*base->is_readable)(self);

  using RType = gboolean;
  return RType();
}
gssize PollableInputStream_Class::read_nonblocking_vfunc_callback(GPollableInputStream* self, void* buffer, gsize count, GError** error)
{
  const auto obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    const auto obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
        // Call the virtual member method, which derived classes might override.
        return obj->read_nonblocking_vfunc(buffer, count);
      }
      catch(Glib::Error& errormm)
      {
        errormm.propagate(error);
        return -1;
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(self), CppObjectType::get_type()) // Get the interface.
)  );

  // Call the original underlying C function:
  if(base && base->read_nonblocking)
    return (*base->read_nonblocking)(self, buffer, count, error);

  using RType = gssize;
  return RType();
}


Glib::ObjectBase* PollableInputStream_Class::wrap_new(GObject* object)
{
  return new PollableInputStream((GPollableInputStream*)(object));
}


/* The implementation: */

PollableInputStream::PollableInputStream()
:
  Glib::Interface(pollableinputstream_class_.init())
{}

PollableInputStream::PollableInputStream(GPollableInputStream* castitem)
:
  Glib::Interface((GObject*)(castitem))
{}

PollableInputStream::PollableInputStream(const Glib::Interface_Class& interface_class)
: Glib::Interface(interface_class)
{
}

PollableInputStream::PollableInputStream(PollableInputStream&& src) noexcept
: Glib::Interface(std::move(src))
{}

PollableInputStream& PollableInputStream::operator=(PollableInputStream&& src) noexcept
{
  Glib::Interface::operator=(std::move(src));
  return *this;
}

PollableInputStream::~PollableInputStream() noexcept
{}

// static
void PollableInputStream::add_interface(GType gtype_implementer)
{
  pollableinputstream_class_.init().add_interface(gtype_implementer);
}

PollableInputStream::CppClassType PollableInputStream::pollableinputstream_class_; // initialize static member

GType PollableInputStream::get_type()
{
  return pollableinputstream_class_.init().get_type();
}


GType PollableInputStream::get_base_type()
{
  return g_pollable_input_stream_get_type();
}


bool PollableInputStream::can_poll() const
{
  return g_pollable_input_stream_can_poll(const_cast<GPollableInputStream*>(gobj()));
}

bool PollableInputStream::is_readable() const
{
  return g_pollable_input_stream_is_readable(const_cast<GPollableInputStream*>(gobj()));
}

gssize PollableInputStream::read_nonblocking(void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gssize retvalue = g_pollable_input_stream_read_nonblocking(gobj(), buffer, count, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize PollableInputStream::read_nonblocking(void* buffer, gsize count)
{
  GError* gerror = nullptr;
  gssize retvalue = g_pollable_input_stream_read_nonblocking(gobj(), buffer, count, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}


bool Gio::PollableInputStream::can_poll_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->can_poll)
  {
    bool retval((*base->can_poll)(const_cast<GPollableInputStream*>(gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
bool Gio::PollableInputStream::is_readable_vfunc() const
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->is_readable)
  {
    bool retval((*base->is_readable)(const_cast<GPollableInputStream*>(gobj())));
    return retval;
  }

  using RType = bool;
  return RType();
}
gssize Gio::PollableInputStream::read_nonblocking_vfunc(void* buffer, gsize count) 
{
  const auto base = static_cast<BaseClassType*>(
      g_type_interface_peek_parent( // Get the parent interface of the interface (The original underlying C interface).
g_type_interface_peek(G_OBJECT_GET_CLASS(gobject_), CppObjectType::get_type()) // Get the interface.
)  );

  if(base && base->read_nonblocking)
  {
    GError* gerror = nullptr;
    gssize retval((*base->read_nonblocking)(gobj(),buffer,count,&(gerror)));
    if(gerror)
      ::Glib::Error::throw_exception(gerror);
    return retval;
  }

  using RType = gssize;
  return RType();
}


} // namespace Gio


