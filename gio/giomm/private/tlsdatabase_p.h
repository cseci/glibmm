// Generated by gmmproc 2.58.0 -- DO NOT MODIFY!
#ifndef _GIOMM_TLSDATABASE_P_H
#define _GIOMM_TLSDATABASE_P_H


#include <glibmm/private/object_p.h>

#include <glibmm/class.h>

namespace Gio
{

class TlsDatabase_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = TlsDatabase;
  using BaseObjectType = GTlsDatabase;
  using BaseClassType = GTlsDatabaseClass;
  using CppClassParent = Glib::Object_Class;
  using BaseClassParent = GObjectClass;

  friend class TlsDatabase;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();


  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.

  //Callbacks (virtual functions):
  static GTlsCertificateFlags verify_chain_vfunc_callback(GTlsDatabase* self, GTlsCertificate* chain, const gchar* purpose, GSocketConnectable* identity, GTlsInteraction* interaction, GTlsDatabaseVerifyFlags flags, GCancellable* cancellable, GError** error);
  static void verify_chain_async_vfunc_callback(GTlsDatabase* self, GTlsCertificate* chain, const gchar* purpose, GSocketConnectable* identity, GTlsInteraction* interaction, GTlsDatabaseVerifyFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data);
  static GTlsCertificateFlags verify_chain_finish_vfunc_callback(GTlsDatabase* self, GAsyncResult* result, GError** error);
  static gchar* create_certificate_handle_vfunc_callback(GTlsDatabase* self, GTlsCertificate* certificate);
  static GTlsCertificate* lookup_certificate_for_handle_vfunc_callback(GTlsDatabase* self, const gchar* handle, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GError** error);
  static void lookup_certificate_for_handle_async_vfunc_callback(GTlsDatabase* self, const gchar* handle, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data);
  static GTlsCertificate* lookup_certificate_for_handle_finish_vfunc_callback(GTlsDatabase* self, GAsyncResult* result, GError** error);
  static GTlsCertificate* lookup_certificate_issuer_vfunc_callback(GTlsDatabase* self, GTlsCertificate* certificate, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GError** error);
  static void lookup_certificate_issuer_async_vfunc_callback(GTlsDatabase* self, GTlsCertificate* certificate, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data);
  static GTlsCertificate* lookup_certificate_issuer_finish_vfunc_callback(GTlsDatabase* self, GAsyncResult* result, GError** error);
  static GList* lookup_certificates_issued_by_vfunc_callback(GTlsDatabase* self, GByteArray* issuer_raw_dn, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GError** error);
  static void lookup_certificates_issued_by_async_vfunc_callback(GTlsDatabase* self, GByteArray* issuer_raw_dn, GTlsInteraction* interaction, GTlsDatabaseLookupFlags flags, GCancellable* cancellable, GAsyncReadyCallback callback, gpointer user_data);
  static GList* lookup_certificates_issued_by_finish_vfunc_callback(GTlsDatabase* self, GAsyncResult* result, GError** error);
};


} // namespace Gio


#endif /* _GIOMM_TLSDATABASE_P_H */

