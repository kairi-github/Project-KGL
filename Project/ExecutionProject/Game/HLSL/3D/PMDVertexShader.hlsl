#include "PMDShaderHeader.hlsli"

struct VSInput
{
	float4 pos : POSITION;
	float4 normal : NORMAL;
	float2 uv : TEXCOORD;
	min16uint2 boneno : BONE_NO;
	min16uint weight : WEIGHT;
};

Output VSMain(VSInput input, uint inst_no : SV_InstanceID)
{
	Output output = (Output)0;

	float w = input.weight / 100.0f;
	row_major matrix bm = bones[input.boneno[0]] * w + bones[input.boneno[1]] * (1 - w);

	float4 bm_pos = mul(input.pos, bm);
	output.svpos = mul(bm_pos, wvp);
	output.pos = mul(bm_pos, world);
	output.tpos = mul(output.pos, light_camera);

	input.normal.w = 0;	// 平行移動成分を無効化

	output.normal = mul(input.normal, world);
	output.vnormal = mul(output.normal, view);
	output.uv = input.uv;
	output.ray = normalize(input.pos.xyz - eye);
	return output;
}