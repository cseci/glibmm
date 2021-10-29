// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!


#include <glibmm.h>

#include <glibmm/variantiter.h>
#include <glibmm/private/variantiter_p.h>


/* Copyright(C) 2010 The glibmm Development Team
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

#include <glibmm/variant.h>
#include <glib.h>

namespace Glib
{

VariantIter::VariantIter(const VariantBase& variant)
: gobject_(g_variant_iter_new(const_cast<GVariant*>(variant.gobj())))
{
}

bool
VariantIter::next_value(VariantBase& value)
{
  GVariant* const g_value = g_variant_iter_next_value(gobj());

  if (g_value)
  {
    value.init(g_value); // g_value is already referenced.
    return true;
  }
  else
    return false;
}

} // namespace Glib

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::VariantIter wrap(GVariantIter* object, bool take_copy /* = false */)
{
  return Glib::VariantIter(object, take_copy);
}

} // namespace Glib


namespace Glib
{


VariantIter::VariantIter()
:
  gobject_ (nullptr) // Allows creation of invalid wrapper, e.g. for output arguments to methods.
{}

VariantIter::VariantIter(const VariantIter& src)
:
  gobject_ ((src.gobject_) ? g_variant_iter_copy(src.gobject_) : nullptr)
{}

VariantIter::VariantIter(GVariantIter* castitem, bool make_a_copy /* = false */)
{
  if(!make_a_copy)
  {
    // It was given to us by a function which has already made a copy for us to keep.
    gobject_ = castitem;
  }
  else
  {
    // We are probably getting it via direct access to a struct,
    // so we can not just take it - we have to take a copy of it.
    if(castitem)
      gobject_ = g_variant_iter_copy(castitem);
    else
      gobject_ = nullptr;
  }
}


VariantIter& VariantIter::operator=(const VariantIter& src)
{
  const auto new_gobject = (src.gobject_) ? g_variant_iter_copy(src.gobject_) : nullptr;

  if(gobject_)
    g_variant_iter_free(gobject_);

  gobject_ = new_gobject;

  return *this;
}

VariantIter::VariantIter(VariantIter&& other) noexcept
:
  gobject_(other.gobject_)
{
  other.gobject_ = nullptr;
}

VariantIter& VariantIter::operator=(VariantIter&& other) noexcept
{
  VariantIter temp (other);
  swap(temp);
  return *this;
}

VariantIter::~VariantIter() noexcept
{
  if(gobject_)
    g_variant_iter_free(gobject_);
}

void VariantIter::swap(VariantIter& other) noexcept
{
  std::swap(gobject_, other.gobject_);
}

GVariantIter* VariantIter::gobj_copy() const
{
  return g_variant_iter_copy(gobject_);
}


gsize VariantIter::init(const VariantContainerBase& value)
{
  return g_variant_iter_init(gobj(), const_cast<GVariant*>((value).gobj()));
}

gsize VariantIter::get_n_children() const
{
  return g_variant_iter_n_children(const_cast<GVariantIter*>(gobj()));
}


} // namespace Glib


