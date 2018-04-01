// dllmain.h : Declaration of module class.

class CRectifierManagerHandlersModule : public ATL::CAtlDllModuleT<CRectifierManagerHandlersModule>
{
public :
	DECLARE_LIBID(LIBID_RectifierManagerHandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_RECTIFIERMANAGERHANDLERS, "{addb8566-fcc7-4e8e-9e91-98015bf9a00e}")
};

extern class CRectifierManagerHandlersModule _AtlModule;
