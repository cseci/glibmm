// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GIOMM_ACTIONMAP_P_H
#define _GIOMM_ACTIONMAP_P_H


#include <glibmm/private/interface_p.h>
#include <gio/gio.h>

#include <glibmm/private/interface_p.h>

namespace Gio
{

class ActionMap_Class : public Glib::Interface_Class
{
public:
  using CppObjectType = ActionMap;
  using BaseObjectType = GActionMap;
  using BaseClassType = GActionMapInterface;
  using CppClassParent = Glib::Interface_Class;

  friend class ActionMap;

  const Glib::Interface_Class& init();

  static void iface_init_function(void* g_iface, void* iface_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GAction* lookup_action_vfunc_callback(GActionMap* self, const gchar* action_name);
  static void add_action_vfunc_callback(GActionMap* self, GAction* action);
  static void remove_action_vfunc_callback(GActionMap* self, const gchar* action_name);
};


} // namespace Gio


#endif /* _GIOMM_ACTIONMAP_P_H */

