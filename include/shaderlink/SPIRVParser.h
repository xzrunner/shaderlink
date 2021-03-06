#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace shaderlink 
{

class SPIRVParser 
{
public:
	void Parse(const std::vector<unsigned int>& spv);

	enum class ValueType
	{
		Void,
		Bool,
		Int,
		Float,
		Vector,
		Matrix,
		Struct,
		Unknown
	};
	struct Variable 
	{
		std::string Name;
		ValueType Type = ValueType::Unknown, BaseType = ValueType::Unknown;
		int TypeComponentCount = 1;
		std::string TypeName;
	};
	struct Function 
	{
		int LineStart;
		int LineEnd;
		std::vector<Variable> Arguments;
		std::vector<Variable> Locals;

		Variable ReturnType;
	};

	std::unordered_map<std::string, Function> Functions;
	std::unordered_map<std::string, std::vector<Variable>> UserTypes;
	std::vector<Variable> Uniforms;
	std::vector<Variable> Globals;

	bool BarrierUsed;
	int LocalSizeX, LocalSizeY, LocalSizeZ;

	int ArithmeticInstCount;
	int BitInstCount;
	int LogicalInstCount;
	int TextureInstCount;
	int DerivativeInstCount;
	int ControlFlowInstCount;

}; // SPIRVParser

}