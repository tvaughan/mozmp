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

  /* void setFile (in string file); */
  NS_IMETHOD SetFile(const char *file) = 0;

  /* void getFile (out string file); */
  NS_IMETHOD GetFile(char **file) = 0;

  /* void mTime (inout string b, in unsigned long bsize); */
  NS_IMETHOD MTime(char **b, PRUint32 bsize) = 0;

};

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTAT \
  NS_IMETHOD SetFile(const char *file); \
  NS_IMETHOD GetFile(char **file); \
  NS_IMETHOD MTime(char **b, PRUint32 bsize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTAT(_to) \
  NS_IMETHOD SetFile(const char *file) { return _to ## SetFile(file); } \
  NS_IMETHOD GetFile(char **file) { return _to ## GetFile(file); } \
  NS_IMETHOD MTime(char **b, PRUint32 bsize) { return _to ## MTime(b, bsize); } 

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

/* void setFile (in string file); */
NS_IMETHODIMP nsStat::SetFile(const char *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getFile (out string file); */
NS_IMETHODIMP nsStat::GetFile(char **file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mTime (inout string b, in unsigned long bsize); */
NS_IMETHODIMP nsStat::MTime(char **b, PRUint32 bsize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStat_h__ */
