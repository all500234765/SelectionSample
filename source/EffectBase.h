#pragma once

#include <UnigineRender.h>

using namespace Unigine;

template<typename T>
class EffectBase
{
public:
	using CALLBACK_INDEX = Render::CALLBACK_INDEX;

	EffectBase(CALLBACK_INDEX cb = Render::CALLBACK_BEGIN_TAA): index(cb)
	{
		auto func = MakeCallback(this, &EffectBase::effect_logic);
		callback = Render::addCallback(index, func);
	}

	~EffectBase()
	{
		Render::removeCallback(index, callback);
		callback = nullptr;
	}

protected:
	virtual void effect_logic() = 0;

private:
	CALLBACK_INDEX index;
	void *callback;
};
