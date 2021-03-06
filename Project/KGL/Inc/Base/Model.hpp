#pragma once

#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX

#include <DirectXMath.h>
#include <filesystem>

namespace KGL
{
	inline namespace BASE
	{
		namespace MODEL
		{
			struct MaterialForHLSL		// HLSL用
			{
				DirectX::XMFLOAT3	deffuse;
				FLOAT				alpha;
				DirectX::XMFLOAT3	specular;
				FLOAT				specularity;
				DirectX::XMFLOAT3	ambient;
			};
			struct AdditionalMaterial	// それ以外
			{
				std::filesystem::path	tex_path;
				UCHAR					toon_idx;
				bool					edge_flg;
			};
			struct Material
			{
				UINT				indices_num;
				MaterialForHLSL		material;
				AdditionalMaterial	additional;
			};
		}
	}
}