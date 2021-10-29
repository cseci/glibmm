// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/proxyaddress.h>
#include <giomm/private/proxyaddress_p.h>


/* Copyright (C) 2010 glibmm Development Team
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


namespace Glib
{

Glib::RefPtr<Gio::ProxyAddress> wrap(GProxyAddress* object, bool take_copy)
{
  return Glib::RefPtr<Gio::ProxyAddress>( dynamic_cast<Gio::ProxyAddress*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& ProxyAddress_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &ProxyAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_proxy_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void ProxyAddress_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* ProxyAddress_Class::wrap_new(GObject* object)
{
  return new ProxyAddress((GProxyAddress*)object);
}


/* The implementation: */

GProxyAddress* ProxyAddress::gobj_copy()
{
  reference();
  return gobj();
}

ProxyAddress::ProxyAddress(const Glib::ConstructParams& construct_params)
:
  InetSocketAddress(construct_params)
{

}

ProxyAddress::ProxyAddress(GProxyAddress* castitem)
:
  InetSocketAddress((GInetSocketAddress*)(castitem))
{}


ProxyAddress::ProxyAddress(ProxyAddress&& src) noexcept
: InetSocketAddress(std::move(src))
{}

ProxyAddress& ProxyAddress::operator=(ProxyAddress&& src) noexcept
{
  InetSocketAddress::operator=(std::move(src));
  return *this;
}


ProxyAddress::~ProxyAddress() noexcept
{}


ProxyAddress::CppClassType ProxyAddress::proxyaddress_class_; // initialize static member

GType ProxyAddress::get_type()
{
  return proxyaddress_class_.init().get_type();
}


GType ProxyAddress::get_base_type()
{
  return g_proxy_address_get_type();
}


ProxyAddress::ProxyAddress(const Glib::RefPtr<InetAddress>& address, guint16 port, const Glib::ustring& protocol, const Glib::ustring& destination_hostname, guint16 destination_port, const Glib::ustring& username, const Glib::ustring& password)
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  InetSocketAddress(Glib::ConstructParams(proxyaddress_class_.init(), "address", const_cast<GInetAddress*>(Glib::unwrap(address)), "port", port, "protocol", protocol.c_str(), "destination_hostname", destination_hostname.c_str(), "destination_port", destination_port, "username", username.c_str(), "password", password.c_str(), nullptr))
{
  

}

Glib::RefPtr<ProxyAddress> ProxyAddress::create(const Glib::RefPtr<InetAddress>& address, guint16 port, const Glib::ustring& protocol, const Glib::ustring& destination_hostname, guint16 destination_port, const Glib::ustring& username, const Glib::ustring& password)
{
  return Glib::RefPtr<ProxyAddress>( new ProxyAddress(address, port, protocol, destination_hostname, destination_port, username, password) );
}

Glib::ustring ProxyAddress::get_protocol() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_proxy_address_get_protocol(const_cast<GProxyAddress*>(gobj())));
}

Glib::ustring ProxyAddress::get_destination_protocol() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_proxy_address_get_destination_protocol(const_cast<GProxyAddress*>(gobj())));
}

Glib::ustring ProxyAddress::get_destination_hostname() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_proxy_address_get_destination_hostname(const_cast<GProxyAddress*>(gobj())));
}

guint16 ProxyAddress::get_destination_port() const
{
  return g_proxy_address_get_destination_port(const_cast<GProxyAddress*>(gobj()));
}

Glib::ustring ProxyAddress::get_username() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_proxy_address_get_username(const_cast<GProxyAddress*>(gobj())));
}

Glib::ustring ProxyAddress::get_password() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_proxy_address_get_password(const_cast<GProxyAddress*>(gobj())));
}

Glib::ustring ProxyAddress::get_uri() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_proxy_address_get_uri(const_cast<GProxyAddress*>(gobj())));
}


Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_protocol() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "protocol");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_destination_protocol() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "destination-protocol");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_destination_hostname() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "destination-hostname");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_destination_port() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "destination-port");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_username() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "username");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_password() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "password");
}

Glib::PropertyProxy_ReadOnly< Glib::ustring > ProxyAddress::property_uri() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::ustring >(this, "uri");
}


} // namespace Gio


