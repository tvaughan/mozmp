/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM nsIStat.idl
 */

#ifndef __gen_nsIStat_h__
#define __gen_nsIStat_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStat */
#define NS_ISTAT_IID_STR "6df20f63-68a0-4c51-a847-a3ba00b6e6b6"

#define NS_ISTAT_IID \
  {0x6df20f63, 0x68a0, 0x4c51, \
    { 0xa8, 0x47, 0xa3, 0xba, 0x00, 0xb6, 0xe6, 0xb6 }}

class NS_NO_VTABLE nsIStat : public nsISupports {
 public: 

  NS_DEFINE_STATIC_IID_ACCESSOR(NS_ISTAT_IID)

  /* attribute string file; */
  NS_IMETHOD GetFile(char * *aFile) = 0;
  NS_IMETHOD SetFile(const char * aFile) = 0;

  /* string mTime (); */
  NS_IMETHOD MTime(char **_retval) = 0;

};

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTAT \
  NS_IMETHOD GetFile(char * *aFile); \
  NS_IMETHOD SetFile(const char * aFile); \
  NS_IMETHOD MTime(char **_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTAT(_to) \
  NS_IMETHOD GetFile(char * *aFile) { return _to ## GetFile(aFile); } \
  NS_IMETHOD SetFile(const char * aFile) { return _to ## SetFile(aFile); } \
  NS_IMETHOD MTime(char **_retval) { return _to ## MTime(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStat : public nsIStat
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTAT

  nsStat();
  virtual ~nsStat();
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStat, nsIStat)

nsStat::nsStat()
{
  NS_INIT_ISUPPORTS();
  /* member initializers and constructor code */
}

nsStat::~nsStat()
{
  /* destructor code */
}

/* attribute string file; */
NS_IMETHODIMP nsStat::GetFile(char * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStat::SetFile(const char * aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string mTime (); */
NS_IMETHODIMP nsStat::MTime(char **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStat_h__ */
