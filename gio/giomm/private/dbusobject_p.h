// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GIOMM_DBUSOBJECT_P_H
#define _GIOMM_DBUSOBJECT_P_H


#include <glibmm/private/interface_p.h>
#include <gio/gio.h>

#include <glibmm/private/interface_p.h>

namespace Gio
{

namespace DBus
{

class Object_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = Object;
  using BaseObjectType = GDBusObject;
  using BaseClassType = GDBusObjectIface;
  using CppClassParent = Glib::Interface_Class;

  friend class Object;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void interface_added_callback(GDBusObject* self, GDBusInterface* p0);
  static void interface_removed_callback(GDBusObject* self, GDBusInterface* p0);

  //Callbacks (virtual functions):
  static const gchar* get_object_path_vfunc_callback(GDBusObject* self);
  static GList* get_interfaces_vfunc_callback(GDBusObject* self);
  static GDBusInterface* get_interface_vfunc_callback(GDBusObject* self, const gchar* interface_name);
};


} // namespace DBus

} // namespace Gio


#endif /* _GIOMM_DBUSOBJECT_P_H */

