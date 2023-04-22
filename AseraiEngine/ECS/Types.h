#pragma once

#include <bitset>

namespace Aserai
{
	const uint32_t MAX_COMPONENTS = 32;

	using Signature = std::bitset<MAX_COMPONENTS>;

	struct BaseComponent
	{
	protected:
		static uint32_t BaseID;
	};

	template<typename T>
	class Component : public BaseComponent
	{
	public:
		static uint32_t GetID()
		{
			static auto id = BaseID++;
			return id;
		}
	};
}