// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GIOMM_LISTMODEL_H
#define _GIOMM_LISTMODEL_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2016 The giomm Development Team
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

#include <glibmm/interface.h>
#include <gio/gio.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GListModelInterface GListModelInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GListModel = struct _GListModel;
using GListModelClass = struct _GListModelClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class ListModel_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** A dynamic list of objects.
 *
 * A ListModel represents a mutable list of
 * Glib::Objects. Its main intention is as a model for various widgets in
 * user interfaces, such as list views, but it can also be used as a
 * convenient method of returning lists of data, with support for
 * updates.
 *
 * Each object in the list may also report changes in itself via some
 * mechanism (normally the Glib::PropertyProxy<>::signal_changed() signal
 * of one or more of the object's properties). Taken together
 * with the signal_items_changed() signal, this provides for a list
 * that can change its membership, and in which the members can change
 * their individual properties.
 *
 * A good example would be the list of visible wireless network access
 * points, where each access point can report dynamic properties such as
 * signal strength.
 *
 * It is important to note that the ListModel itself does not report
 * changes to the individual items.  It only reports changes to the list
 * membership.  If you want to observe changes to the objects themselves
 * then you need to connect signals to the objects that you are
 * interested in.
 *
 * All items in a ListModel are of (or derived from) the same type.
 * get_item_type() returns that type.  The type may be an
 * interface, in which case all objects in the list must implement it.
 *
 * The semantics are close to that of an array:
 * get_n_items() returns the number of items in the list and
 * get_object() returns an item at a (0-based) position. In
 * order to allow implementations to calculate the list length lazily,
 * you can also iterate over items: starting from 0, repeatedly call
 * get_object() until it returns nullptr.
 *
 * This interface is intended only to be used from a single thread.  The
 * thread in which it is appropriate to use it depends on the particular
 * implementation, but typically it will be from the thread that owns
 * the thread-default main context
 * in effect at the time that the model was created.
 *
 * @newin{2,50}
 */

class ListModel : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = ListModel;
  using CppClassType = ListModel_Class;
  using BaseObjectType = GListModel;
  using BaseClassType = GListModelInterface;

  // noncopyable
  ListModel(const ListModel&) = delete;
  ListModel& operator=(const ListModel&) = delete;

private:
  friend class ListModel_Class;
  static CppClassType listmodel_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  ListModel();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit ListModel(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit ListModel(GListModel* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  ListModel(ListModel&& src) noexcept;
  ListModel& operator=(ListModel&& src) noexcept;

  ~ListModel() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GListModel*       gobj()       { return reinterpret_cast<GListModel*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GListModel* gobj() const { return reinterpret_cast<GListModel*>(gobject_); }

private:


protected:
  
  /** Emits the ListModel::signal_items_changed() signal on @a list.
   * 
   * This function should only be called by classes implementing
   * ListModel. It has to be called after the internal representation
   * of @a list has been updated, because handlers connected to this signal
   * might query the new state of the list.
   * 
   * Implementations must only make changes to the model (as visible to
   * its consumer) in places that will not cause problems for that
   * consumer.  For models that are driven directly by a write API (such
   * as ListStore), changes can be reported in response to uses of that
   * API.  For models that represent remote data, changes should only be
   * made from a fresh mainloop dispatch.  It is particularly not
   * permitted to make changes in response to a call to the ListModel
   * consumer API.
   * 
   * Stated another way: in general, it is assumed that code making a
   * series of accesses to the model via the API, without returning to the
   * mainloop, and without calling other code, will continue to view the
   * same contents of the model.
   * 
   * @newin{2,50}
   * 
   * @param position The position at which @a list changed.
   * @param removed The number of items removed.
   * @param added The number of items added.
   */
  void items_changed(guint position, guint removed, guint added);

public:
  
  /** Gets the type of the items in @a list. All items returned from
   * Glib::list_model_get_type() are of that type or a subtype, or are an
   * implementation of that interface.
   * 
   * The item type of a ListModel can not change during the life of the
   * model.
   * 
   * @newin{2,50}
   * 
   * @return The Type of the items contained in @a list.
   */
  GType get_item_type() const;
  
  /** Gets the number of items in @a list.
   * 
   * Depending on the model implementation, calling this function may be
   * less efficient than iterating the list with increasing values for
   *  @a position until g_list_model_get_item() returns <tt>nullptr</tt>.
   * 
   * @newin{2,50}
   * 
   * @return The number of items in @a list.
   */
  guint get_n_items() const;

  //g_list_model_get_item is useless as long as we have g_list_model_get_object().
  //It doesn't do anything differently.
  

  /** Get the item at @a position. If @a position is greater than the number of
   * items in @a list, <tt>nullptr</tt> is returned.
   * 
   * <tt>nullptr</tt> is never returned for an index that is smaller than the length
   * of the list.  See g_list_model_get_n_items().
   * 
   * @newin{2,50}
   * 
   * @param position The position of the item to fetch.
   * @return The object at @a position.
   */
  Glib::RefPtr<Glib::ObjectBase> get_object(guint position);
  
  /** Get the item at @a position. If @a position is greater than the number of
   * items in @a list, <tt>nullptr</tt> is returned.
   * 
   * <tt>nullptr</tt> is never returned for an index that is smaller than the length
   * of the list.  See g_list_model_get_n_items().
   * 
   * @newin{2,50}
   * 
   * @param position The position of the item to fetch.
   * @return The object at @a position.
   */
  Glib::RefPtr<const Glib::ObjectBase> get_object(guint position) const;

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%items_changed(guint position, guint removed, guint added)</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted whenever items were added or removed to
   *  @a list. At @a position, @a removed items were removed and @a added items
   * were added in their place.
   * 
   * @newin{2,50}
   * 
   * @param position The position at which @a list changed.
   * @param removed The number of items removed.
   * @param added The number of items added.
   */

  Glib::SignalProxy< void,guint,guint,guint > signal_items_changed();


    virtual GType get_item_type_vfunc();

    virtual guint get_n_items_vfunc();

    virtual gpointer get_item_vfunc(guint position);


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
   * @relates Gio::ListModel
   */
  Glib::RefPtr<Gio::ListModel> wrap(GListModel* object, bool take_copy = false);

} // namespace Glib


#endif /* _GIOMM_LISTMODEL_H */

