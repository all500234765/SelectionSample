#pragma once

#include <UnigineObjects.h>

#include "EffectBase.h"

class SelectionEffect: public EffectBase<SelectionEffect>
{
public:
	void setSelection(ObjectPtr o) { selection = o; }

protected:
	void effect_logic() override;

private:
	ObjectPtr selection;
};
