//使用 Windows 映像组件（WCI）将图标（HICON）转换为具有透明度的PARGB32位图，并添加到菜单项中
//https://docs.microsoft.com/en-us/previous-versions/bb757020(v=msdn.10)

#pragma once
class CWCIFactory
{
public:
    ~CWCIFactory();
    static IWICImagingFactory* GetWCI() { return m_instance.m_pWICFactory; }

private:
    HRESULT _hrOleInit{};
    IWICImagingFactory *m_pWICFactory{};

    static CWCIFactory m_instance;      //CWCIFactory类唯一的对象

private:
    CWCIFactory();
};

class CMenuIcon
{
public:
    CMenuIcon();
    ~CMenuIcon();

    //向一个菜单项添加图标
    static HRESULT AddIconToMenuItem(HMENU hmenu, int iMenuItem, BOOL fByPosition, HICON hicon);

private:
    static HRESULT AddBitmapToMenuItem(HMENU hmenu, int iItem, BOOL fByPosition, HBITMAP hbmp);
    static void InitBitmapInfo(__out_bcount(cbInfo) BITMAPINFO *pbmi, ULONG cbInfo, LONG cx, LONG cy, WORD bpp);
    static HRESULT Create32BitHBITMAP(HDC hdc, const SIZE *psize, __deref_opt_out void **ppvBits, __out HBITMAP* phBmp);
};

