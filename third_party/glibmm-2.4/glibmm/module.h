// -*- c++ -*-
// Generated by gmmproc 2.39.93 -- DO NOT MODIFY!
#ifndef _GLIBMM_MODULE_H
#define _GLIBMM_MODULE_H


/* Copyright (C) 2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <string>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GModule GModule; }
#endif

namespace Glib
{

/** @addtogroup glibmmEnums glibmm Enums and Flags */

/** 
 *  @var ModuleFlags MODULE_BIND_LAZY
 *  specifies that symbols are only resolved whenneeded. The default action is to bind all symbols when the moduleis loaded.
 * 
 *  @var ModuleFlags MODULE_BIND_LOCAL
 *  specifies that symbols in the module shouldnot be added to the global name space. The default action on mostplatforms is to place symbols in the module in the global name space,which may cause conflicts with existing symbols.
 * 
 *  @var ModuleFlags MODULE_BIND_MASK
 *  mask for all flags.
 * 
 *  @enum ModuleFlags
 * 
 * Flags passed to g_module_open().
 * Note that these flags are not supported on all platforms.
 * @ingroup glibmmEnums
 * @par Bitwise operators:
 * <tt>%ModuleFlags operator|(ModuleFlags, ModuleFlags)</tt><br>
 * <tt>%ModuleFlags operator&(ModuleFlags, ModuleFlags)</tt><br>
 * <tt>%ModuleFlags operator^(ModuleFlags, ModuleFlags)</tt><br>
 * <tt>%ModuleFlags operator~(ModuleFlags)</tt><br>
 * <tt>%ModuleFlags& operator|=(ModuleFlags&, ModuleFlags)</tt><br>
 * <tt>%ModuleFlags& operator&=(ModuleFlags&, ModuleFlags)</tt><br>
 * <tt>%ModuleFlags& operator^=(ModuleFlags&, ModuleFlags)</tt><br>
 */
enum ModuleFlags
{
  MODULE_BIND_LAZY = 1 << 0,
  MODULE_BIND_LOCAL = 1 << 1,
  MODULE_BIND_MASK = 0x03
};

