// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GIOMM_PERMISSION_H
#define _GIOMM_PERMISSION_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The giomm Development Team
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

#include <glibmm/object.h>
#include <giomm/cancellable.h>
#include <giomm/asyncresult.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GPermission = struct _GPermission;
using GPermissionClass = struct _GPermissionClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class Permission_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** An object representing the permission to perform a certain action.
 *
 * A Permission represents the status of the caller's permission to
 * perform a certain action.
 *
 * You can query if the action is currently allowed and if it is
 * possible to acquire the permission so that the action will be allowed
 * in the future.
 *
 * There is also an API to actually acquire the permission and one to
 * release it.
 *
 * As an example, a Permission might represent the ability for the
 * user to write to a Settings object.  This Permission object could
 * then be used to decide if it is appropriate to show a "Click here to
 * unlock" button in a dialog and to provide the mechanism to invoke
 * when that button is clicked.
 *
 * @newin{2,42}
 */

class Permission : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Permission;
  using CppClassType = Permission_Class;
  using BaseObjectType = GPermission;
  using BaseClassType = GPermissionClass;

  // noncopyable
  Permission(const Permission&) = delete;
  Permission& operator=(const Permission&) = delete;

private:  friend class Permission_Class;
  static CppClassType permission_class_;

protected:
  explicit Permission(const Glib::ConstructParams& construct_params);
  explicit Permission(GPermission* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Permission(Permission&& src) noexcept;
  Permission& operator=(Permission&& src) noexcept;

  ~Permission() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GPermission*       gobj()       { return reinterpret_cast<GPermission*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GPermission* gobj() const { return reinterpret_cast<GPermission*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GPermission* gobj_copy();

private:


public:

  
  /** Attempts to acquire the permission represented by @a permission.
   * 
   * The precise method by which this happens depends on the permission
   * and the underlying authentication mechanism.  A simple example is
   * that a dialog may appear asking the user to enter their password.
   * 
   * You should check with g_permission_get_can_acquire() before calling
   * this function.
   * 
   * If the permission is acquired then <tt>true</tt> is returned.  Otherwise,
   * <tt>false</tt> is returned and @a error is set appropriately.
   * 
   * This call is blocking, likely for a very long time (in the case that
   * user interaction is required).  See g_permission_acquire_async() for
   * the non-blocking version.
   * 
   * @newin{2,26}
   * 
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the permission was successfully acquired.
   * 
   * @throws Glib::Error
   */
  bool acquire(const Glib::RefPtr<Cancellable>& cancellable);

  /// A acquire() convenience overload.
  bool acquire();
  
  /** Attempts to acquire the permission represented by @a permission.
   * 
   * This is the first half of the asynchronous version of
   * g_permission_acquire().
   * 
   * @newin{2,26}
   * 
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot The SlotAsyncReady to call when done.
   */
  void acquire_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /// A acquire_async() convenience overload.
  void acquire_async(const SlotAsyncReady& slot);
  
  /** Collects the result of attempting to acquire the permission
   * represented by @a permission.
   * 
   * This is the second half of the asynchronous version of
   * g_permission_acquire().
   * 
   * @newin{2,26}
   * 
   * @param result The AsyncResult given to the SlotAsyncReady.
   * @return <tt>true</tt> if the permission was successfully acquired.
   * 
   * @throws Glib::Error
   */
  bool acquire_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /** Attempts to release the permission represented by @a permission.
   * 
   * The precise method by which this happens depends on the permission
   * and the underlying authentication mechanism.  In most cases the
   * permission will be dropped immediately without further action.
   * 
   * You should check with g_permission_get_can_release() before calling
   * this function.
   * 
   * If the permission is released then <tt>true</tt> is returned.  Otherwise,
   * <tt>false</tt> is returned and @a error is set appropriately.
   * 
   * This call is blocking, likely for a very long time (in the case that
   * user interaction is required).  See g_permission_release_async() for
   * the non-blocking version.
   * 
   * @newin{2,26}
   * 
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if the permission was successfully released.
   * 
   * @throws Glib::Error
   */
  bool release(const Glib::RefPtr<Cancellable>& cancellable);

  /// A release() convenience overload.
  bool release();
  
  /** Attempts to release the permission represented by @a permission.
   * 
   * This is the first half of the asynchronous version of
   * g_permission_release().
   * 
   * @newin{2,26}
   * 
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @param slot The SlotAsyncReady to call when done.
   */
  void release_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /// A release_async() convenience overload.
  void release_async(const SlotAsyncReady& slot);
  
  /** Collects the result of attempting to release the permission
   * represented by @a permission.
   * 
   * This is the second half of the asynchronous version of
   * g_permission_release().
   * 
   * @newin{2,26}
   * 
   * @param result The AsyncResult given to the SlotAsyncReady.
   * @return <tt>true</tt> if the permission was successfully released.
   * 
   * @throws Glib::Error
   */
  bool release_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /** Gets the value of the 'allowed' property.  This property is <tt>true</tt> if
   * the caller currently has permission to perform the action that
   *  @a permission represents the permission to perform.
   * 
   * @newin{2,26}
   * 
   * @return The value of the 'allowed' property.
   */
  bool get_allowed() const;
  
  /** Gets the value of the 'can-acquire' property.  This property is <tt>true</tt>
   * if it is generally possible to acquire the permission by calling
   * g_permission_acquire().
   * 
   * @newin{2,26}
   * 
   * @return The value of the 'can-acquire' property.
   */
  bool get_can_acquire() const;
  
  /** Gets the value of the 'can-release' property.  This property is <tt>true</tt>
   * if it is generally possible to release the permission by calling
   * g_permission_release().
   * 
   * @newin{2,26}
   * 
   * @return The value of the 'can-release' property.
   */
  bool get_can_release() const;

  /** <tt>true</tt> if the caller currently has permission to perform the action that
   *  @a permission represents the permission to perform.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_allowed() const;


  /** <tt>true</tt> if it is generally possible to acquire the permission by calling
   * g_permission_acquire().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_can_acquire() const;


  /** <tt>true</tt> if it is generally possible to release the permission by calling
   * g_permission_release().
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_can_release() const;


protected:

  Permission();

// A copy is needed for vfuncs, i.e. Glib::wrap($3, true)
 

  /// @throws Glib::Error.
  virtual bool acquire_vfunc(const Glib::RefPtr<Cancellable>& cancellable);

    virtual void acquire_async_vfunc(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /// @throws Glib::Error.
  virtual bool acquire_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


  /// @throws Glib::Error.
  virtual bool release_vfunc(const Glib::RefPtr<Cancellable>& cancellable);

    virtual void release_async_vfunc(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);

  /// @throws Glib::Error.
  virtual bool release_finish_vfunc(const Glib::RefPtr<AsyncResult>& result);


  // You should never call this function except from a Gio::Permission implementation.
  
  /** This function is called by the Permission implementation to update
   * the properties of the permission.  You should never call this
   * function except from a Permission implementation.
   * 
   * GObject notify signals are generated, as appropriate.
   * 
   * @newin{2,26}
   * 
   * @param allowed The new value for the 'allowed' property.
   * @param can_acquire The new value for the 'can-acquire' property.
   * @param can_release The new value for the 'can-release' property.
   */
  void impl_update(bool allowed, bool can_acquire, bool can_release);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::Permission
   */
  Glib::RefPtr<Gio::Permission> wrap(GPermission* object, bool take_copy = false);
}


#endif /* _GIOMM_PERMISSION_H */

