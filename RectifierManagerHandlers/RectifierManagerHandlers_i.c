

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 10:14:07 2038
 */
/* Compiler settings for RectifierManagerHandlers.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IPreview,0xa84626a2,0xc0a2,0x41fa,0xa6,0xc6,0x52,0x3b,0x79,0x3c,0x0c,0x29);


MIDL_DEFINE_GUID(IID, IID_IThumbnail,0xe90134f9,0x5c2b,0x4099,0xa1,0xad,0x57,0x13,0xc7,0x1f,0x80,0x3a);


MIDL_DEFINE_GUID(IID, IID_ISearch,0xcab361fa,0x14d9,0x459f,0xad,0x2c,0x72,0x1e,0xa4,0xca,0x81,0x6a);


MIDL_DEFINE_GUID(IID, LIBID_RectifierManagerHandlersLib,0x7481a037,0x3454,0x45bc,0x89,0x82,0xf5,0xe8,0x8d,0x49,0xd9,0x90);


MIDL_DEFINE_GUID(CLSID, CLSID_Preview,0x8e092e57,0xda12,0x4d29,0x9c,0x4d,0x23,0xd8,0xc9,0x26,0x4e,0x66);


MIDL_DEFINE_GUID(CLSID, CLSID_Thumbnail,0x5fdbe258,0x4624,0x41fd,0xba,0x8d,0xfb,0xe0,0x11,0xbc,0x54,0xdd);


MIDL_DEFINE_GUID(CLSID, CLSID_Search,0xbf048be9,0x8007,0x4b45,0x99,0x77,0xc2,0x90,0x46,0x52,0x98,0xb3);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



