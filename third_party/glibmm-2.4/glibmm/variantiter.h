// -*- c++ -*-
// Generated by gmmproc 2.39.93 -- DO NOT MODIFY!
#ifndef _GLIBMM_VARIANTITER_H
#define _GLIBMM_VARIANTITER_H


/* Copyright(C) 2010 The glibmm Development Team
 *
 * This library is free software, ) you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, ) either
 * version 2.1 of the License, or(at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, ) without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library, ) if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glib.h>


namespace Glib
{

class VariantBase;
class VariantContainerBase;

//This can't be like a real iterator (like Gtk::TextIter),
//because g_iter_value_get_next_value() both gets a value and changes the iterator.
//GtkTextIter allows us to go forward and then separately get the current value.
/** VariantIter - An opaque data structure used to iterate through
 * VariantBase containers such as arrays.
 * @newin{2,28}
 */
class VariantIter
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef VariantIter CppObjectType;
  typedef GVariantIter BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Constructs an invalid object.
   * E.g. for output arguments to methods. There is not much you can do with
   * the object before it has been assigned a valid value.
   */
  VariantIter();

  // Use make_a_copy=true when getting it directly from a struct.
  explicit VariantIter(GVariantIter* castitem, bool make_a_copy = false);

  VariantIter(const VariantIter& src);
  VariantIter& operator=(const VariantIter& src);

  ~VariantIter();

  GVariantIter*       gobj()       { return gobject_; }
  const GVariantIter* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  GVariantIter* gobj_copy() const;

protected:
  GVariantIter* gobject_;

private:

  
public:
  //TODO: The variant parameter should be a VariantContainerBase.
  explicit VariantIter(const VariantBase& variant);

  
  /** Initialises (without allocating) a VariantIter.  @a iter may be
   * completely uninitialised prior to this call; its old value is
   * ignored.
   * 
   * The iterator remains valid for as long as @a value exists, and need not
   * be freed in any way.
   * 
   * @newin{2,24}
   * @param value A container Variant.
   * @return The number of items in @a value.
   */
  gsize init(const VariantContainerBase& value);

      
  /** Queries the number of child items in the container that we are
   * iterating over.  This is the total number of items -- not the number
   * of items remaining.
   * 
   * This function might be useful for preallocation of arrays.
   * 
   * @newin{2,24}
   * @return The number of children in the container.
   */
  gsize get_n_children() const;

  bool next_value(VariantBase& value);
  

  // Ignore varargs functions
  

};

} // namespace Glib


namespace Glib
{

  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Glib::VariantIter
   */
Glib::VariantIter wrap(GVariantIter* object, bool take_copy = false);

} // namespace Glib


#endif /* _GLIBMM_VARIANTITER_H */

