

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sun Oct 20 19:18:13 2013
 */
/* Compiler settings for test2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __test2_h_h__
#define __test2_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Itest2_FWD_DEFINED__
#define __Itest2_FWD_DEFINED__
typedef interface Itest2 Itest2;
#endif 	/* __Itest2_FWD_DEFINED__ */


#ifndef __test2_FWD_DEFINED__
#define __test2_FWD_DEFINED__

#ifdef __cplusplus
typedef class test2 test2;
#else
typedef struct test2 test2;
#endif /* __cplusplus */

#endif 	/* __test2_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __test2_LIBRARY_DEFINED__
#define __test2_LIBRARY_DEFINED__

/* library test2 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_test2;

#ifndef __Itest2_DISPINTERFACE_DEFINED__
#define __Itest2_DISPINTERFACE_DEFINED__

/* dispinterface Itest2 */
/* [uuid] */ 


EXTERN_C const IID DIID_Itest2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("52686648-AF15-42D2-A952-A278DB717F8A")
    Itest2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct Itest2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Itest2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Itest2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Itest2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Itest2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Itest2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Itest2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Itest2 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } Itest2Vtbl;

    interface Itest2
    {
        CONST_VTBL struct Itest2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Itest2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define Itest2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define Itest2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define Itest2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define Itest2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define Itest2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define Itest2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __Itest2_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_test2;

#ifdef __cplusplus

class DECLSPEC_UUID("F05B6413-7720-475A-A9C2-6BFBAEFFE7F2")
test2;
#endif
#endif /* __test2_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