/** @ingroup glibmmEnums */
inline ModuleFlags operator|(ModuleFlags lhs, ModuleFlags rhs)
  { return static_cast<ModuleFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline ModuleFlags operator&(ModuleFlags lhs, ModuleFlags rhs)
  { return static_cast<ModuleFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline ModuleFlags operator^(ModuleFlags lhs, ModuleFlags rhs)
  { return static_cast<ModuleFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup glibmmEnums */
inline ModuleFlags operator~(ModuleFlags flags)
  { return static_cast<ModuleFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup glibmmEnums */
inline ModuleFlags& operator|=(ModuleFlags& lhs, ModuleFlags rhs)
  { return (lhs = static_cast<ModuleFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline ModuleFlags& operator&=(ModuleFlags& lhs, ModuleFlags rhs)
  { return (lhs = static_cast<ModuleFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup glibmmEnums */
inline ModuleFlags& operator^=(ModuleFlags& lhs, ModuleFlags rhs)
  { return (lhs = static_cast<ModuleFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


//TODO: Replace get_last_error() with exceptions?
//Provide operator()?

/** Dynamic Loading of Modules
 * These functions provide a portable way to dynamically load object
 *  files (commonly known as 'plug-ins'). The current implementation
 * supports all systems that provide an implementation of dlopen()
 * (e.g. Linux/Sun), as well as HP-UX via its shl_load() mechanism,
 * and Windows platforms via DLLs.
 */
class Module
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Module CppObjectType;
  typedef GModule BaseObjectType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

private:

  
public:

  /** Opens a module.
   *
   * First of all it tries to open file_name as a module. If that
   * fails and file_name has the ".la"-suffix (and is a libtool
   * archive) it tries to open the corresponding module. If that fails
   * and it doesn't have the proper module suffix for the platform
   * (G_MODULE_SUFFIX), this suffix will be appended and the
   * corresponding module will be opended. If that fails and file_name
   * doesn't have the ".la"-suffix, this suffix is appended and
   * it tries to open the corresponding module.
   *
   * Use operator bool() to see whether the operation succeeded. For instance,
   * @code
   * Glib::Module module("plugins/helloworld");
   * if(module)
   * {
   *   void* func = 0;
   *   bool found = get_symbol("some_function", func);
   * }
   * @endcode
   *
   * @param file_name The library filename to open
   * @param flags Flags to configure the load process
   */
  explicit Module(const std::string& file_name, ModuleFlags flags = ModuleFlags(0));

  /** Close a module. The module will be removed from memory, unless
   * <tt>make_resident</tt> has been called.
   */
  virtual ~Module();

  /** Check whether the module was found.
   */
  operator bool() const;

  
  /** Checks if modules are supported on the current platform.
   * @returns true if available, false otherwise
   */
  static bool get_supported();

  
  /** Ensures that a module will never be unloaded. Any calls to the
   * Glib::Module destructor will not unload the module.
   */
  void make_resident();

  
  /** Gets a string describing the last module error.
   * @returns The error string
   */
  static std::string get_last_error();

  
  /** Gets a symbol pointer from the module.
   * @param symbol_name The name of the symbol to lookup
   * @param symbol A pointer to set to the symbol
   * @returns True if the symbol was found, false otherwise.
   */
  bool get_symbol(const std::string& symbol_name, void*& symbol) const;

  
  /** Get the name of the module.
   * @returns The name of the module
   */
  std::string get_name() const;
  

  /** A portable way to build the filename of a module. The
   * platform-specific prefix and suffix are added to the filename, if
   * needed, and the result is added to the directory, using the
   * correct separator character.
   *
   * The directory should specify the directory where the module can
   * be found. It can be an empty string to indicate that the
   * module is in a standard platform-specific directory, though this
   * is not recommended since the wrong module may be found.
   *
   * For example, calling <tt>build_path()</tt> on a Linux
   * system with a directory of <tt>/lib</tt> and a module_name of
   * "mylibrary" will return <tt>/lib/libmylibrary.so</tt>. On a
   * Windows system, using <tt>\\Windows</tt> as the directory it will
   * return <tt>\\Windows\\mylibrary.dll</tt>.
   *
   * @param directory The directory the module is in
   * @param module_name The name of the module
   * @returns The system-specific filename of the module
   */
  // TODO: add an override which doesn't take a directory
  // TODO: check what happens when directory is ""
  
  /** A portable way to build the filename of a module. The platform-specific
   * prefix and suffix are added to the filename, if needed, and the result
   * is added to the directory, using the correct separator character.
   * 
   * The directory should specify the directory where the module can be found.
   * It can be <tt>0</tt> or an empty string to indicate that the module is in a
   * standard platform-specific directory, though this is not recommended
   * since the wrong module may be found.
   * 
   * For example, calling g_module_build_path() on a Linux system with a
   *  @a directory of `/lib` and a @a module_name of "mylibrary" will return
   * `/lib/libmylibrary.so`. On a Windows system, using `\\Windows` as the
   * directory it will return `\\Windows\\mylibrary.dll`.
   * @param directory The directory where the module is. This can be
   * <tt>0</tt> or the empty string to indicate that the standard platform-specific
   * directories will be used, though that is not recommended.
   * @param module_name The name of the module.
   * @return The complete path of the module, including the standard library
   * prefix and suffix. This should be freed when no longer needed.
   */
  static std::string build_path(const std::string& directory, const std::string& module_name);

  GModule*       gobj()       { return gobject_; }
  const GModule* gobj() const { return gobject_; }

protected:
  GModule* gobject_;

private:
  // noncopyable
  Module(const Module&);
  Module& operator=(const Module&);


};

} // namespace Glib


#endif /* _GLIBMM_MODULE_H */

