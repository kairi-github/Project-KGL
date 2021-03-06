#include <Base/DXC.hpp>
#include <Helper/ThrowAssert.hpp>

using namespace KGL;

DXC::DXC(const std::filesystem::path& dll_path) noexcept : DLL(dll_path)
{
	HRESULT hr = S_OK;
	hr = Load(FuncNameCI);
	RCHECK_STR(FAILED(hr), "関数 " + FuncNameCI + " の読み込みに失敗", "Load(FuncNameCI)に失敗");
	Load(FuncNameCI2); // 失敗してもOK

	hr = CreateInstance(CLSID_DxcCompiler, m_compiler.GetAddressOf());
	RCHECK(FAILED(hr), "compiler の DxcCreateInstance に失敗");
	hr = CreateInstance(CLSID_DxcLibrary, m_liblary.GetAddressOf());
	RCHECK(FAILED(hr), "liblary の DxcCreateInstance に失敗");
	hr = m_liblary->CreateIncludeHandler(m_dx_include_handler.GetAddressOf());
	RCHECK(FAILED(hr), "dx_include_handler の CreateIncludeHandler に失敗");
}