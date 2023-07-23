#pragma once

#include "Hyperion/Input.h"

namespace Hyperion
{
	class WindowsInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int Button);

		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl();
		virtual float GetMouseYImpl();
	};
}