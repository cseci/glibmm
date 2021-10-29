// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/networkaddress.h>
#include <giomm/private/networkaddress_p.h>


/* Copyright (C) 2007 The giomm Development Team
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
#include <giomm/asyncresult.h>
#include "slot_async.h"

namespace Gio
{

Glib::RefPtr<NetworkAddress>
NetworkAddress::parse(const std::string& host_and_port, guint16 default_port)
{
  GError* error = nullptr;
  auto* address =
    G_NETWORK_ADDRESS(g_network_address_parse(host_and_port.c_str(), default_port, &error));
  if (error)
    Glib::Error::throw_exception(error);

  return Glib::wrap(address);
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::NetworkAddress> wrap(GNetworkAddress* object, bool take_copy)
{
  return Glib::RefPtr<Gio::NetworkAddress>( dynamic_cast<Gio::NetworkAddress*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& NetworkAddress_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &NetworkAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_network_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  SocketConnectable::add_interface(get_type());

  }

  return *this;
}


void NetworkAddress_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* NetworkAddress_Class::wrap_new(GObject* object)
{
  return new NetworkAddress((GNetworkAddress*)object);
}


/* The implementation: */

GNetworkAddress* NetworkAddress::gobj_copy()
{
  reference();
  return gobj();
}

NetworkAddress::NetworkAddress(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

NetworkAddress::NetworkAddress(GNetworkAddress* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


NetworkAddress::NetworkAddress(NetworkAddress&& src) noexcept
: Glib::Object(std::move(src))
  , SocketConnectable(std::move(src))
{}

NetworkAddress& NetworkAddress::operator=(NetworkAddress&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  SocketConnectable::operator=(std::move(src));
  return *this;
}


NetworkAddress::~NetworkAddress() noexcept
{}


NetworkAddress::CppClassType NetworkAddress::networkaddress_class_; // initialize static member

GType NetworkAddress::get_type()
{
  return networkaddress_class_.init().get_type();
}


GType NetworkAddress::get_base_type()
{
  return g_network_address_get_type();
}


NetworkAddress::NetworkAddress(const std::string& hostname, guint16 port)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(networkaddress_class_.init(), "hostname", hostname.c_str(), "port", port, nullptr))
{
  

}

Glib::RefPtr<NetworkAddress> NetworkAddress::create(const std::string& hostname, guint16 port)
{
  return Glib::RefPtr<NetworkAddress>( new NetworkAddress(hostname, port) );
}

std::string NetworkAddress::get_hostname() const
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_network_address_get_hostname(const_cast<GNetworkAddress*>(gobj())));
}

guint16 NetworkAddress::get_port() const
{
  return g_network_address_get_port(const_cast<GNetworkAddress*>(gobj()));
}

std::string NetworkAddress::get_scheme() const
{
  return Glib::convert_const_gchar_ptr_to_stdstring(g_network_address_get_scheme(const_cast<GNetworkAddress*>(gobj())));
}


Glib::PropertyProxy_ReadOnly< std::string > NetworkAddress::property_hostname() const
{
  return Glib::PropertyProxy_ReadOnly< std::string >(this, "hostname");
}

Glib::PropertyProxy_ReadOnly< guint > NetworkAddress::property_port() const
{
  return Glib::PropertyProxy_ReadOnly< guint >(this, "port");
}

Glib::PropertyProxy_ReadOnly< std::string > NetworkAddress::property_scheme() const
{
  return Glib::PropertyProxy_ReadOnly< std::string >(this, "scheme");
}


} // namespace Gio


